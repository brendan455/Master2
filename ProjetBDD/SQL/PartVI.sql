/* Partie VI */

/* Question 1 Mise à jour d'un déclencheur pour s'assurer de la supprission de l'ensembles des informations à la suppression d'un ouvrage */

CREATE GLOBAL TEMPORARY TABLE TEMP_NB_EXEMPLAIRE(
	ISBN VARCHAR2(20),
	Nb_Exemplaire NUMBER(3)
) ON COMMIT PRESERVE ROWS;

INSERT INTO TEMP_NB_EXEMPLAIRE (ISBN, Nb_Exemplaire)
SELECT ISBN, COUNT(*)
FROM EXEMPLAIRE
GROUP BY ISBN;

-- code du trigger 
CREATE OR REPLACE TRIGGER T_Last_Exemplaire
BEFORE DELETE ON EXEMPLAIRE
FOR EACH ROW
DECLARE
v_Nb_exemplaire NUMBER;

BEGIN
SELECT Nb_exemplaire
INTO v_Nb_exemplaire
FROM TEMP_NB_EXEMPLAIRE
WHERE TEMP_NB_EXEMPLAIRE.ISBN = :OLD.ISBN;
IF (v_Nb_exemplaire) = 1 THEN
  DELETE FROM OUVRAGE WHERE OUVRAGE.ISBN = :OLD.ISBN;
END IF;
END;
/

-- test du trigger
ALTER TABLE EXEMPLAIRE DROP CONSTRAINT ISBN_Ouvrage;
DELETE FROM EXEMPLAIRE WHERE ISBN = '2020549522';
ALTER TABLE EXEMPLAIRE ADD CONSTRAINT ISBN_Ouvrage FOREIGN KEY(ISBN) REFERENCES OUVRAGE (ISBN) ON DELETE CASCADE;

-- suppression de la table temporaire
DROP TABLE TEMP_NB_EXEMPLAIRE;

/* Question 2 Déclencheur de vérification de la cotisation d'un membre à l'emprunt */

CREATE OR REPLACE TRIGGER T_Check_Emprunt
BEFORE INSERT ON EMPRUNTS
FOR EACH ROW
DECLARE
	Is_membre_ok boolean;

BEGIN
   Is_membre_ok := AdhesionAjour(:new.ID_adherent);
   IF NOT Is_membre_ok THEN
      -- Erreur qui empêche un nouvel emprunt
      RAISE_APPLICATION_ERROR(-20000,'Emprunt impossible, membre non à jour de ses cotisations');
   END IF;
END;
/

INSERT INTO EMPRUNTS VALUES(22,6,sysdate,null);

/* Question 3 Déclencheur interdissant le changement d'un membre pour une fiche de location */

CREATE OR REPLACE TRIGGER T_Modif_ID_Emprunt

BEFORE UPDATE OF ID_adherent ON EMPRUNTS
	REFERENCING OLD AS OLD_ID NEW AS NEW_ID
	FOR EACH ROW
	WHEN(NEW_ID.ID_adherent!=OLD_ID.ID_adherent)

BEGIN
	RAISE_APPLICATION_ERROR(-20001, 'ID adherent ne peut pas etre modifie pour un emprunt');
	ROLLBACK;
END;
/

UPDATE EMPRUNTS SET ID_adherent=4 WHERE Numero_emprunt=21;
UPDATE EMPRUNTS SET Etat_emprunt='En cours' WHERE Numero_emprunt=21;

/* Question 4 Déclencheur pour interdire de modifier la référence d'un ouvrage en cours d'emprunt */

CREATE OR REPLACE TRIGGER Modification_Ref_Ouvrage
BEFORE UPDATE OF ISBN ON OUVRAGE
FOR EACH ROW
DECLARE
v_ISBN VARCHAR2(20);
BEGIN
SELECT ISBN
INTO v_ISBN
FROM DETAILS
WHERE ISBN = :OLD.ISBN AND Date_retour IS NULL
GROUP BY ISBN;
IF v_ISBN IS NOT NULL THEN
  RAISE_APPLICATION_ERROR(-20002, 'Ce livre est est en cours d''emprunt, son referencement ne peut pas etre modifie');
END IF;
EXCEPTION
WHEN no_data_found THEN
  dbms_output.put_line('ISBN modifie');
END;
/

UPDATE OUVRAGE SET ISBN= '2251678365' WHERE ISBN = '2222222222';

/* Question 5 Déclencheur pour la mise à jour de la valeur NombreEmprunts */

CREATE OR REPLACE TRIGGER T_Maj_Etat
BEFORE UPDATE OR INSERT ON EXEMPLAIRE
FOR EACH ROW

BEGIN
   IF (:new.Nombre_emprunts<=10) THEN :new.Etat := 'Neuf';
   ELSIF (:new.Nombre_emprunts BETWEEN 11 AND 25) THEN :new.Etat := 'Bon';
   ELSIF (:new.Nombre_emprunts BETWEEN 26 AND 40) THEN :new.Etat := 'Moyen';
   ELSIF (:new.Nombre_emprunts >=41) THEN :new.Etat := 'Mauvais';
   END IF;
END;
/

/* Question 6 Assurer que l'emprunt a bien été pris en compte pour l'exemplaire */

-- Suppression de la contrainte d'éffacement en cascade inutile
ALTER TABLE DETAILS DROP CONSTRAINT Numero_Emprunts;

CREATE OR REPLACE TRIGGER T_Detail_Emprunt
BEFORE DELETE ON DETAILS
REFERENCING OLD AS OLD NEW AS NEW
FOR EACH ROW

BEGIN		
	DELETE FROM EMPRUNTS WHERE EMPRUNTS.Numero_emprunt = :OLD.Numero_emprunt;
END T_Detail_Emprunt;
/

    -- Test du Trigger --
DELETE FROM DETAILS WHERE Numero_emprunt=10;

/* Question 7 Information sur la date d'emprunt et par quel employés elle à été traitée */

ALTER TABLE DETAILS ADD(Employe VARCHAR2(10),Date_enregistrement_employe DATE);

ALTER TABLE EMPRUNTS ADD(Employe VARCHAR2(10),Date_enregistrement_employe DATE);

CREATE OR REPLACE TRIGGER T_Enregistrement_Emprunt
	BEFORE INSERT ON EMPRUNTS
	REFERENCING NEW AS NEW_Enregistrement
	FOR EACH ROW

BEGIN
	:NEW_Enregistrement.Employe := USER;
	:NEW_Enregistrement.Date_enregistrement_employe := SYSDATE;
END;
/

CREATE OR REPLACE TRIGGER T_Enregistrement_Details
	BEFORE INSERT ON DETAILS
	REFERENCING NEW AS NEW_Enregistrement
	FOR EACH ROW

BEGIN
	:NEW_Enregistrement.Employe := USER;
	:NEW_Enregistrement.Date_enregistrement_employe := SYSDATE;
END;
/

execute EmpruntExpress(2,2266091611,1);

/* Question 8 Fonction AnalyseActivite */

CREATE OR REPLACE FUNCTION AnalyseActivite(a_Nom IN VARCHAR2 DEFAULT NULL, a_Date IN DATE DEFAULT NULL) RETURN NUMBER IS
	v_Nb_Details number:=0;
	v_Nb_Emprunts number:=0;

BEGIN 
	IF(a_Nom is NULL AND a_Date is NOT NULL) THEN
		SELECT count(*) INTO v_Nb_Details
		FROM DETAILS
		WHERE to_char(Date_enregistrement_employe)=a_Date;
	
		SELECT count(*) INTO v_Nb_Emprunts
		FROM EMPRUNTS
		WHERE to_char(Date_enregistrement_employe)=a_Date;
	END IF;
	
	IF(a_Date is NULL AND a_Nom is NOT NULL) THEN
		
		SELECT count(*) INTO v_Nb_Details
		FROM DETAILS
		WHERE Employe=a_Nom;
	
		SELECT count(*) INTO v_Nb_Emprunts
		FROM EMPRUNTS
		WHERE Employe=a_Nom ;
		
	END IF;
	
	IF(a_Date is NOT NULL AND a_Nom is NOT NULL) THEN

		SELECT count(*) INTO v_Nb_Details
		FROM DETAILS
		WHERE Employe=a_Nom AND to_char(Date_enregistrement_employe)=a_Date;
	
		SELECT count(*) INTO v_Nb_Emprunts
		FROM EMPRUNTS
		WHERE Employe=a_Nom AND to_char(Date_enregistrement_employe)=a_Date;
		
	END IF;
	
	return v_Nb_Emprunts+v_Nb_Details;
END;
/

SELECT AnalyseActivite(user,TO_DATE(sysdate, 'DD-MM-YY')) FROM dual;

/* Question 9 Interdire ajout détails si tous les exemplaires ont été rendus */

CREATE OR REPLACE TRIGGER T_Exception_Emprunt
BEFORE INSERT OR UPDATE ON DETAILS
FOR EACH ROW

DECLARE
	CURSOR c_etat_emprunt IS
		SELECT *
		FROM DETAILS
		WHERE Numero_emprunt = :NEW.Numero_emprunt;
	
	v_etat_emprunt c_etat_emprunt%rowtype;
	cptr NUMBER:=0;

BEGIN		
	OPEN c_etat_emprunt;
	LOOP
		FETCH c_etat_emprunt INTO v_etat_emprunt;
		EXIT WHEN c_etat_emprunt%NOTFOUND;
		
		IF v_etat_emprunt.Date_retour IS NOT NULL THEN
			cptr:=cptr+1;
		END IF;
		
		IF cptr = c_etat_emprunt%ROWCOUNT THEN
			RAISE_APPLICATION_ERROR(-20001,' Impossible de rentrer un nouvel exemplaire pour l''emprunt n°'||v_etat_emprunt.Numero_emprunt);
		END IF;
	END LOOP;
	CLOSE c_etat_emprunt;
END;
/

INSERT INTO DETAILS(Numero_emprunt,Nombre_ouvrage,ISBN,Numero_exemplaire,Date_retour) VALUES (1,1,'2038704015',2,Sysdate-5);

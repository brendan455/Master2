/* Partie IV */

/* Question 1 Fonction FinValidite */

CREATE OR REPLACE FUNCTION FinValidite
  (a_numero_membre IN NUMBER)
RETURN DATE
IS
  v_fin_validite DATE;

BEGIN
  SELECT ADD_MONTHS(Date_adhesion, Duree_adhesion)
  INTO v_fin_validite
  FROM MEMBRE
  WHERE ID_adherent = a_numero_membre;
  RETURN v_fin_validite;
END FinValidite;
/

SELECT FinValidite(2) FROM dual;

/* Question 2 Fonction AdhesionAjour */

CREATE OR REPLACE FUNCTION AdhesionAjour
  (a_numero_membre IN NUMBER)
RETURN boolean AS
  v_adhesion_a_jour BOOLEAN;

BEGIN
  IF FinValidite(a_numero_membre) < sysdate THEN
    v_adhesion_a_jour := FALSE;
  ELSE
    v_adhesion_a_jour := TRUE;
  END IF;
  RETURN v_adhesion_a_jour;
END;
/

BEGIN
  IF (adhesionAJour(6)) THEN
    dbms_output.put_line('true');
    ELSE dbms_output.put_line('false');
  END IF;
END;
/

/* Question 3 Fonction RetourExemplaire */

CREATE OR REPLACE PROCEDURE RetourExemplaire(a_ISBN IN VARCHAR2, a_Numero_exemplaire IN NUMBER) IS

BEGIN
	UPDATE DETAILS SET DETAILS.Date_retour = SYSDATE
	WHERE DETAILS.ISBN=a_ISBN AND DETAILS.Numero_exemplaire=a_Numero_exemplaire AND DETAILS.Date_retour is NULL;
	DBMS_OUTPUT.PUT_LINE(' Requete effectuee ');
END;
/

execute RetourExemplaire(2266091611,1 );
SELECT * FROM details;

/* Question 4 Fonction PurgeMembres */

CREATE OR REPLACE PROCEDURE PurgeMembres IS
BEGIN
	DELETE FROM MEMBRE WHERE(MONTHS_BETWEEN(SYSDATE,ADD_MONTHS(Date_adhesion,Duree_adhesion))>36);
END;
	/

EXECUTE PurgeMembres;
SELECT * FROM MEMBRE;

/* Question 5 Fonction MesureActivite */

CREATE OR REPLACE FUNCTION MesureActivite(v_periode IN NUMBER)
RETURN NUMBER IS
   
   -- On stocke dans un curseur l'ID des membres ayant des emprunts pendant une période (donnée en paramètre) et le nombre des emprunts effectués pour chacun
   CURSOR c_emprunts_membre(periode IN NUMBER) IS
      SELECT iD_adherent, COUNT(*)
      FROM DETAILS d INNER JOIN EMPRUNTS e ON d.Numero_emprunt = e.Numero_emprunt
      WHERE months_between(SYSDATE, Cree_le)< periode
      GROUP BY iD_adherent;
      v_emprunts_membre c_emprunts_membre%ROWTYPE;

BEGIN
   open c_emprunts_membre(v_periode);
   -- Recherche du membre ayant le plus d'emprunts parmi ceux contenus dans le curseur c_emprunts_membre
   FETCH c_emprunts_membre INTO v_emprunts_membre;
   close c_emprunts_membre;
   RETURN v_emprunts_membre.ID_adherent;
END;
/

SELECT MesureActivite(6) from dual;

/* Question 6 Fonction EmpruntMoyen */

CREATE OR REPLACE FUNCTION EmpruntMoyen(a_ID IN NUMBER)
RETURN VARCHAR2 IS
   v_duree_emprunts NUMBER;

BEGIN
   SELECT ROUND(AVG(d.Date_retour-e.Cree_le),2) INTO v_duree_emprunts
   FROM DETAILS d INNER JOIN EMPRUNTS e ON d.Numero_emprunt = e.Numero_emprunt
   WHERE e.ID_adherent = a_ID AND d.Date_retour IS NOT NULL;
   RETURN v_duree_emprunts;
END;
/

SELECT EmpruntMoyen(2) FROM dual;

/* Question 7 Fonction DureeMoyenne */

CREATE OR REPLACE FUNCTION DureeMoyenne(a_ISBN IN VARCHAR2, a_Numero_exemplaire IN NUMBER DEFAULT NULL)
RETURN VARCHAR2 IS
   v_duree_emprunts NUMBER;

BEGIN
	IF(a_Numero_exemplaire IS NULL) THEN -- Juste ISBN --
		SELECT ROUND(AVG(d.Date_retour-e.Cree_le),2) INTO v_duree_emprunts
		FROM DETAILS d INNER JOIN EMPRUNTS e ON d.Numero_emprunt = e.Numero_emprunt
		WHERE d.ISBN = a_ISBN AND d.Date_retour IS NOT NULL;
	ELSE
		SELECT ROUND(AVG(d.Date_retour-e.Cree_le),2) INTO v_duree_emprunts
		FROM DETAILS d INNER JOIN EMPRUNTS e ON d.Numero_emprunt = e.Numero_emprunt
		WHERE d.ISBN = a_ISBN AND d.Numero_exemplaire=a_Numero_exemplaire AND d.Date_retour IS NOT NULL;
	END IF;
	RETURN v_duree_emprunts;
END;
/

SELECT DureeMoyenne(2266085816) FROM dual;
SELECT DureeMoyenne(2266085816,1) FROM dual;

/* Question 8 Procédure MajEtatExemplaire */

CREATE OR REPLACE PROCEDURE MajEtatExemplaire IS

CURSOR c_details IS
SELECT ISBN,Numero_exemplaire,count(*) AS Nb_emprunt 
FROM DETAILS 
GROUP BY ISBN,Numero_exemplaire;

--Variable pour le nombre d'emprunt de chaque exemplaire
v_c_details c_details%rowtype;

--Variable pour stocker l'etat de chaque exemplaire
v_etat EXEMPLAIRE.Etat%type;

BEGIN
	OPEN c_details;
		LOOP
			FETCH c_details INTO v_c_details;
			IF (v_c_details.Nb_emprunt<=10)
				THEN v_etat := 'Neuf';
					ELSIF (v_c_details.Nb_emprunt BETWEEN 11 AND 25)
						THEN v_etat := 'Bon';
						ELSIF (v_c_details.Nb_emprunt BETWEEN 26 AND 40)
							THEN v_etat := 'Moyen';
							ELSE v_etat := 'Mauvais';
			END IF;	
			UPDATE EXEMPLAIRE SET Etat=v_etat WHERE (v_c_details.ISBN = EXEMPLAIRE.ISBN AND v_c_details.Numero_exemplaire = EXEMPLAIRE.Numero_exemplaire); 
			EXIT WHEN c_details%NOTFOUND;
			
		END LOOP;
	CLOSE c_details;
END;
/

BEGIN
   DBMS_SCHEDULER.CREATE_JOB( 'MAJEtat' , 'MajEtatExemplaire' , systimestamp , 'systimestamp +14' ) ;
END;
/

EXECUTE MajEtatExemplaire;

/* Question 9 Fonction AjouteMembre */

CREATE OR REPLACE FUNCTION AjouteMembre
  (a_Nom IN VARCHAR2,
   a_Prenom IN VARCHAR2,
   a_adresse IN VARCHAR2,
   a_date_adhesion IN DATE,
   a_duree_adhesion IN NUMBER,
   a_telephone IN VARCHAR2)
RETURN NUMBER IS
  v_num_sequence NUMBER;

BEGIN
  INSERT INTO MEMBRE(ID_adherent,Nom,Prenom,Adresse,Date_adhesion,Duree_adhesion, Portable) VALUES (IDmember_seq.nextval, a_Nom,a_Prenom, a_adresse, a_date_adhesion, a_duree_adhesion, a_telephone)
  RETURNING ID_adherent INTO v_num_sequence;
  RETURN v_num_sequence;
END;
/

    -- Test de la fonction --

DECLARE
  v_num_sequence NUMBER := AjouteMembre('Doe', 'John', '1 rue Californie', Sysdate-10, 6, '06 12 34 56 78');
BEGIN
  DBMS_OUTPUT.PUT_LINE(' NUM SEQ : ' || v_num_sequence);
END;
/

/* Question 10 Procédure SupprimeExemplaire */

CREATE OR REPLACE PROCEDURE SupprimeExemplaire
	(	a_ISBN IN EXEMPLAIRE.ISBN%type,
		a_Numex IN EXEMPLAIRE.Numero_exemplaire%type)
IS
CURSOR c_exemplaire IS SELECT ISBN,Numero_exemplaire FROM EXEMPLAIRE WHERE (ISBN,Numero_exemplaire) NOT IN (SELECT ISBN,Numero_exemplaire FROM DETAILS WHERE(Date_retour IS NULL));
v_c_exemplaire c_exemplaire%rowtype;
v_404 NUMBER:=0;

BEGIN
	OPEN c_exemplaire;
		
		LOOP
			FETCH c_exemplaire INTO v_c_exemplaire;
			IF (a_ISBN=v_c_exemplaire.ISBN) AND (a_Numex=v_c_exemplaire.Numero_exemplaire)
				THEN DELETE FROM EXEMPLAIRE WHERE((ISBN=a_ISBN) AND (Numero_exemplaire=a_Numex));v_404:=1;
			END IF;
			EXIT WHEN NOT c_exemplaire%FOUND;
		END LOOP;
		IF (v_404=1)
			THEN DBMS_OUTPUT.PUT_LINE('--> Le livre a bien ete supprime ');
			ELSE DBMS_OUTPUT.PUT_LINE('--> Ce livre n''existe pas ou il est emprunte, impossible de le supprimer  ');
		END IF;
	CLOSE c_exemplaire;
END;
/

SELECT * FROM EXEMPLAIRE;

--Ici, l'exemplaire en en cours d'emprunt, il n'est pas supprimé de la table
execute SupprimeExemplaire(2253010219,1);

--Ici, bien que ce soit le même livre, l'exemplaire n'est pas emprunté, il est donc supprimé
execute SupprimeExemplaire(2253010219,2);
SELECT * FROM EXEMPLAIRE;

/* Question 11 Procédure EmpruntExpress */

CREATE OR REPLACE PROCEDURE EmpruntExpress(a_ID IN NUMBER, a_ISBN IN VARCHAR2, a_Numero_exemplaire IN NUMBER) IS
	vmax_Emprunt number;

BEGIN
	SELECT MAX(Numero_emprunt) INTO vmax_Emprunt FROM EMPRUNTS;
	INSERT INTO EMPRUNTS(Numero_emprunt,ID_adherent,Cree_le,Etat_emprunt) VALUES (vmax_Emprunt+1,a_ID,Sysdate,'En cours');
	INSERT INTO DETAILS(Numero_emprunt,Nombre_ouvrage,ISBN,Numero_exemplaire,Date_retour) VALUES (vmax_Emprunt+1,1,a_ISBN,a_Numero_exemplaire,NULL);
END;
/

execute EmpruntExpress(2,2266091611,1 );
SELECT * FROM details;

/* Question 12 Package Livre */

CREATE OR REPLACE PACKAGE Livre AS
	FUNCTION FinValidite(a_numero_membre IN NUMBER)	RETURN DATE;
	FUNCTION AdhesionAjour(a_numero_membre IN NUMBER) RETURN boolean;
	PROCEDURE RetourExemplaire(a_ISBN IN VARCHAR2, a_Numero_exemplaire IN NUMBER);
	PROCEDURE PurgeMembres;
	FUNCTION MesureActivite(v_periode IN NUMBER) RETURN NUMBER;
	FUNCTION EmpruntMoyen(a_ID IN NUMBER) RETURN VARCHAR2;
	FUNCTION DureeMoyenne(a_ISBN IN VARCHAR2, a_Numero_exemplaire IN NUMBER DEFAULT NULL) RETURN VARCHAR2;
	PROCEDURE MajEtatExemplaire;
	FUNCTION AjouteMembre(a_Nom IN VARCHAR2,a_Prenom IN VARCHAR2,a_adresse IN VARCHAR2,a_date_adhesion IN DATE,a_duree_adhesion IN NUMBER,a_telephone IN VARCHAR2) RETURN NUMBER;
	PROCEDURE SupprimeExemplaire(a_ISBN IN EXEMPLAIRE.ISBN%type,a_Numex IN EXEMPLAIRE.Numero_exemplaire%type);
	PROCEDURE EmpruntExpress(a_ID IN NUMBER, a_ISBN IN VARCHAR2, a_Numero_exemplaire IN NUMBER);
END;
/

CREATE OR REPLACE PACKAGE BODY Livre AS
	
	FUNCTION FinValidite(a_numero_membre IN NUMBER)
	RETURN DATE IS
		v_fin_validite DATE;
	
	BEGIN
		SELECT ADD_MONTHS(Date_adhesion, Duree_adhesion)
		INTO v_fin_validite
		FROM MEMBRE
		WHERE ID_adherent = a_numero_membre;
		RETURN v_fin_validite;
	END FinValidite;



	FUNCTION AdhesionAjour(a_numero_membre IN NUMBER)
	RETURN boolean AS
		v_adhesion_a_jour BOOLEAN;

	BEGIN
		IF FinValidite(a_numero_membre) < sysdate THEN
			v_adhesion_a_jour := FALSE;
		ELSE
			v_adhesion_a_jour := TRUE;
		END IF;
		RETURN v_adhesion_a_jour;
	END;



	PROCEDURE RetourExemplaire(a_ISBN IN VARCHAR2, a_Numero_exemplaire IN NUMBER) IS
	
	BEGIN
		UPDATE DETAILS SET DETAILS.Date_retour = SYSDATE
		WHERE DETAILS.ISBN=a_ISBN AND DETAILS.Numero_exemplaire=a_Numero_exemplaire AND DETAILS.Date_retour is NULL;
		DBMS_OUTPUT.PUT_LINE(' Requete effectuee ');
	END;



	PROCEDURE PurgeMembres IS
	BEGIN
		DELETE FROM MEMBRE WHERE(MONTHS_BETWEEN(SYSDATE,ADD_MONTHS(Date_adhesion,Duree_adhesion))>36);
	END;



	FUNCTION MesureActivite(v_periode IN NUMBER)
	RETURN NUMBER IS
	
	-- On stocke dans un curseur l'ID des membres ayant des emprunts pendant une période (donnée en paramètre) et le nombre des emprunts effectués pour chacun
	CURSOR c_emprunts_membre(periode IN NUMBER) IS
		SELECT iD_adherent, COUNT(*)
		FROM DETAILS d INNER JOIN EMPRUNTS e ON d.Numero_emprunt = e.Numero_emprunt
		WHERE months_between(SYSDATE, Cree_le)< periode
		GROUP BY iD_adherent;
		v_emprunts_membre c_emprunts_membre%ROWTYPE;
	
	BEGIN
		OPEN c_emprunts_membre(v_periode);
		-- Recherche du membre ayant le plus d'emprunts parmi ceux contenus dans le curseur c_emprunts_membre
		FETCH c_emprunts_membre INTO v_emprunts_membre;
		CLOSE c_emprunts_membre;
		RETURN v_emprunts_membre.ID_adherent;
	END;



	FUNCTION EmpruntMoyen(a_ID IN NUMBER)
	RETURN VARCHAR2 IS
		v_duree_emprunts NUMBER;
	
	BEGIN
		SELECT ROUND(AVG(d.Date_retour-e.Cree_le),2) INTO v_duree_emprunts
		FROM DETAILS d INNER JOIN EMPRUNTS e ON d.Numero_emprunt = e.Numero_emprunt
		WHERE e.ID_adherent = a_ID AND d.Date_retour IS NOT NULL;
		RETURN v_duree_emprunts;
	END;



	FUNCTION DureeMoyenne(a_ISBN IN VARCHAR2, a_Numero_exemplaire IN NUMBER DEFAULT NULL)
	RETURN VARCHAR2 IS
		v_duree_emprunts NUMBER;
	
	BEGIN
		IF(a_Numero_exemplaire IS NULL) THEN -- Juste ISBN --
			SELECT ROUND(AVG(d.Date_retour-e.Cree_le),2) INTO v_duree_emprunts
			FROM DETAILS d INNER JOIN EMPRUNTS e ON d.Numero_emprunt = e.Numero_emprunt
			WHERE d.ISBN = a_ISBN AND d.Date_retour IS NOT NULL;
		ELSE
			SELECT ROUND(AVG(d.Date_retour-e.Cree_le),2) INTO v_duree_emprunts
			FROM DETAILS d INNER JOIN EMPRUNTS e ON d.Numero_emprunt = e.Numero_emprunt
			WHERE d.ISBN = a_ISBN AND d.Numero_exemplaire=a_Numero_exemplaire AND d.Date_retour IS NOT NULL;
		END IF;
		RETURN v_duree_emprunts;
	END;

	

	PROCEDURE MajEtatExemplaire IS
		CURSOR c_details IS
		SELECT ISBN,Numero_exemplaire,count(*) AS Nb_emprunt 
		FROM DETAILS 
		GROUP BY ISBN,Numero_exemplaire;
		
		--Variable pour le nombre d'emprunt de chaque exemplaire
		v_c_details c_details%rowtype;
		
		--Variable pour stocker l'etat de chaque exemplaire
		v_etat EXEMPLAIRE.Etat%type;
	
	BEGIN
		OPEN c_details;
		LOOP
			FETCH c_details INTO v_c_details;
			IF (v_c_details.Nb_emprunt<=10)
				THEN v_etat := 'Neuf';
					ELSIF (v_c_details.Nb_emprunt BETWEEN 11 AND 25)
						THEN v_etat := 'Bon';
						ELSIF (v_c_details.Nb_emprunt BETWEEN 26 AND 40)
							THEN v_etat := 'Moyen';
							ELSE v_etat := 'Mauvais';
			END IF;	
			UPDATE EXEMPLAIRE SET Etat=v_etat WHERE (v_c_details.ISBN = EXEMPLAIRE.ISBN AND v_c_details.Numero_exemplaire = EXEMPLAIRE.Numero_exemplaire); 
			EXIT WHEN c_details%NOTFOUND;
			
		END LOOP;
		CLOSE c_details;
	END;

	
	FUNCTION AjouteMembre(a_Nom IN VARCHAR2,a_Prenom IN VARCHAR2,a_adresse IN VARCHAR2,a_date_adhesion IN DATE,a_duree_adhesion IN NUMBER,a_telephone IN VARCHAR2)
	RETURN NUMBER IS
		v_num_sequence NUMBER;
	
	BEGIN
		INSERT INTO MEMBRE(ID_adherent,Nom,Prenom,Adresse,Date_adhesion,Duree_adhesion, Portable) VALUES (IDmember_seq.nextval, a_Nom,a_Prenom, a_adresse, a_date_adhesion, a_duree_adhesion, a_telephone)
		RETURNING ID_adherent INTO v_num_sequence;
		RETURN v_num_sequence;
	END;

	PROCEDURE SupprimeExemplaire(a_ISBN IN EXEMPLAIRE.ISBN%type,a_Numex IN EXEMPLAIRE.Numero_exemplaire%type) IS
		CURSOR c_exemplaire IS SELECT ISBN,Numero_exemplaire FROM EXEMPLAIRE WHERE (ISBN,Numero_exemplaire) NOT IN (SELECT ISBN,Numero_exemplaire FROM DETAILS WHERE(Date_retour IS NULL));
		v_c_exemplaire c_exemplaire%rowtype;
		v_404 NUMBER:=0;

	BEGIN
		OPEN c_exemplaire;
		LOOP
			FETCH c_exemplaire INTO v_c_exemplaire;
			IF (a_ISBN=v_c_exemplaire.ISBN) AND (a_Numex=v_c_exemplaire.Numero_exemplaire)
				THEN DELETE FROM EXEMPLAIRE WHERE((ISBN=a_ISBN) AND (Numero_exemplaire=a_Numex));v_404:=1;
			END IF;
			EXIT WHEN NOT c_exemplaire%FOUND;
		END LOOP;
		IF (v_404=1)
			THEN DBMS_OUTPUT.PUT_LINE('--> Le livre a bien ete supprime ');
			ELSE DBMS_OUTPUT.PUT_LINE('--> Ce livre n''existe pas ou il est emprunte, impossible de le supprimer  ');
		END IF;
		CLOSE c_exemplaire;
	END;


	PROCEDURE EmpruntExpress(a_ID IN NUMBER, a_ISBN IN VARCHAR2, a_Numero_exemplaire IN NUMBER) IS
		vmax_Emprunt number;
	
	BEGIN
		SELECT MAX(Numero_emprunt) INTO vmax_Emprunt FROM EMPRUNTS;
		INSERT INTO EMPRUNTS(Numero_emprunt,ID_adherent,Cree_le,Etat_emprunt) VALUES (vmax_Emprunt+1,a_ID,Sysdate,'En cours');
		INSERT INTO DETAILS(Numero_emprunt,Nombre_ouvrage,ISBN,Numero_exemplaire,Date_retour) VALUES (vmax_Emprunt+1,1,a_ISBN,a_Numero_exemplaire,NULL);
	END;



END Livre;
/

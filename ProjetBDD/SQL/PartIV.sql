/* Partie IV */

/* Question 1 Mise à jour conditionelle */

set serveroutput on;
DECLARE

--Curseur contenant les attributs de la table DETAILS
CURSOR c_details IS SELECT ISBN,Numero_exemplaire,count(*) as Nb_emprunt 
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
			IF (v_c_details.Nb_emprunt<=1)
				THEN v_etat := 'Neuf';
					ELSIF (v_c_details.Nb_emprunt<=2)
						THEN v_etat := 'Bon';
						ELSIF (v_c_details.Nb_emprunt<=3)
							THEN v_etat := 'Moyen';
							ELSE v_etat := 'Mauvais';
			END IF;	
			UPDATE EXEMPLAIRE SET Etat=v_etat WHERE (v_c_details.ISBN = EXEMPLAIRE.ISBN AND v_c_details.Numero_exemplaire = EXEMPLAIRE.Numero_exemplaire); 
			EXIT WHEN c_details%NOTFOUND;
			
		END LOOP;
	CLOSE c_details;
END;
/

/* Question 2 Supprimez les membres dont l'adhésion à expirés il y a plus de 2 ans */

DECLARE
	
-- CURSOR contient les ids des membres avec adhesion expiree depuis plus de 2 ans et ayant emprunté un livre qui est rendu
-- c_ID_membres_adhesion_expiree_livres_non_rendus
CURSOR c_ID_membres_a_supprime IS
SELECT m.ID_adherent 
FROM MEMBRE m INNER JOIN EMPRUNTS e ON m.ID_adherent=e.ID_adherent 
WHERE MONTHS_BETWEEN(sysdate, ADD_MONTHS(m.Date_adhesion,m.Duree_adhesion))>24 
AND e.Etat_Emprunt NOT IN ('En cours'); 
v_ID_membres_a_supprime c_ID_membres_a_supprime%ROWTYPE;

BEGIN
	OPEN c_ID_membres_a_supprime;
	
	-- Dans les ids selectionnes, verifie emprunt rendu. Si oui, supprime membre
	IF c_ID_membres_a_supprime%ISOPEN THEN
		LOOP
			FETCH c_ID_membres_a_supprime into v_ID_membres_a_supprime;
			EXIT WHEN c_ID_membres_a_supprime%NOTFOUND;
			UPDATE EMPRUNTS SET ID_adherent = NULL WHERE ID_adherent = v_ID_membres_a_supprime.ID_adherent;
			DELETE FROM MEMBRE WHERE MEMBRE.ID_adherent = v_ID_membres_a_supprime.ID_adherent;
			DBMS_OUTPUT.PUT_LINE('ID membre supprime' ||v_ID_membres_a_supprime.ID_adherent);
		END LOOP;
	END IF;
	CLOSE c_ID_membres_a_supprime;
END;
/

/* Question 3 Affichez les 3 membres qui ont empruntés le plus d'ouvrages les dix derniers mois et ceux qui en ont empruntés le moins */

DECLARE

-- Curseur avec le nombre d'emprunts de chaque ouvrage, trié par ordre croissant
CURSOR Min3_Emprunts IS
SELECT ID_adherent,COUNT(*) as Nb_Emprunt
FROM EMPRUNTS
WHERE months_between(Sysdate,Cree_le)<=10
GROUP BY ID_adherent
ORDER BY COUNT(*) ASC;

-- Curseur avec le nombre d'emprunts de chaque ouvrage, trié par ordre décroissant
CURSOR Max3_Emprunts IS
SELECT ID_adherent,COUNT(*) as Nb_emprunt
FROM EMPRUNTS
WHERE months_between(Sysdate,Cree_le)<=10
GROUP BY ID_adherent
ORDER BY COUNT(*) DESC;
record_3 Max3_Emprunts%rowtype;
j number;
v_MEMBRE MEMBRE%rowtype;

BEGIN
	OPEN Max3_Emprunts;
	DBMS_OUTPUT.PUT_LINE('Les 3 membres ayant empruntes le plus de livres dans les 10 derniers mois sont :');	
	FOR j IN 1..3 LOOP
		FETCH Max3_Emprunts INTO record_3;
		EXIT WHEN Max3_Emprunts%NOTFOUND;
		SELECT * INTO v_MEMBRE
		FROM MEMBRE
		WHERE ID_adherent=record_3.ID_adherent;
		DBMS_OUTPUT.PUT_LINE('Membre N° '|| record_3.ID_adherent || ' a le nom ' || v_MEMBRE.nom || ' et le prenom ' ||  v_MEMBRE.prenom || ' et a emprunte ' || record_3.Nb_Emprunt || ' livres ');
	END LOOP;
	CLOSE Max3_Emprunts;

	OPEN Min3_Emprunts;
	DBMS_OUTPUT.PUT_LINE('Les 3 membres ayant empruntes le moins de livres dans les 10 derniers mois sont :');
	FOR j IN 1..3 LOOP
		FETCH Min3_Emprunts INTO record_3;
		EXIT WHEN Min3_Emprunts%NOTFOUND;
		SELECT * INTO v_MEMBRE
		FROM MEMBRE
		WHERE ID_adherent=record_3.ID_adherent;
		DBMS_OUTPUT.PUT_LINE('Membre N° '|| record_3.ID_adherent || ' a le nom ' || v_MEMBRE.nom || ' et le prenom ' ||  v_MEMBRE.prenom || ' et a emprunte ' || record_3.Nb_Emprunt || ' livres ');
	END LOOP;
	CLOSE Min3_Emprunts;
END ; 
/

/* Question 4 Affichez les 5 ouvrages les plus empruntés */

DECLARE

CURSOR c_ouvrage_exemplaire IS
SELECT ISBN, Numero_exemplaire, count(*) as ouvrage_plus_emprunte
FROM DETAILS
GROUP BY ISBN, Numero_exemplaire
ORDER BY ouvrage_plus_emprunte DESC;
V_ouvrage_exemplaire c_ouvrage_exemplaire%ROWTYPE;

BEGIN
  OPEN c_ouvrage_exemplaire;
  IF c_ouvrage_exemplaire%ISOPEN THEN
    LOOP
      FETCH c_ouvrage_exemplaire into V_ouvrage_exemplaire;
      EXIT WHEN c_ouvrage_exemplaire%ROWCOUNT > 5;
      DBMS_OUTPUT.PUT_LINE('L''exemplaire :' || V_ouvrage_exemplaire.Numero_exemplaire || ' de l''ouvrage ' || V_ouvrage_exemplaire.ISBN || ' a ete emprunte ' || V_ouvrage_exemplaire.ouvrage_plus_emprunte);
    END LOOP;
  END IF;
  CLOSE c_ouvrage_exemplaire;
END;
/

/* Question 5 Listes des membres dont l'adhésion a expiré ou bien dans 30 jours */

DECLARE

CURSOR c_adhesion_expire IS
SELECT Nom, Prenom, Date_adhesion
FROM MEMBRE
WHERE months_between(Sysdate,ADD_MONTHS(Date_adhesion,Duree_adhesion)) >= 1;
v_adhesion_expire c_adhesion_expire%ROWTYPE;

BEGIN
  OPEN c_adhesion_expire;
  IF c_adhesion_expire%ISOPEN THEN
    LOOP
      FETCH c_adhesion_expire into v_adhesion_expire;
      EXIT WHEN c_adhesion_expire%NOTFOUND;
      DBMS_OUTPUT.PUT_LINE('L''adhesion de ' || v_adhesion_expire.Nom || ' ' || v_adhesion_expire.Prenom || ' est/va bientôt expire. Date d''adhesion: ' || v_adhesion_expire.Date_adhesion );
    END LOOP;
  END IF;
  CLOSE c_adhesion_expire;
END;
/

/* Question 6 Mise à jour du système d'état d'un exemplaire */

ALTER TABLE EXEMPLAIRE ADD (Nombre_emprunts NUMBER(3) DEFAULT NULL);
ALTER TABLE EXEMPLAIRE ADD (Date_calcule_emprunts DATE DEFAULT sysdate);

DECLARE

CURSOR c_nb_emprunt IS
SELECT ISBN, Numero_exemplaire, count(*) as Nb_Emprunt
FROM DETAILS
GROUP BY ISBN, Numero_exemplaire
ORDER BY Nb_Emprunt DESC;
v_nb_emprunt c_nb_emprunt%ROWTYPE;

CURSOR c_date_1er_emprunt IS
SELECT ISBN, Numero_exemplaire, Cree_le
FROM EMPRUNTS e INNER JOIN DETAILS d ON e.Numero_emprunt = d.Numero_emprunt
ORDER BY ISBN, Numero_exemplaire, Cree_le DESC;
v_date_1er_emprunt c_date_1er_emprunt%ROWTYPE;

BEGIN
  OPEN c_nb_emprunt;
  IF c_nb_emprunt%ISOPEN THEN
    LOOP
      FETCH c_nb_emprunt into v_nb_emprunt;
      EXIT WHEN c_nb_emprunt%NOTFOUND;
      UPDATE EXEMPLAIRE SET Nombre_emprunts = v_nb_emprunt.Nb_Emprunt WHERE v_nb_emprunt.ISBN = EXEMPLAIRE.ISBN AND v_nb_emprunt.Numero_exemplaire = EXEMPLAIRE.Numero_exemplaire;
    END LOOP;
  END IF;
  CLOSE c_nb_emprunt;
 
  OPEN c_date_1er_emprunt;
  IF c_date_1er_emprunt%ISOPEN THEN
    LOOP
      FETCH c_date_1er_emprunt into v_date_1er_emprunt;
      EXIT WHEN c_date_1er_emprunt%NOTFOUND;
      UPDATE EXEMPLAIRE SET Date_calcule_emprunts= v_date_1er_emprunt.Cree_le WHERE v_date_1er_emprunt.ISBN = EXEMPLAIRE.ISBN AND v_date_1er_emprunt.Numero_exemplaire = EXEMPLAIRE.Numero_exemplaire;
    END LOOP;
  END IF;
  CLOSE c_date_1er_emprunt;
END;
/

/* Question 7 Ajout d'une contrainte d'intégrité d'un exemplaire */

DECLARE
  
CURSOR C_Nb_Etat_Moyen_Mauvais IS
SELECT COUNT(*) AS nb_etat_moyen_mauvais
FROM EXEMPLAIRE
WHERE Etat = 'Moyen' OR Etat = 'Mauvais';
v_Nb_Etat_Moyen_Mauvais C_Nb_Etat_Moyen_Mauvais%ROWTYPE;

CURSOR C_Nb_exemplaire IS
SELECT *
FROM EXEMPLAIRE;
v_Nb_exemplaire C_Nb_exemplaire%ROWTYPE;

BEGIN
  OPEN C_Nb_Etat_Moyen_Mauvais;
  OPEN C_Nb_exemplaire;
  FETCH C_Nb_Etat_Moyen_Mauvais into v_Nb_Etat_Moyen_Mauvais;
  LOOP
    FETCH C_Nb_exemplaire into v_Nb_exemplaire;
    EXIT WHEN C_Nb_exemplaire%NOTFOUND;
  END LOOP;
  IF v_Nb_Etat_Moyen_Mauvais.nb_etat_moyen_mauvais > (C_Nb_exemplaire%ROWCOUNT/2) THEN
    UPDATE EXEMPLAIRE SET Etat= 'Douteux' WHERE (ISBN, Numero_exemplaire) IN(SELECT ISBN, Numero_exemplaire FROM DETAILS GROUP BY ISBN, Numero_exemplaire HAVING COUNT (*)>40);
    UPDATE EXEMPLAIRE SET Etat= 'Mauvais' WHERE (ISBN, Numero_exemplaire) IN(SELECT ISBN, Numero_exemplaire FROM DETAILS GROUP BY ISBN, Numero_exemplaire HAVING COUNT (*)>60);
  END IF;
  CLOSE C_Nb_exemplaire;
  CLOSE C_Nb_Etat_Moyen_Mauvais;
END;
/

/* Question 8 Supprimez les membres sans emprunts depuis 3 ans */

DECLARE
CURSOR c_dernier_emprunt IS
SELECT ID_adherent, MAX(Cree_le) as dernier_emprunt
FROM EMPRUNTS
GROUP BY ID_adherent;
v_dernier_emprunt c_dernier_emprunt%ROWTYPE;

BEGIN
  OPEN c_dernier_emprunt;
  IF c_dernier_emprunt%ISOPEN THEN
    LOOP
      FETCH c_dernier_emprunt into v_dernier_emprunt;
      EXIT WHEN c_dernier_emprunt%NOTFOUND;
      IF months_between(sysdate, v_dernier_emprunt.dernier_emprunt) > 36 THEN
        DELETE FROM MEMBRE WHERE ID_adherent = v_dernier_emprunt.ID_adherent;
      END IF;
    END LOOP;
  END IF;
  CLOSE c_dernier_emprunt;
END;
/

/* Question 9 Contrainte pour assurer la conformité du format pour le téléphone */

ALTER TABLE MEMBRE MODIFY(Portable VARCHAR2(14));

DECLARE

CURSOR c_membres IS
SELECT * FROM MEMBRE FOR UPDATE OF Portable;
v_portable_a_corriger MEMBRE.Portable%TYPE;

BEGIN
	FOR membre in c_membres LOOP
	IF NOT REGEXP_LIKE(membre.Portable,'^06[[:space:]][[:digit:]]{2}[[:space:]][[:digit:]]{2}[[:space:]][[:digit:]]{2}[[:space:]][[:digit:]]{2}$') THEN
   	v_portable_a_corriger := substr(membre.Portable,1,2) || ' ' ||
   	                         substr(membre.Portable,3,2) || ' ' ||
   	                         substr(membre.Portable,5,2) || ' ' ||
   	                         substr(membre.Portable,7,2) || ' ' ||
   	                         substr(membre.Portable,9,2);
      UPDATE MEMBRE
         SET Portable = v_portable_a_corriger
         WHERE CURRENT OF c_membres;
	END IF;
	END LOOP;

END;
/

ALTER TABLE MEMBRE DROP CONSTRAINT with06;
ALTER TABLE MEMBRE ADD CONSTRAINT Portable_format CHECK(REGEXP_LIKE(Portable, '^06[[:space:]][[:digit:]]{2}[[:space:]][[:digit:]]{2}[[:space:]][[:digit:]]{2}[[:space:]][[:digit:]]{2}$'));

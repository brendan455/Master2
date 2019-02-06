/* Partie II */

/* Question 4 Consultation de toutes les tables */

SELECT * FROM LIBELLE_GENRE;
SELECT * FROM OUVRAGE;
SELECT * FROM EXEMPLAIRE;
SELECT * FROM MEMBRE;
SELECT * FROM EMPRUNTS;
SELECT * FROM DETAILS;

/* Question 5 */

/* La commande ROW MOVEMENT permet une utilisation de retour en arrière via la commande FLASHBACK */
ALTER TABLE MEMBRE ENABLE ROW MOVEMENT;
ALTER TABLE DETAILS ENABLE ROW MOVEMENT

/* Question 6 Ajout de la colonne Etat_Emprunt dans la table EMPRUNTS */

ALTER TABLE EMPRUNTS ADD(Etat_Emprunt VARCHAR2(2) DEFAULT 'EC' CHECK( Etat_Emprunt IN ('EC', 'RE')) );

/* La colonne Etat_Emprunt prend la valeur RE si les ouvrages empruntes ont ete rendues */
UPDATE EMPRUNTS SET Etat_Emprunt = 'RE' 
WHERE Numero_emprunt != 20;

/* Question 7 Mise a jour de l'etat des ouvrages en fonction du nombre d'emprunts */

UPDATE EXEMPLAIRE SET Etat= 'Bon' 
WHERE (ISBN, Numero_exemplaire) IN(SELECT ISBN, Numero_exemplaire 
FROM DETAILS 
GROUP BY ISBN, Numero_exemplaire HAVING COUNT (*)>11);

UPDATE EXEMPLAIRE SET Etat= 'Moyen' 
WHERE (ISBN, Numero_exemplaire) IN(SELECT ISBN, Numero_exemplaire 
FROM DETAILS 
GROUP BY ISBN, Numero_exemplaire 
HAVING COUNT (*)>25);

UPDATE EXEMPLAIRE SET Etat= 'Mauvais' 
WHERE (ISBN, Numero_exemplaire) IN(SELECT ISBN, Numero_exemplaire 
FROM DETAILS 
GROUP BY ISBN, Numero_exemplaire 
HAVING COUNT (*)>60);

/* Question 8 Supprimer les exemplaires dans un mauvais etat */

DELETE FROM EXEMPLAIRE WHERE Etat='Mauvais';

/* Question 9 Etablissez la liste des ouvrages que possède la bibliotheque */

SELECT Titre,Auteur FROM OUVRAGE;

/* Question 10 Liste des membres qui ont emprunte un ouvrage depuis plus de deux semaines et indiquer l'ouvrage */

SELECT ID_adherent, ROUND(d.Date_retour - e.Cree_le,2) AS Jours
FROM EMPRUNTS e INNER JOIN DETAILS d ON e.Numero_emprunt = d.Numero_emprunt 
WHERE d.Date_retour IS NOT NULL AND d.Date_retour - e.Cree_le > 15;

/* Question 11 Liste du nombre d'ouvrage par categorie */

SELECT Genre,COUNT(*) AS Nb_Ouvrage FROM OUVRAGE GROUP BY Genre;

/* Question 12 Duree moyenne d'emprunt d'un ouvrage par un membre */

SELECT e.ID_adherent, ROUND(AVG(d.Date_retour - e.Cree_le),2) AS "Durée moyenne d'emprunt"
FROM EMPRUNTS e, DETAILS d
WHERE e.Numero_emprunt = d.Numero_emprunt AND d.Date_retour IS NOT NULL
GROUP BY e.ID_adherent
ORDER BY e.ID_adherent;

/* Question 13 Duree moyenne d'emprunt en fonction du genre de l'ouvrage */

SELECT o.Genre, ROUND(AVG(d.Date_retour - e.Cree_le),2) AS "Durée moyenne d'emprunt"
FROM EMPRUNTS e, OUVRAGE o INNER JOIN DETAILS d ON o.ISBN=d.ISBN
WHERE e.Numero_emprunt = d.Numero_emprunt AND d.Date_retour IS NOT NULL
GROUP BY o.Genre;

/* Question 14 Liste des ouvrages loues plus de 10 fois au cours de l'annee */

SELECT Titre,Auteur 
FROM OUVRAGE 
WHERE ISBN IN (SELECT ISBN FROM DETAILS WHERE ((Sysdate-Date_retour)< 365) GROUP BY ISBN HAVING count(*) > 10);

/* Question 15 Liste de tous les ouvrages en indiquant le nombre d'exemplaires de la base */

SELECT o.Titre, e.Numero_exemplaire
FROM OUVRAGE o INNER JOIN EXEMPLAIRE e ON o.ISBN=e.ISBN
ORDER BY o.Titre, e.Numero_exemplaire;

/* Question 16 Creation d'une vue pour connaitre le nombre d'ouvrage non rendu pour chaque membre */

CREATE OR REPLACE VIEW  Nb_Ouvrage_Membre AS 
SELECT e.ID_adherent, count(*) AS Nb_Emprunts 
FROM EMPRUNTs e INNER JOIN  DETAILS d ON e.Numero_emprunt=d.Numero_emprunt
WHERE (d.Date_retour IS NULL)
GROUP BY e.ID_adherent;

/* Question 17 Creation d'une vue affichant le nombre d'emprunt par ouvrage */

CREATE OR REPLACE VIEW Nb_Emprunts_Ouvrage AS 
SELECT ISBN,count(*) AS Nb_Emprunt 
FROM DETAILS 
GROUP BY ISBN;

/* Question 18 Liste des membres tries par ordre alphabetique */

SELECT m.Nom, m.Prenom
FROM Membre m
ORDER BY m.Nom;

/* Question 19 Nombre de location par titre et nombre de locations de chaque exemplaire */

CREATE GLOBAL TEMPORARY TABLE TEMP_LOCATION_TITRE(
	ISBN VARCHAR2(20),
	Nb_location_titre NUMBER(3)
) ON COMMIT PRESERVE ROWS; 

CREATE GLOBAL TEMPORARY TABLE TEMP_LOCATION_EXEMPLAIRE(
	ISBN VARCHAR2(20),
	Numero_exemplaire NUMBER(2),
	Nb_location_exemplaire NUMBER(3)
) ON COMMIT PRESERVE ROWS; 


INSERT INTO TEMP_LOCATION_TITRE (ISBN, Nb_location_titre)
SELECT ISBN, COUNT(*)
FROM DETAILS
GROUP BY ISBN;

INSERT INTO TEMP_LOCATION_EXEMPLAIRE (ISBN, Numero_exemplaire, Nb_location_exemplaire)
SELECT ISBN, Numero_exemplaire, COUNT(*)
FROM DETAILS
GROUP BY ISBN, Numero_exemplaire;

/* Question 20 Liste des genres et des ouvrages correspondant */

SELECT Titre, Genre
FROM OUVRAGE
WHERE Genre IN (SELECT Genre FROM OUVRAGE GROUP BY Genre)
ORDER BY Titre;

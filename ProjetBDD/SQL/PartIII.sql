/* Partie III */

/* Question 1 Etablissez le nombres d'emprunts par ouvrage et par exemplaire */

SELECT DECODE(GROUPING(ISBN),1 ,'Tous ISBN', ISBN) AS ISBN,
DECODE(GROUPING(Numero_Exemplaire),1 ,'Tous Exemplaire', Numero_Exemplaire) AS Nb_Exemplaire, count(*) AS Nb_Emprunt
FROM DETAILS
GROUP BY ROLLUP(ISBN,Numero_Exemplaire);

/* Question 2 Etablissez la liste des exemplaires qui n'ont jamais été empruntés au cours des 3 derniers mois */

SELECT ISBN,Numero_exemplaire 
FROM EXEMPLAIRE 
WHERE (ISBN,Numero_Exemplaire) 
NOT IN (SELECT ISBN,Numero_exemplaire FROM DETAILS WHERE months_between(Sysdate,Date_retour)< 3);

/* Question 3 Etablissez la liste des ouvrages sans exemplaires à l'état neuf */

SELECT Titre
FROM OUVRAGE
WHERE ISBN NOT IN (SELECT ISBN FROM EXEMPLAIRE WHERE Etat IN ('Neuf'));

/* Question 4 Tous les titres avec le mot "mer" */

SELECT Titre
FROM OUVRAGE
WHERE LOWER(Titre) LIKE '%mer%';

/* Question 5 Liste des auteurs avec la particule "de" */

SELECT Auteur
FROM OUVRAGE
WHERE REGEXP_LIKE(Auteur, '.*\sde\s.*');

/* Question 6 Afficher les correspondances "genre" / "public" pour les ouvrages de la bibliothèque */

SELECT ISBN, Titre, CASE Genre 
	WHEN 'BD' THEN 'Jeunesse' 
	WHEN 'INF' THEN 'Professionnel' 
	WHEN 'POL' THEN 'Adulte' 
	ELSE 'Tous'
	END as "PUBLIC"
FROM OUVRAGE;

/* Question 7 Commentez les différentes tables */

COMMENT ON TABLE MEMBRE IS 'Descriptifs des membres. Possede le synonymes Abonnes.';
COMMENT ON TABLE LIBELLE_GENRE IS 'Descriptifs des genres possibles des ouvrages.';
COMMENT ON TABLE OUVRAGE IS 'Descriptifs des ouvrages references par la bibliotheque.';
COMMENT ON TABLE EXEMPLAIRE IS 'Definition precise des livres presents dans la bibliotheque.';
COMMENT ON TABLE EMPRUNTS IS 'Fiche d''emprunt de livres, toujours associee à un et un seul membre.';
COMMENT ON TABLE DETAILS IS 'Chaque ligne correspond a un livre emprunte.';

/* Question 8 Intérrogez les commentaires associés aux tables */

SELECT table_name,comments 
FROM user_tab_comments 
WHERE comments IS NOT NULL;

/* Question 9 Etablissement d'une contrainte d'emprunt pour un nouveau membre */

ALTER TABLE EMPRUNTS DROP CONSTRAINT ID_adherent_Membre;
ALTER TABLE EMPRUNTS ADD CONSTRAINT ID_adherent_Membre FOREIGN KEY(ID_adherent) REFERENCES MEMBRE(ID_adherent) ON DELETE CASCADE DEFERRABLE INITIALLY DEFERRED;

/* Question 10 supprimez la table des détails */

DROP TABLE DETAILS;

/* Question 11 Annulez cette suppression de table */

FLASHBACK TABLE DETAILS TO BEFORE DROP;

/* Question 12 Etablissez une requete affichant un message en fonction du nombre d'exemplaire d'un ouvrage */

SELECT ISBN, COUNT(*) AS Nb_exemplaire, CASE COUNT(*)
	WHEN 0 THEN 'Aucun' 
	WHEN 1 THEN 'Peu' 
	WHEN 2 THEN 'Normal'
	WHEN 3 THEN 'Normal'
	WHEN 4 THEN 'Normal' 
	ELSE 'Beaucoup' END as "QUANTITE"
FROM EXEMPLAIRE
GROUP BY ISBN;

/* Partie I */

/* Question 1 Mise en place des tables */

create table LIBELLE_GENRE
(
	Genre VARCHAR2(10),
	Libelle VARCHAR2(20)  NOT NULL,
	CONSTRAINT LIBELLE_GENRE_pk PRIMARY KEY (Genre)
);

create table OUVRAGE
(
	ISBN VARCHAR2(20),
	Titre VARCHAR2(100) NOT NULL,
	Auteur VARCHAR2(20) NOT NULL,
	Genre VARCHAR2(10) NOT NULL,
	Editeur VARCHAR2(20) NOT NULL,
	CONSTRAINT Genre_Libelle FOREIGN KEY(Genre) REFERENCES Libelle_genre(Genre),
	CONSTRAINT Ouvrage_pk PRIMARY KEY (ISBN)
);

create table EXEMPLAIRE
(
	ISBN VARCHAR2(20),
	Numero_exemplaire NUMBER(2),
	Etat VARCHAR2(8) CHECK( Etat IN('Mauvais', 'Moyen', 'Bon', 'Neuf'))  NOT NULL,
	CONSTRAINT ISBN_Ouvrage FOREIGN KEY(ISBN) REFERENCES OUVRAGE (ISBN) ON DELETE CASCADE,
	CONSTRAINT Exemplaire_pk PRIMARY KEY (Numero_exemplaire,ISBN)
);

create table MEMBRE
(
	ID_adherent NUMBER(6),
	Nom VARCHAR2(20) NOT NULL,
	Prenom VARCHAR2(20) NOT NULL,
	Adresse VARCHAR2(30) NOT NULL,
	Telephone VARCHAR2(10),
	Date_adhesion DATE NOT NULL,
	Duree_adhesion NUMBER(2) NOT NULL,
	CONSTRAINT Membre_pk PRIMARY KEY (ID_adherent),
	CONSTRAINT Tel_unique UNIQUE (Telephone)
);

create table EMPRUNTS
(
	Numero_emprunt NUMBER(6),
	ID_adherent NUMBER(6),
	Cree_le DATE NOT NULL,
	CONSTRAINT ID_adherent_Membre FOREIGN KEY(ID_adherent) REFERENCES MEMBRE (ID_adherent) ON DELETE CASCADE,
	CONSTRAINT emprunt_pk PRIMARY KEY (Numero_emprunt)
);

create table DETAILS_EMPRUNTS
(
	Numero_emprunt NUMBER(6),
	Nombre_Ouvrage NUMBER(6),
	ISBN VARCHAR2(20),
	Numero_exemplaire NUMBER(2),
	Date_retour DATE,
	CONSTRAINT Numero_Emprunts FOREIGN KEY(Numero_emprunt) REFERENCES EMPRUNTS (Numero_emprunt),
	CONSTRAINT Numero_Exemplaire_ISBN FOREIGN KEY(Numero_exemplaire,ISBN) REFERENCES EXEMPLAIRE (Numero_exemplaire,ISBN) ON DELETE CASCADE,
	CONSTRAINT Details_emprunt_pk PRIMARY KEY (Numero_emprunt,Nombre_Ouvrage)
);


/* Question 2 Generation automatique de l'ID membre */

CREATE SEQUENCE IDmember_seq START WITH 1 INCREMENT BY 1 NOCYCLE;

/* Question 3 Contrainte de MEMBRE unique */

ALTER TABLE MEMBRE ADD CONSTRAINT Doublon_Membre UNIQUE (Nom,Prenom,Telephone);

/* Question 4 Ajout d'une colonne pour le numero de Portable commençant par "06" */

ALTER TABLE MEMBRE ADD(Portable VARCHAR2(10) CONSTRAINT with06 CHECK (SUBSTR(Portable,1,2) = '06')); 

 
/* Question 5 Suppression de la colonne Telephone pendant les heures de fermeture */

ALTER TABLE MEMBRE DROP CONSTRAINT Doublon_Membre;
ALTER TABLE MEMBRE SET unused (Telephone);

/*ALTER TABLE MEMBRE DROP unused COLUMNS CHECK(select extract(hour from cast(to_char(sysdate, 'DD-MON-YYYY HH24:MI:SS') as timestamp)) from dual > 7  AND select extract(hour from cast(to_char(sysdate, 'DD-MON-YYYY HH24:MI:SS') as timestamp)) from dual < 20);*/


ALTER TABLE MEMBRE ADD CONSTRAINT Doublon_Membre UNIQUE (Nom,Prenom,Portable);


/* Question 6 Generation d'index sur les clefs etrangeres */

CREATE INDEX Index_Genre_in_Ouvrage ON OUVRAGE(Genre);
CREATE INDEX Index_ISBN_in_Exemplaire ON EXEMPLAIRE(ISBN);
CREATE INDEX Index_ID_adherent_in_Emprunt ON EMPRUNTS(ID_adherent);
CREATE INDEX Index_NumEmpr ON DETAILS_EMPRUNTS(Numero_emprunt);
CREATE INDEX Index_NumExamp_ISBNs ON DETAILS_EMPRUNTS(Numero_exemplaire, ISBN);

/* Question 7 Automatisation de la suppression de la ligne DETAILS_EMPRUNTS concerné lors de la suppression de l'emprunt */

ALTER TABLE DETAILS_EMPRUNTS DROP CONSTRAINT Numero_Emprunts;
ALTER TABLE DETAILS_EMPRUNTS ADD CONSTRAINT Numero_Emprunts FOREIGN KEY(Numero_emprunt) REFERENCES EMPRUNTS (Numero_emprunt) ON DELETE CASCADE;

/* Question 8 Etat neuf par défaut pour un nouvel exemplaire */

ALTER TABLE EXEMPLAIRE MODIFY(Etat VARCHAR2(8) DEFAULT 'NE');

/* Question 9 Création d'un alias abonnes pour la table membre */

CREATE SYNONYM ABONNES FOR MEMBRE;

/* Question 10 Renommer la table DETAILSEMPRUNTS en DETAILS */

ALTER TABLE DETAILS_EMPRUNTS RENAME TO DETAILS;

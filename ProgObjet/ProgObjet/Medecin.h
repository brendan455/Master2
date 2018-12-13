// Auteur : DENIAUD B. - AIRAULT D.

#ifndef MEDECIN_H
#define MEDECIN_H
#pragma once
#include "Personne.h"
class Medecin : public Personne
{
	private: // Attribut
		int numeroOrdreMedecin;
		std::string specialite;

	public: // Méthodes
		// Constructeur
		Medecin();
		Medecin(string specialite, int numeroOrdreMedecin, string nom, string prenom, string adresse, bool sexe, int num) : Personne(nom, prenom, adresse, sexe, num) {};
		

		// Accesseurs
		int getnumeroOrdreMedecin();
		void setnumeroOrdreMedecin(int);

		std::string getSpecialite();
		void setSpecialite(std::string);


		// Affichage
		void afficherMedecin();
		//void afficherMedecinFichier(std::string);
};

#endif

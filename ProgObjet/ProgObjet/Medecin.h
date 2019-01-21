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
		Medecin(std::string specialite, int numeroOrdreMedecin, std::string nom, std::string prenom, std::string adresse, bool sexe, int num);
		

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

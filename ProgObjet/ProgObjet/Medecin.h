// Auteur : DENIAUD B. - AIRAULT D.

#ifndef MEDECIN_H
#define MEDECIN_H
#pragma once
#include "Personne.h"
class Medecin
{
	private: // Attribut
		int numeroOrdreMedecin;
		std::string specialite;

	public: // Méthodes
		// Constructeur
		Medecin();
		Medecin(std::string,int) : Personne(std::string, std::string , std::setnomMedecin, bool, int);
		
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

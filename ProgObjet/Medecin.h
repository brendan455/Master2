// Auteur : DENIAUD B. - AIRAULT D.

#ifndef MEDECIN_H
#define MEDECIN_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Medecin
{
	private: // Attribut
		std::string nom;
		std::string prenom;
		int numeroOrdreMedecin;
		std::string specialite;

	public: // Méthodes
		// Constructeur
		Medecin(std::string,std::string,int,std::string);
		
		// Accesseurs
		std::string getnomMedecin();
		void setnomMedecin(std::string);

		std::string getprenomMedecin();
		void setprenomMedecin(std::string);
		
		int getnumeroOrdreMedecin();
		void setnumeroOrdreMedecin(int);

		std::string getSpecialite();
		void setSpecialite(std::string);


		// Affichage
		void afficherMedecin();
		void afficherMedecinFichier(std::string);
};

#endif

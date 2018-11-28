// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Medecin
{
	private: // Attribut
		int ID;
		string nom;
		string prenom;
		int numeroOrdreMedecin;
		string specialite;

	public: // Méthodes
		// Constructeur
		Medecin(string);
		
		// Accesseurs
		int getIDMedecin();
		void setIDMedecin(int);

		string getnomMedecin();
		void setnomMedecin(string);

		string getprenomMedecin();
		void setprenomMedecin(string);
		
		int getnumeroOrdreMedecin();
		void setnumeroOrdreMedecin(int);

		string getSpecialite();
		void setSpecialite(string);


		// Affichage
		void afficherMedecin();
		void afficherMedecinFichier(string);
};

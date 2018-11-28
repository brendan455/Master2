// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Medicament
{
	private: // Attribut
		int ID;
		string nom;
		string laboratoire;

	public: // Méthodes
		// Constructeur
		Medicament(string);
		
		// Accesseurs
		int getIDMedicament();
		void setIDMedicament(int);

		string getnomMedicament();
		void setnomMedicament(string);

		string getlaboratoireMedicament();
		void setlaboratoireMedicament(string);


		// Affichage
		void afficherMedicament();
		void afficherMedicamentFichier(string);
};

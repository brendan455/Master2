// DENIAUD Brendan et AIRAULT David

#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Medicament
{
	private: // Attribut
		string nom;
		string laboratoire;

	public: // Méthodes
		// Constructeur
		Medicament(string);
		
		// Accesseurs
		string getNom();
		void setNom(string);

		string getLaboratoire();
		void setLaboratoire(string);
		
		// Affichage
		void afficherMedicament();
};

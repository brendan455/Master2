// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Gene
{
	private: // Attribut
		string nom;
		string prenom;
		int numeroSecuriteSociale;

	public: // Méthodes
		// Constructeur
		Patient(string);
		
		// Accesseurs
		string getnomPatient();
		void setnomPatient(string);

		string getprenomPatient();
		void setprenomPatient(string);
		
		int getnumeroSecuriteSociale();
		void setnumeroSecuriteSociale(int);

		// Affichage
		void afficherPatient();
		void afficherPatientFichier(string);
};

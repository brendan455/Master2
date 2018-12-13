// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Personne.h"

class Patient : public Personne
{
	private: // Attribut
		int numeroSecuriteSociale;
		char groupeSanguin;

	public: // Méthodes
		// Constructeur
		Patient();
		Patient(int groupe, char numero, string nom, string prenom, string adresse, bool sexe, int num) : Personne(nom, prenom, adresse, sexe, num) {};
		
		// Accesseurs
		int getNumeroSecuriteSociale();
		void setNumeroSecuriteSociale(int);
		char getGroupeSanguin();
		void setGroupeSanguin(char);
		
		// Affichage
		//void afficherPatient();
};

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
		Patient(int numero, char groupe, std::string nom, std::string prenom, std::string adresse, bool sexe, int num);

		// Accesseurs
		int getNumeroSecuriteSociale();
		void setNumeroSecuriteSociale(int);
		char getGroupeSanguin();
		void setGroupeSanguin(char);
		
		// Affichage
		//void afficherPatient();
};

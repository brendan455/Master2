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
		Patient(int,char) : Personne(std::string,std::string,std::string,bool,int);
		// Accesseurs
		int getNumeroSecuriteSociale();
		void setNumeroSecuriteSociale(int);
		char getGroupeSanguin();
		void setGroupeSanguin(char);
		// Affichage
		//void afficherPatient();
};

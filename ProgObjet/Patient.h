// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Patient
{
	private: // Attribut
		std::string nom;
		std::string prenom;
		int numeroSecuriteSociale;
		bool sexe;
		std::string civilite

	public: // Méthodes
		// Constructeur
		Patient(std::string,std::string,int,bool);
		
		// Accesseurs
		std::string getNomPatient();
		void setNomPatient(std::string);

		std::string getPrenomPatient();
		void setPrenomPatient(std::string);
		
		int getNumeroSecuriteSociale();
		void setNumeroSecuriteSociale(int);
	
		bool getSexe();
		void setSexe(bool);
	
		std::string getCivilite();
		void setCivilite(std::string);

		// Affichage
		void afficherPatient();
};

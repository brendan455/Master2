// Auteur : DENIAUD B. - AIRAULT D.

#ifndef PERSONNE_H
#define PERSONNE_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Personne {
	protected :
		std::string nom; 
		std::string prenom;
		std::string adresse;
		int numeroDeTelephone;
		bool sexe;
	public :
		//Constructeur
		Personne();
		Personne(std::string, std::string, std::string, bool, int);

		//Accesseurs
		std::string getNom();
		std::string getPrenom();
		std::string getAdresse();
		bool getSexe();
		int getNumeroDeTelephone();

		void setNumeroDeTelephone(int);
		void setNom(std::string);
		void setPrenom(std::string);
		void setAdresse(std::string);
		void setSexe(bool);


};
#endif
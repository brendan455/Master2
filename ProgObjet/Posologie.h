// DENIAUD Brendan et AIRAULT David

#ifndef POSOLOGIE_H
#define POSOLOGIE_H
#pragma once
#include <iostream>
#include <string>

class Posologie
{
	private: // Attribut
		int nombreDePrises;
		std::string jsm;
		std::string temps;

	public: // Méthodes
		// Constructeur
		Posologie(int,std::string,std::string);
		
		// Accesseurs
		int getNbPrise();
		void setNbPrise(int);
		std::string getJSM();
		void setJSM(std::string);
		std::string getTemps();
		void setTemps(std::string);
			
		// Affichage
		void afficherPosologie();
};

#endif




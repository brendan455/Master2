// DENIAUD Brendan et AYRAULT David

#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Posologie
{
	private: // Attribut
		int nombreDePrises;

	public: // Méthodes
		// Constructeur
		Posologie(int);
		
		// Accesseurs
		int getPosologie();
		void setPosologie(int);
		
		// Affichage
		void afficherPosologie();
};

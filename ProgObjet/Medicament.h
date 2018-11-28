// Auteur : DENIAUD B. - AIRAULT D.

#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Medicament
{
	private: // Attribut
		int ID;
		std::string nom;
		std::string laboratoire;
		
	
	
		void setIDMedicament(int);
	
	public: // Méthodes
		// Constructeur
		Medicament(std::string);
		
		// Accesseurs
		int getIDMedicament();

		std::string getnomMedicament();
		void setnomMedicament(string);

		std::string getlaboratoireMedicament();
		void setlaboratoireMedicament(string);


		// Affichage
		void afficherMedicament();
		void afficherMedicamentFichier(string);
};

#endif

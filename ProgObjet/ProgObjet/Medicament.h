// Auteur : DENIAUD B. - AIRAULT D.

#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Medicament {
	private: // Attribut
		std::string nom;
		std::string laboratoire;
		
	
	public: // Méthodes
		// Constructeur
		Medicament();
		Medicament(std::string,std::string);
		
		// Accesseurs
		std::string getnomMedicament();
		void setnomMedicament(std::string);

		std::string getlaboratoireMedicament();
		void setlaboratoireMedicament(std::string);

		/*
		// Affichage
		void afficherMedicament();
		void afficherMedicamentFichier(string);
		*/
};

#endif

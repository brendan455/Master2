// Auteur : DENIAUD B. - AIRAULT D.

#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Prescription.h"

class Medicament : public Prescription
{
	private: // Attribut
		std::string nom;
		std::string laboratoire;
		
	
	public: // Méthodes
		// Constructeur
		Medicament(std::string);
		
		// Accesseurs
		std::string getnomMedicament();
		void setnomMedicament(string);

		std::string getlaboratoireMedicament();
		void setlaboratoireMedicament(string);

		// Affichage
		void afficherMedicament();
		void afficherMedicamentFichier(string);
};

#endif

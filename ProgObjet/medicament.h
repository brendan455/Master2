// DENIAUD Brendan et AIRAULT David
#ifndef MEDICAMENT_H
define MEDICAMENT_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>


namespace Med
class Medicament
{
	private: // Attribut
		std::string nom;
		std::string laboratoire;

	public: // Méthodes
		// Constructeur
		Medicament(std::string,std::string);
		
		// Accesseurs
		std::string getNom();
		void setNom(std::string);
		string getLaboratoire();
		void setLaboratoire(string);
		
		// Comportement
		void afficherMedicament();
};

#endif

// DENIAUD Brendan et AIRAULT David

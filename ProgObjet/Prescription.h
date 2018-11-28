// Auteur : DENIAUD B. - AIRAULT D.

#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H
#pragma once
#include <iostream>
#include <string.h>
#include <fstream>



class Prescription
{
	private: // Attributs
		std::string typeDePrescripiton
		Posologie posologie
		Date dateDePrescription


	public: // Méthodes
		// Constructeur
		Prescription(std::string,Posologie,dateDePrescription);
		
	
		// Accesseurs
		std::string setTypePrescription();
		void getTypePrescription();
		Posologie setPosologie();
		void getPosologie();
		Date setDate();
		void getDate();
	
		// Affichage
		void afficherPrescription();
		
		
		
};

#endif

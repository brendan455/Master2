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
		Prescription(std::string,Posologie,Date);
		
	
		// Accesseurs
		std::string setTypePrescription();
		void getTypePrescription();
		Posologie setPosologie();
		void getPosologie();
		Date setDatePrescription();
		void getDatePrescription();
	
		// Affichage
		void afficherPrescription();
		
		
		
};

#endif

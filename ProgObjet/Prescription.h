// Auteur : DENIAUD B. - AIRAULT D.

#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H
#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include "Posologie.h"
#include "Date.h"



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
		void getTypePrescription(std::string);
		Posologie setPosologie();
		void getPosologie(Posologie);
		Date setDatePrescription();
		void getDatePrescription(Date);
	
		// Affichage
		void afficherPrescription();
		
		
		
};

#endif

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
		std::string getTypePrescription();
		void setTypePrescription(std::string);
		Posologie getPosologie();
		void setPosologie(Posologie);
		Date getDatePrescription();
		void setDatePrescription(Date);
	
		// Affichage
		void afficherPrescription();
		
		
		
};

#endif

// Auteur : DENIAUD B. - AIRAULT D.

#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "Posologie.h"
#include "Date.h"
#include "Medicament.h"



class Prescription
{
	protected: // Attributs
		std::string typeDePrescripiton;
		Posologie posologie;
		Date dateDePrescription;
		std::list<Medicament> medicaments;


	public: // Méthodes
		// Constructeur
		Prescription();
		Prescription(std::string,Posologie,Date, std::list<Medicament>);

	
		// Accesseurs
		std::string getTypePrescription();
		void setTypePrescription(std::string);
		std::list<Medicament> getMedicaments();
		void setMedicaments(std::list<Medicament>);
		Posologie getPosologie();
		void setPosologie(Posologie);
		Date getDatePrescription();
		void setDatePrescription(Date);
	
		// Affichage
/*		void afficherPrescription();
		
	*/	
		
};

#endif

// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "Prescription.h"
#include "Medecin.h"
#include "Date.h"

class RDV
{
	private: // Attributs
		Medecin medecin;
		std::list<Prescription> prescriptions;
		Date dateRdv;
		int ID;


	public: // Méthodes
		RDV();
		RDV(Medecin, std::list<Prescription>, Date, int);
		RDV(Medecin, Date, int);


		
		
		// Accesseurs
		void setMedecin(Medecin);
		Medecin getMedecin();
		void setPrescriptions(std::list<Prescription>);
		std::list<Prescription> getPrescriptions();
		void setDateRdv(Date);
		Date getDateRdv();
		int getID();
		void setID(int);
	
		// Affichage
		void afficherBilanRdv();
};

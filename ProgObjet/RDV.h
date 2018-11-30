// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "Prescription.h"
#include "Medecin.h"
#include "Date.h"
using namespace std;

class RDV
{
	private: // Attributs
		Medecin medecin
		List(Prescription) prescriptions
		Date dateRdv


	public: // Méthodes
		RDV(Medecin,List(Prescription),Date);
		
		// Accesseurs
		void setMedecin(Medecin):
		Medecin getMedecin();
		void setPrescriptions(List(Prescription));
		List(Prescription) getPrescriptions();
		void setDateRdv(Date);
		Date getDateRdv();
	
		// Affichage
		void afficherBilanRdv();
};

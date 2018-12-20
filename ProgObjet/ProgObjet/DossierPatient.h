// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "Patient.h"
#include "RDV.h"

class DossierPatient
{
	private: // Attributs
		std::list<RDV> rdvs;
		Patient patient;


	public: // Méthodes
		// Constructeur
		DossierPatient();
		DossierPatient(Patient);
		DossierPatient(std::list<RDV>,Patient);
		
		// Affichage
		void afficherDossierPatient();
		
		// Accesseurs
		void setPatient(Patient);
		Patient getPatient();
		void setRdvs(std::list<RDV>);
		std::list<RDV> getRdvs();
};

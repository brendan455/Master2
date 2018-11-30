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
		int numeroDossier;
		list<RDV> rendezVous;
		Patient patient;

	public: // Méthodes
		// Constructeur
		DossierPatient(int,list<RDV>,Patient);
		
		// Accesseurs
		int getNumeroDossier();
		void setNumeroDossier(int);
		Patient getPatient();
		void setPatient(Patient);
		list<RDV> getRendezVous();
		void setRendezVous(list<RDV>);
	
		// Affichage
		void afficherDossierPatient();
		
};

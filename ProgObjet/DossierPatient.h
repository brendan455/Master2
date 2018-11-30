// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "Patient.h"

class DossierPatient
{
	private: // Attributs
		int ID;
		Type type;
		Patient listofpatients;


	public: // Méthodes
		// Constructeur
		DossierPatient(int,string);
		
		// Affichage
		void afficherDossierPatient();
		void afficherSelonnomPatient(string);
		
		// Accesseurs
		int getID();
		int TrouverDossier();
		void setDossierPatient(vector<Patient>);
		void setIDDossierPatient(int);
		vector<Patient> getNomPatientDossierPatient();
};

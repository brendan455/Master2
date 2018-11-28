// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include "Patient.h"
using namespace std;



class DossierPatient
{
	private: // Attributs
		int ID;
		Type type;
		vector<Patient> listofpatients;


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

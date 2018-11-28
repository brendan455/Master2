// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include "Patient.h"
#include "Medecin.h"
#include "Date.h"
using namespace std;



class RDV
{
	private: // Attributs
		vector<Medecin> listofmedecins;
		vector<Patient> listofpatients;
		vector<Date> dateRDV;


	public: // Méthodes
		
		// Affichage
		void afficherRDVPatient(string);
		void afficherRDVMedecin(string);
		void afficherRDVDate(int);
		
		// Accesseurs
		vector<Patient> getNomPatient();
		vector<Medecin> getNomMedecin();
		vector<Date> getDate();

		void setRDVPatient(vector<Patient>);
		void setRDVMedecin(vector<Medecin>);
		void setRDVDate(vector<Date>);

};

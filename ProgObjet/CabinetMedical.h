// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Patient.h"
#include "Medecin.h"
#include "DossierPatient.h"
using namespace std;

class CabinetMedical:{

	public: // Méthodes
		// Constructeur
		CabinetMedical(string);

	private: // Attributs
		string nomCabinet;
		string adresse;
		vector<DossierPatient> listofdossiers;
		vector<Medecin> listofmedecins;
		vector<Patient> listofpatients;
		
		// Affichage
		void afficherCabinetMedical();
		
		// Ajouter un objet DossierPatient
		vector<DossierPatient> ajouterDossierPatient(string);

		// Ajouter un objet Medecin
		vector<Medecin> ajouterMedecin(string);

		// Ajouter un objet Patient
		vector<Patient> ajouterPatient(string);
};

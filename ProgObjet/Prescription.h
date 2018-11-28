// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include "Patient.h"
#include "Medecin.h"
#include "Posologie.h"
using namespace std;



class Prescription
{
	private: // Attributs
		int ID;
		string typeDePrescription;
		vector<Patient> nom_patient;
		vector<Posologie> dateDebut;
		vector<Posologie> dateFin;
		vector<Medecin> nom_medecin;
		vector<Posologie> nombrePrisesJour;


	public: // Méthodes
		// Constructeur
		Prescription(int,string);
		
		// Affichage
		void afficherPrescription();
		
		// Accesseurs
		int getIDPrescription();
		int TrouverPrescription();
		vector<Patient> getnomPatientPrescription();
		vector<Medecin> getnomMedecinPrescription();
		vector<Posologie> getdateDebutPrescription();
		vector<Posologie> getdateFinPrescription();
		vector<Posologie> getPosologiePrescription();
		void setIDPrescription(int);
		void setnomPatientPrescription(string);
		void setnomMedecinPrescription(string);
		void setdateDebutPrescription(int);
		void setIDPrescription(int);
		void setnombrePrisesJourPrescription(int);
};

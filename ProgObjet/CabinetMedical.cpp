// Auteur : DENIAUD B. - AIRAULT D.

#include "CabinetMedical.h"
#include <iostream> 
#include <string>
using namespace std;

// Code du contructeur de la classe CabinetMedical
CabinetMedical::CabinetMedical(string nomCabinet, string adresse, vector<DossierPatient> listofdossiers, vector<Medecin> listofmedecins, vector<Patient> listofpatients){
	this->nomCabinet=nomCabinet;
	this->adresse=adresse;
	ajouterDossierPatient(ID, nom_patient);
	ajouterMedecin(ID,nom_medecin,prenom_medecin,numeroOrdreMedecin,specialite);
}


// Affichage d'un objet de type CabinetMedical
void CabinetMedical::afficherCabinetMedical(){
	cout << "~~~ Le cabinet medical est : " << this->nomCabinet  << " et est situé à l'adresse :" << this->adresse <<  endl;	
}


// Lien entre CabinetMedical et un objet de type DossierPatient
vector<DossierPatient> CabinetMedical::ajouterDossierPatient(string nom_patient){
	vector<DossierPatient>::iterator it; int my_ID;
    for (it = this->DossierPatient.begin(); it != this->DossierPatient.end(); ++it) { 
		my_ID=it->getID();
		if(my_ID==ID){ // Parcourir les DossierPatient pour trouver si il existe déjà, dans ce cas rien faire
			cout << "~~~  Le dossier existe déjà \n";
			return this->nom_patient;
		}
	}
	DossierPatient p1(ID,nom_patient); // Création d'un objet de type DossierPatient
	this->nom_patient.push_back(p1);
	return this->nom_patient;
}


// Lien entre CabinetMedical et un objet de type Medecin
vector<Medecin> CabinetMedical::ajouterMedecin(string nom_medecin){
	vector<Medecin>::iterator it; int my_ID;
    for (it = this->Medecin.begin(); it != this->Medecin.end(); ++it) { 
		my_ID=it->getID();
		if(my_ID==ID){ // Parcourir les Medecin pour trouver si il existe déjà, dans ce cas rien faire
			cout << "~~~  Le medecin existe déjà \n";
			return this->nom_medecin;
		}
	}
	Medecin m1(ID,nom_medecin,prenom_medecin,numeroOrdreMedecin,specialite); // Création d'un objet de type Medecin
	this->nom_medecin.push_back(m1);
	return this->nom_medecin;
}


// Lien entre CabinetMedical et un objet de type Patient
vector<Patient> DossierPatient::ajouterPatient(string nom_patient){
	vector<Patient>::iterator it; int my_ID;
    for (it = this->Patient.begin(); it != this->Patient.end(); ++it) { 
		my_ID=it->getID();
		if(my_ID==ID){ // Parcourir les Patient pour trouver si il existe déjà, dans ce cas rien faire
			cout << "~~~  Le patient existe déjà \n";
			return this->nom_patient;
		}
	}
	Patient p1(ID,nom_patient,prenom_patient,numeroSecuriteSociale); // Création d'un objet de type Patient
	this->nom_patient.push_back(p1);
	return this->nom_patient;
}

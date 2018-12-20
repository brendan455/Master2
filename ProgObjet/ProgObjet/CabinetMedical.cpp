// Auteur : DENIAUD B. - AIRAULT D.




#include "CabinetMedical.h"
#include <iostream> 
#include <string>

using namespace std;

CabinetMedical::CabinetMedical() {}
CabinetMedical::CabinetMedical(int test){
	CabinetMedical::setNomCabinet("null");
};

// Code du contructeur de la classe CabinetMedical
CabinetMedical::CabinetMedical(string nomCabinet, string adresse, list<Medecin> medecins, list<DossierPatient> dossiersPatient) {
	CabinetMedical::setNomCabinet(nomCabinet);
	CabinetMedical::setAdresseCabinet(adresse);
	CabinetMedical::setMedecins(medecins);
	CabinetMedical::setDossiersPatient(dossiersPatient);
};


// Accesseurs
string CabinetMedical::getNomCabinet() {
	return this->nomCabinet;
};

void CabinetMedical::setNomCabinet(string nomCabinet) {
	this->nomCabinet = nomCabinet;
};

string CabinetMedical::getAdresseCabinet() {
	return this->adresse;
}
void CabinetMedical::setAdresseCabinet(std::string adresse)
{
	this->adresse = adresse;
};


list<DossierPatient> CabinetMedical::getDossiersPatient() {
	return this->dossiersPatient;
};

void CabinetMedical::setDossiersPatient(std::list<DossierPatient> dossiersPatient) {
	this->dossiersPatient = dossiersPatient;
};

list<Medecin> CabinetMedical::getMedecins() {
	return this->medecins;
};

void CabinetMedical::setMedecins(std::list<Medecin> medecins) {
	this->medecins = medecins;
};

/*
// Affichage d'un objet de type CabinetMedical
void CabinetMedical::afficherNomAdresseCabinetMedical() {
	cout << "~~~ Le cabinet medical est : " << this->nomCabinet << " et est situé à l'adresse :" << this->adresse << endl;
}


// Lien entre CabinetMedical et un objet de type Medecin
list<Medecin> CabinetMedical::ajouterMedecin(string nom_medecin) {
	list<Medecin>::iterator it; int my_ID;
	for (it = this->Medecin.begin(); it != this->Medecin.end(); ++it) {
		my_ID = it->getID();
		if (my_ID == ID) { // Parcourir les Medecin pour trouver si il existe déjà, dans ce cas rien faire
			cout << "~~~  Le medecin existe déjà \n";
			return this->nom_medecin;
		}
	}
	Medecin m1(nom_medecin, prenom_medecin, numeroOrdreMedecin, specialite); // Création d'un objet de type Medecin
	this->nom_medecin.push_back(m1);
	return this->nom_medecin;
}


// Lien entre CabinetMedical et un objet de type Patient
list<Patient> DossierPatient::ajouterPatient(string nom_patient) {
	list<Patient>::iterator it; int my_ID;
	for (it = this->Patient.begin(); it != this->Patient.end(); ++it) {
		my_ID = it->getID();
		if (my_ID == ID) { // Parcourir les Patient pour trouver si il existe déjà, dans ce cas rien faire
			cout << "~~~  Le patient existe déjà \n";
			return this->nom_patient;
		}
	}
	Patient p1(nom_patient, prenom_patient, numeroSecuriteSociale); // Création d'un objet de type Patient
	this->nom_patient.push_back(p1);
	return this->nom_patient
};
*/

// Auteur : DENIAUD B. - AIRAULT D.

#include "Prescription.h"
#include <iostream> 
#include <string>
using namespace std;


// Initialisation du compteur pour la numérotation des objets de type DossierPatient
int Prescription::compteur=0;

// Code du contructeur de DossierPatient
Prescription::Prescription(int ID, string typeDePrescription, vector<Patient> nom_patient, vector<Posologie> dateDebut, vector<Posologie> dateFin, vector<Medecin> nom_medecin, vector<Posologie> nombrePrisesJour){
	this->ID=this->compteur;
	this->typeDePrescription=typeDePrescription;
	ajouternomPatient(nom_patient);
	ajouterPoslogie(dateDebut);
	ajouterPoslogie(dateFin);
	ajouternomMedecin(nom_medecin);
	ajouterPosologie(nombrePrisesJour);
	this->compteur=this->compteur+1;
}


// Affichage d'un objet de type DossierPatient
void DossierPatient::afficherPrescription(){
	cout << "	- La prescription porte le N° : " << this->ID <<" le nom du patient est : " << this->nom_patient << " La date de début du traitement est le : " << this->dateDebut << " La date de fin de traitement est : " << this->dateFin << " Le medecin préscripteur est : " << this->nom_medecin << " La poslogie du traitement est (nombres de prises / jour) : " << this->nombrePrisesJour << endl;
}


// Obtenir un ID de Prescription
int Prescription::getIDPrescription(){
	return this->ID;
}

// Trouver un objet DossierPatient en fonction d'un ID passé en paramètre
int Prescription::TrouverPrescription(int ID){
	int i, ID;
	i = Prescriptiont::getIDPrescription();
	if (i == ID){
		return 1; // Si on trouve un objet correspondant à l'ID, on renvoie 1
	}
	return 0; // Aucun objet trouvé
}

// Obtenir un nom de patient de Prescription
string Prescription::getnomPatientPrescription(){
	return this->nom_patient;
}

// Obtenir un nom de medecin de Prescription
string Prescription::getnomMedecinPrescription(){
	return this->nom_medecin;
}

// Obtenir un date de début de Prescription
int Prescription::getdateDebutPrescription(){
	return this->dateDebut;
}

// Obtenir un date de fin de Prescription
int Prescription::getdateFinPrescription(){
	return this->dateFin;
}

// Obtenir un posologie de Prescription
int Prescription::getPosologiePrescription(){
	return this->poslogie;
}


// Changer l'ID d'un objet Prescription
void Prescription::setIDPrescription(int ID){ 
	this->ID=ID;
}

// Changer le nom d'un patient d'un objet Prescription
void Prescription::setnomPatientPrescription(string nom_patient){ 
	this->nom_patient=nom_patient;
}

// Changer le nom d'un medecin d'un objet Prescription
void Prescription::setnomMedecinPrescription(string nom_medecin){ 
	this->nom_medecin=nom_medecin;
}

// Changer la date de debut de traitement d'un objet Prescription
void Prescription::setdateDebutPrescription(int dateDebut){ 
	this->dateDebut=dateDebut;
}

// Changer la date de fin de traitement d'un objet Prescription
void Prescription::setIDPrescription(int dateFin){ 
	this->dateFin=dateFin;
}

// Changer le nombre de prises/jour d'un objet Prescription
void Prescription::setnombrePrisesJourPrescription(int nombrePrisesJour){ 
	this->nombrePrisesJour=nombrePrisesJour;
}


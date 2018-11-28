// Auteur : DENIAUD B. - AIRAULT D.

#include "RDV.h"
#include <iostream> 
#include <string>
using namespace std;


// Code du contructeur de RDV
RDV::RDV(vector<Medecin> nom_medecin, vector<Patient> nom_patient, vector<Date> dateRDV){
	ajouterMedecin(nom_medecin);
	ajouterPatient(nom_patient);
	ajouterDate(dateRDV);
}


// Affichage d'un objet de type RDV
void RDV::afficherRDVPatient(){
	string nom_patient;
	cout << "	- Le rendez-vous du patient : "<< this->nom_patient << endl;	
	vector<Patient>::iterator it;
    for (it = this->listofpatients.begin(); it != this->listofpatients.end(); ++it) {
        it->affichernomPatient(); // Afficher les noms de DossierPatient
    }
}

void RDV::afficherRDVMedecin(){
	string nom_medecin;
	cout << "	- Le rendez-vous du medecin : "<< this->nom_medecin << endl;	
	vector<Medecin>::iterator it;
    for (it = this->listofmedecins.begin(); it != this->listofmedecins.end(); ++it) {
        it->affichernomMedecin(); // Afficher les noms de DossierPatient
    }
}

void RDV::afficherRDVDate(){
	int dateRDV;
	cout << "	- Le rendez-vous est programmé pour le : "<< this->dateRDV << endl;	
	vector<Date>::iterator it;
    for (it = this->listofdates.begin(); it != this->listofdates.end(); ++it) {
        it->display2(); // Afficher les noms de DossierPatient
    }
}


// Récupérer les noms d'un objet RDV
vector<Patient> RDV::getNomPatient(){ 
	return this->listofpatients;
}

// Récupérer les noms d'un objet DossierPatient
vector<Medecin> RDV::getNomMedecin(){ 
	return this->listofmedecins;
}

// Récupérer les noms d'un objet DossierPatient
vector<Date> RDV::getDate(){ 
	return this->dateRDV;
}


// Changer les patients d'un objet DossierPatient
void RDV::setRDVPatient(vector<Patient> listofpatients){ 
	this->listofpatients=listofpatients;
}

// Changer l'ID d'un objet DossierPatient
void RDV::setRDVMedecin(vector<Medecin> listofmedecins){ 
	this->listofmedecins=listofmedecins;
}

// Changer l'ID d'un objet DossierPatient
void RDV::setRDVDate(vector<Date> dateRDV){ 
	this->dateRDV=dateRDV;
}


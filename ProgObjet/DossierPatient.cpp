// Auteur : DENIAUD B. - AIRAULT D.

#include "DossierPatient.h"
#include <iostream> 
#include <string>
using namespace std;


// Initialisation du compteur pour la numérotation des objets de type DossierPatient
int DossierPatient::compteur=0;

// Code du contructeur de DossierPatient
DossierPatient::DossierPatient(vector<Patient> nom_patient){
	this->ID=this->compteur;
	ajouterPatient(nom_patient);
	this->compteur=this->compteur+1;
}


// Affichage d'un objet de type DossierPatient
void DossierPatient::afficherDossierPatient(){
	string nom_patient;
	cout << "	- Le dossier patient N°"<< this->ID <<" est le dossier de " << nom_patient << endl;	
	vector<Patient>::iterator it;
    for (it = this->listofpatients.begin(); it != this->listofpatients.end(); ++it) {
        it->affichernomPatient(); // Afficher les noms de DossierPatient
    }
}

// Obtenir les noms de DossierPatient
int DossierPatient::afficherSelonnomPatient(string nom_patient){ // Récupérer nom des DossierPatient
	vector<Patient>::iterator it;  string nom_patient;
    for (it = this->listofpatients.begin(); it != this->listofpatients.end(); ++it) {
        nom_patient=it->getnomPatient();
		if(nom.compare(nom_patient)==0){ // si le nom est dans le DossierPatient, retourner 1
			return 1;
		}
    } // Cas où nom ne fait pas parti des DossierPatient : renvoyer 0
	return 0;
}

// Obtenir un ID de DossierPatient
int DossierPatient::getID(){
	return this->ID;
}

// Trouver un objet DossierPatient en fonction d'un ID passé en paramètre
int DossierPatient::TrouverDossier(int ID){
	int i, ID;
	i = DossierPatient::getIDDossierPatient();
	if (i == ID){
		return 1; // Si on trouve un objet correspondant à l'ID, on renvoie 1
	}
	return 0; // Aucun objet trouvé
}


// Changer les patients d'un objet DossierPatient
void DossierPatient::setDossierPatient(vector<Patient> listofpatients){ 
	this->listofpatients=listofpatients;
}

// Changer l'ID d'un objet DossierPatient
void DossierPatients::setIDDossierPatient(int ID){ 
	this->ID=ID;
}


// Récupérer les noms d'un objet DossierPatient
vector<Patient> DossierPatient::getNomPatientDossierPatient(){ 
	return this->listofpatients;
}

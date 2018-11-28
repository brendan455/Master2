// Auteur : DENIAUD B. - AIRAULT D.

#include "Patient.h"
#include <iostream> 
using namespace std;


// Initialisation du compteur pour la numérotation des objets de type Patient
int Patient::compteur=0;

// Constructeur de Patient
Patient::Patient(string nom, string prenom, int numeroSecuriteSociale){
	this->ID=this->compteur; 
	this->nom=nom;
	this->prenom=prenom;
	this->numeroSecuriteSociale=numeroSecuriteSociale;
	this->compteur=this->compteur+1;
}

// Accesseurs
string Patient::getnomPatient(){ // Récupérer les noms de l'objet Patient
	return this->nom;
}

string Patient::getprenomPatient(){ // Récupérer les prénoms de l'objet Patient
	return this->prenom;
}

int Patient::getnumeroSecuriteSociale(){ // Récupérer les numéros de sécurité sociale d'un objet Patient
	return this->numeroSecuriteSociale;
}

void Patient::setnomPatient(string nom){ // Changer un nom d'un objet Patient
	this->nom=nom;
}

void Patient::setprenomPatient(string prenom){ // Changer un prénom d'un objet Patient
	this->prenom=prenom;
}

void Patient::setnnumeroSecuriteSociale(int numeroSecuriteSociale){ // Changer un numéro de sécurité sociale d'un objet Patient
	this->numeroSecuriteSociale=numeroSecuriteSociale;
}

// Affichage d'un objet de type Patient
void Medicament::afficherPatient(){
	cout << "	- L'ID du patient est : "<< this->ID <<" Le nom du patient est : " << this->nom_patient << "Le prénom du patient est : " << this->prenom_patient << "Le numéro de sécurité sociale du patient est : " << this->numeroSecuriteSociale << endl;	
}


// Enregistrer un objet de type Patient dans un fichier
void Patient::afficherPatientFichier(string nomFichier){
	ofstream outputFile(nomFichier.c_str(), ios::app); // Ouvrir le fichier
	if(outputFile){ // Si l'ouverture a fonctionnée, écrire à la suite le nom du patient
		outputFile << "		* Le patient est : " << this->nom << endl;
		outputFile.close(); // Fermer le fichier
	}
}

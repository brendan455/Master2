// DENIAUD Brendan et AYRAULT David

#include "patient.h"

//Initialisation d'un compteur pour l'identification des objets de type patient.
int Patient::compteur=0

//Constructeurs
Patient::Patient(int ID, string nom, string prenom, int numeroDeSecuriteSociale, Date dateDeNaissance){
	this->ID=this->compteur;
	this->nom=nom;
	this->prenom=prenom;
	this->numeroDeSecuriteSociale=numeroDeSecuriteSociale;
	this->dateDeNaissance=dateDeNaissance;
	this->compteur=this->compteur+1;
}

//Affichage d'un objet de type Patient
void Patient::afficherNomPatient(){
	std::count << " Le nom du patient est : " << this->nom << endl;
}

void Patient::afficherPrenomPatient(){
	std::count << " Le prenom du patient est : " << this->prenom << endl;
}

void Patient::afficherNumeroSecuPatient(){
	std::count << " Le numéro de sécurité sociale du patient est : " << this->numeroDeSecuriteSociale << endl;
}

void Patient::afficherNDatePatient(){
	std::count << " La date de naissance du patient est : " << this->dateDeNaissance << endl;
}

//Accesseurs
int Patient::getCompteur(){
	return this->compteur;
}

void Patient::setIDPatient(int ID){
	this->ID=ID;
}

int Patient::getIDPatient(){
	return this->ID;
}

void Proteine::setNomPatient(string nom){
	this->nom=nom;
}

string Proteine::getNomPatient(){
	return this->nom;
}

void Proteine::setPrenomPatient(string prenom){
	this->prenom=prenom;
}

string Proteine::getPrenomPatient(){
	return this->prenom;
}

void Proteine::setNumeroDeSecuriteSocialePatient(int numeroDeSecuriteSociale){
	this->numeroDeSecuriteSociale=numeroDeSecuriteSociale;
}

int Proteine::getNumeroDeSecuriteSocialePatient(){
	return this->numeroDeSecuriteSociale;
}


// Auteur : DENIAUD B. - AIRAULT D.

#include "Patient.h"
#include <iostream> 
using namespace std;


// Constructeur de Patient
Patient::Patient(string nom, string prenom, int numeroSecuriteSociale, bool sexe){
	Patient::setNomPatient(nom);
	Patient::setPrenomPatient(prenom);
	Patient::setNumeroSecuriteSociale(numeroSecuriteSociale);
	Patient::setSexe(sexe);
	if getSexe(){
		Patient::setCivilite("Monsieur");
	}
	else {
		Patient::setCivilite("Madame");
	}
};

// Accesseurs
string Patient::getNomPatient(){ // Récupérer les noms de l'objet Patient
	return this->nom;
};

string Patient::getPrenomPatient(){ // Récupérer les prénoms de l'objet Patient
	return this->prenom;
};

int Patient::getNumeroSecuriteSociale(){ // Récupérer les numéros de sécurité sociale d'un objet Patient
	return this->numeroSecuriteSociale;
};
bool Patient::getSexe(){
	return this->sexe;
};
string Patient::getCivilite(){
	return this->civilite;
};

void Patient::setSexe(bool sexe){
	this->sexe=sexe;
};

void Patient::setNomPatient(string nom){ // Changer un nom d'un objet Patient
	this->nom=nom;
};

void Patient::setPrenomPatient(string prenom){ // Changer un prénom d'un objet Patient
	this->prenom=prenom;
};

void Patient::setNumeroSecuriteSociale(int numeroSecuriteSociale){ // Changer un numéro de sécurité sociale d'un objet Patient
	this->numeroSecuriteSociale=numeroSecuriteSociale;
};

void Patient::setCivilite(string civilite){
	this->civilite=civilite;
};

// Affichage d'un objet de type Patient
void Medicament::afficherPatient(){
	string sexe;

	if (Patient::getSexe()) {
		sexe = "une femme";
	}
	else {
		sexe = "un homme";
	}
	cout << "	-  Le patient est " << sexe << "," << Patient::getCivilite() << Patient::getNomPatient() << Patient::getPrenomPatient() << "." << "Son numéro de sécurité sociale du patient est le " << Patient::getNumeroSecuriteSociale() << endl;	
}

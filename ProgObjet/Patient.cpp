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
void Patient::setSexe(bool sexe){
	thise->sexe=sexe;
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

// Affichage d'un objet de type Patient
void Medicament::afficherPatient(){
	string sexe;
	string civil;
	if (Patient::getSexe()) {
		sexe = "une femme";
		civil = "Madame";
	}
	else {
		sexe = "un homme";
		civil = "Monsieur";
	}
	cout << "	-  Le patient est " << sexe << "," << civil << Patient::getNomPatient() << Patient::getPrenomPatient() << "." << "Son numéro de sécurité sociale du patient est le " << Patient::getNumeroSecuriteSociale() << endl;	
}

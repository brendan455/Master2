// Auteur : DENIAUD B. - AIRAULT D.

#include "Patient.h"
#include <iostream> 
using namespace std;


// Constructeur de Patient
Patient::Patient() {};
Patient::Patient(int numero, char groupe, string nom, string prenom, string adresse, bool sexe, int num) : Personne(nom,prenom,adresse,sexe,num) {
	Patient::setGroupeSanguin(groupe);
	Patient::setNumeroSecuriteSociale(numero);
};


// Accesseurs

int Patient::getNumeroSecuriteSociale(){ 
	return this->numeroSecuriteSociale;
};
char Patient::getGroupeSanguin(){
	return this->groupeSanguin;
};
void Patient::setNumeroSecuriteSociale(int numeroSecuriteSociale){ 
	this->numeroSecuriteSociale = numeroSecuriteSociale;
};
void Patient::setGroupeSanguin(char groupe){
	this->groupeSanguin = groupe;
};


/*
// Affichage d'un objet de type Patient
void Patient::afficherPatient(){
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
*/
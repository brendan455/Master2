//Auteur: DENIAUD B. - AIRAULT D.

#include "Personne.h"

using namespace std;

//Constructeur
Personne::Personne() {};
Personne::Personne(string nom, string prenom, string adresse, bool sexe , int num) {
	Personne::setNom(nom);
	Personne::setPrenom(prenom);
	Personne::setAdresse(adresse);
	Personne::setSexe(sexe);
	Personne::setNumeroDeTelephone(num);

};

//Accesseurs
string Personne::getNom() {
	return this->nom;
};
string Personne::getPrenom() {
	return this->prenom;
};
string Personne::getAdresse() {
	return this->adresse;
};
bool Personne::getSexe() {
	return this->sexe;
};
int Personne::getNumeroDeTelephone() {
	return this->numeroDeTelephone;
};
void Personne::setNumeroDeTelephone(int num) {
	this->numeroDeTelephone = num;
};
void Personne::setNom(string nom) {
	this->nom = nom;
};
void Personne::setPrenom(string prenom) {
	this->prenom = prenom;
};
void Personne::setAdresse(string adresse) {
	this->adresse = adresse;
};
void Personne::setSexe(bool sexe) {
	this->sexe = sexe;
};
// DENIAUD Brendan et AYRAULT David

#include "medicament.h"
#include <iostream> 
using namespace std;

// Constructeur de Gene
Medicament::Medicament(string nom, string laboratoire){ 
	this->nom=nom;
	this->laboratoire=laboratoire;
}

// Accesseurs
string Medicament::getNom(){
	return this->nom;
}

void Medicament::setNom(string nom){
	this->nom=nom;
}

string Medicament::getLaboratoire(){
	return this->laboratoire
}

void Medicament::setLaboratoire(string laboratoire){
	this->laboratoire=laboratoire;
}

// Affichage d'un objet de type Medicament
void Gene::afficherMedicament(){
	cout << "Le médicament est : " << this->nom << endl;
	cout << "Le médicament est produit par le laboratoire : " << this->laboratoire << endl;	
}


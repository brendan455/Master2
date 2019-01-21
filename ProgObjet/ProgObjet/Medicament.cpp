// Auteur : DENIAUD B. - AIRAULT D.


#include "Medicament.h"
#include <iostream> 
using namespace std;


Medicament::Medicament() {};

// Constructeur de Medicament
Medicament::Medicament(string nom, string laboratoire){
	Medicament::setnomMedicament(nom);
	Medicament::setlaboratoireMedicament(laboratoire);
}


// Accesseurs
string Medicament::getnomMedicament(){
	return this->nom;
};

string Medicament::getlaboratoireMedicament(){
	return this->laboratoire;
};


void Medicament::setnomMedicament(string nom){
	this->nom=nom;
};

void Medicament::setlaboratoireMedicament(string laboratoire){
	this->laboratoire=laboratoire;
};

// DENIAUD Brendan et AYRAULT David

#include "Posologie.h"
?#include <list> ?
#include <iostream> 
using namespace std;

// Constructeur de Gene
Posologie::Posologie(int nombreDePrises, string methode){ 
	this->nombreDePrises=nombreDePrises;
	this->methodeDAministration=methode;
}

// Accesseurs
int Posologie::getNbPrise(){
	return this->nombreDePrises;
}

void Posologie::setNbPrise(int nombreDePrises){
	this->nombreDePrises=nombreDePrises;
}

string Posologie::getJSM(){
	return this->jsm;
}

void Posologie::getJSM(string jsm){
	this->jsm=jsm;
}

string Posologie::getTemps(){
	return this->temps;
}

void Posologie::getTemps(string temps){
	this->temps=temps;
}

// Affichage d'un objet de type Medicament
void Posologie::afficherPosologie(){
	cout << "La posologie est : " << getNbPrise() << " par " << getJSM << " pendant" << getTemps << endl;
}

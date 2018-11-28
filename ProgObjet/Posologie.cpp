// DENIAUD Brendan et AIRAULT David

#include "Posologie.h"
#include <iostream> 
using namespace std;

// Constructeur de Posologie
Posologie::Posologie(int nombreDePrises, string jsm ,string temps){ 
	Posologie::setNbPrise(nombreDePrises);
	Posologie::setJSM(jsm);
	Posologie::setTemps(temps)
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

void Posologie::setJSM(string jsm){
	this->jsm=jsm;
}

string Posologie::getTemps(){
	return this->temps;
}

void Posologie::setTemps(string temps){
	this->temps=temps;
}

// Affichage d'un objet de type Medicament
void Posologie::afficherPosologie(){
	cout << "La posologie est : " << getNbPrise() << " par " << getJSM() << " pendant" << getTemps() << endl;
}

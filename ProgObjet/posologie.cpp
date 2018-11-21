// DENIAUD Brendan et AYRAULT David

#include "posologie.h"
#include <iostream> 
using namespace std;

// Constructeur de Gene
Posologie::Posologie(int nombreDePrises){ 
	this->nombreDePrises=nombreDePrises;
}

// Accesseurs
int Posologie::getPosologie(){
	return this->nombreDePrises;
}

void Posologie::setPosologie(int nombreDePrises){
	this->nombreDePrises=nombreDePrises;
}

// Affichage d'un objet de type Medicament
void Posologie::afficherPosologie(){
	cout << "La posologie est : " << this->nombreDePrises << endl;
}

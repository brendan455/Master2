// Auteur : DENIAUD B. - AIRAULT D.

#include "Prescription.h"
#include <iostream> 
using namespace std;



// Code du contructeur d'une prescription
Prescription::Prescription(string typePrescription,Posologie posologie,date dateDePrescription){
	setDatePrescription(Date dateDePrescription);
	setTypePrescription(string typePrescription);
	setPosologie(Posologie posologie);
}

// Obtenir la date de Prescription
Date Prescription::getDatePrescription(){
	return this->dateDePrescription;
};
// Obtenir la date de Prescription
void Prescription::setDatePrescription(Date datePrescription){
	this->dateDePrescription = datePrescription;
};

std::string getTypePrescription(){
	return this->typeDePrescripiton;
};

void setTypePrescription(string typePrescription){
	this->typeDePrescripiton = typePrescription;
};
Posologie getPosologie(){
	return this->posologie;
};
void setPosologie(Posologie posologie){
	this->posologie = posologie;
};



// Affichage d'un objet de type DossierPatient
void DossierPatient::afficherPrescription(){
	cout << "Je le ferai après..." << << endl;
}

};

// Auteur : DENIAUD B. - AIRAULT D.

#include "Prescription.h"
#include <iostream> 
using namespace std;



// Code du contructeur d'une prescription
Prescription::Prescription(string typePrescription,Posologie posologie,date dateDePrescription){
	Prescription::setDatePrescription(dateDePrescription);
	Prescription::setTypePrescription(typePrescription);
	Prescription::setPosologie(posologie);
}

// Obtenir la date de Prescription
Date Prescription::getDatePrescription(){
	return this->dateDePrescription;
};
// Obtenir la date de Prescription
void Prescription::setDatePrescription(Date datePrescription){
	this->dateDePrescription = datePrescription;
};

string Prescription::getTypePrescription(){
	return this->typeDePrescripiton;
};

void Prescription::setTypePrescription(string typePrescription){
	this->typeDePrescripiton = typePrescription;
};
Posologie Prescription::getPosologie(){
	return this->posologie;
};
void Prescription::setPosologie(Posologie posologie){
	this->posologie = posologie;
};

void Prescription::afficherPosologie(){
	cout << " La posologie de cette prescription est : " << this->posologie << end1 ;
};

};
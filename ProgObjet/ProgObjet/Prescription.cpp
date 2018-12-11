// Auteur : DENIAUD B. - AIRAULT D.

#include "Prescription.h"
#include "Date.h"

#include <iostream> 
using namespace std;



// Code du contructeur d'une prescription

Prescription::Prescription() {};

Prescription::Prescription(string typePrescription,Posologie posologie,Date dateDePrescription,list<Medicament> medicaments){
	Prescription::setDatePrescription(dateDePrescription);
	Prescription::setTypePrescription(typePrescription);
	Prescription::setPosologie(posologie);
	Prescription::setMedicaments(medicaments);
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
}
std::list<Medicament> Prescription::getMedicaments()
{
	return this->medicaments;
};
void Prescription::setMedicaments(std::list<Medicament> medicaments)
{
	this->medicaments = medicaments;
};
Posologie Prescription::getPosologie(){
	return this->posologie;
};
void Prescription::setPosologie(Posologie posologie){
	this->posologie = posologie;
};

/*void Prescription::afficherPrescription(){
	cout << " La prescription est : " << this->posologie << end1 ;
}; */


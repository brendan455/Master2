// Auteur : DENIAUD B. - AIRAULT D.

#include "DossierPatient.h"
#include <iostream> 
#include <string>
using namespace std;


// Code du contructeur de DossierPatient
DossierPatient::DossierPatient() {};
DossierPatient::DossierPatient(Patient patient) {
	list<RDV> emptylist;
	DossierPatient::setPatient(patient);
	DossierPatient::setRdvs(emptylist);
};
DossierPatient::DossierPatient(list<RDV> rdvs, Patient patient){
	DossierPatient::setRdvs(rdvs);
	DossierPatient::setPatient(patient);
};


// Affichage d'un objet de type DossierPatient
void DossierPatient::afficherDossierPatient(){
}

// Accesseurs
void DossierPatient::setPatient(Patient patient) {
	this->patient = patient;
};
Patient DossierPatient::getPatient() {
	return this->patient;
};
void DossierPatient::setRdvs(list<RDV> rdvs) {
	this->rdvs = rdvs;
};
list<RDV> DossierPatient::getRdvs() {
	return this->rdvs;
};

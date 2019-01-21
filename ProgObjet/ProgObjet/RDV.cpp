// Auteur : DENIAUD B. - AIRAULT D.

#include "RDV.h"
#include <iostream> 
#include <string>
using namespace std;


// Code du contructeur de RDV
		
RDV::RDV() {};
RDV::RDV(Medecin medecin, list<Prescription> prescriptions, Date date, int ID)
{
	RDV::setMedecin(medecin);
	RDV::setPrescriptions(prescriptions);
	RDV::setDateRdv(date);
	RDV::setID(ID);
};

RDV::RDV(Medecin medecin, Date date, int ID) {
	list<Prescription> prescriptions;
	RDV::setMedecin(medecin);
	RDV::setPrescriptions(prescriptions);
	RDV::setDateRdv(date);
	RDV::setID(ID);
};


// Accesseurs
void RDV::setMedecin(Medecin medecin){
	this->medecin=medecin;
};
Medecin RDV::getMedecin(){
	return this->medecin;
};
void RDV::setPrescriptions(std::list<Prescription> prescriptions){
	this->prescriptions=prescriptions;
};
list<Prescription> RDV::getPrescriptions(){
	return this->prescriptions;
};
void RDV::setDateRdv(Date date){
	this->dateRdv=date;
};
Date RDV::getDateRdv(){
	return this->dateRdv;
}
;
void RDV::setID(int id) {
	this->ID = id;
};
int RDV::getID() {
	return this->ID;
};

	
// Affichage
void RDV::afficherBilanRdv(){
	list<Prescription> pres = getPrescriptions();
	Prescription courant;
	cout << "       le RDV avec le docteur " << RDV::getMedecin().getPrenom() << " " << getMedecin().getNom() <<  " a donne lieu a " << RDV::getPrescriptions().size() <<" Prescriptions"<< endl ;
	cout << "       le RDV a eu lieu le ";
	getDateRdv().affichage1();
	if (!getPrescriptions().empty()) {
		for (list<Prescription>::iterator it = pres.begin(); it != pres.end(); it++) {
			courant = *it;
			courant.afficherPrescription();
		}
	}
	else {
		cout << "       Il n'y a pas de prescription pour ce rendez vous a l'heure actuelle ";
	}
};

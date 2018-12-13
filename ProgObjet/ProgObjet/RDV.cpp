// Auteur : DENIAUD B. - AIRAULT D.

#include "RDV.h"
#include <iostream> 
#include <string>
using namespace std;


// Code du contructeur de RDV
		
RDV::RDV() {};
RDV::RDV(Medecin medecin, list<Prescription> prescriptions, Date date)
{
	RDV::setMedecin(medecin);
	RDV::setPrescriptions(prescriptions);
	RDV::setDateRdv(date);
};

RDV::RDV(Medecin medecin, Date date) {
	list<Prescription> prescriptions;
	RDV::setMedecin(medecin);
	RDV::setPrescriptions(prescriptions);
	RDV::setDateRdv(date);
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
};
	
// Affichage
void RDV::afficherBilanRdv(){
	cout << "le RDV avec le docteur " << RDV::getMedecin().getnomMedecin() << " a donné lieu à "
		<< RDV::getPrescriptions().size() << endl ;
	cout << " le RDV à eu lieu le " << endl ;
	getDateRdv().affichage2();	
};

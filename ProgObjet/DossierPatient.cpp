// Auteur : DENIAUD B. - AIRAULT D.

#include "DossierPatient.h"
#include <iostream> 
#include <string>
using namespace std;



// Contructeur de DossierPatient
DossierPatient::DossierPatient(int numeroDossier,list<RDV> rendezVous,Patient patient){
	setNumeroDossier(numeroDossier);
	setPatient(patient);
	setRendezVous(rendezVous);
};

// Accesseur
int DossierPatient::getNumeroDossier(){
	return this->numeroDossier;
};
void DossierPatient::setNumeroDossier(int numeroDossier){
	this->numeroDossier=numeroDossier;
};
Patient DossierPatient::getPatient(){
	return this->patient
};
void DossierPatient::setPatient(Patient patient){
	this->patient=patient
};
list<RDV> DossierPatient::getRendezVous(){
	return this->rendezVous
};
void DossierPatient::setRendezVous(list<RDV> rendezVous){
	this->rendezVous=rendezVous
};
	
// Affichage

void afficherDossierPatient(){
	list<RDV>::iterator i;
	string avis = "none";
	
	cout << "Dossier de " << DossierPatient::getPatient().getCivilite() << DossierPatient::getPatient().getNomPatient() << end1 ;
	
	for (i=DossierPatient::getRendezVous().begin(); i!=DossierPatient::getRendezVous().end(); ++i){
   		cout << *i.afficherBilanRdv() <<end1;
		cout << "Voulez vous voir le Rendez-vous suivant ?" << "yes / no " << end1
			
		while (avis.compare("yes") != 0 && avis.compare("no") != 0){
			cin >> avis ;
		}
		if (avis.compare("no") == 0){
			break;
		}
	}
	if (avis.compare("yes") == 0){
		cout << "tout les rendez-vous on été vus" << end1;
	}
};

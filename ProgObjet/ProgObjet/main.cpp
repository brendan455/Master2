

#include "CabinetMedical.h"
#include <iostream> 
#include <string>
using namespace std;


void run(){
	CabinetMedical cabinet = CabinetMedical();
	string reponseString;
	int reponseInt;
	
	int choice;
	DossierPatient nouveauDossier;

	cout << "Bienvenue dans l'application de " << endl;
	cabinet = lire_fichier();

	if (cabinet.getNomCabinet().compare("NULL") == 0) {
		cout << "Premi�re fois" << endl;
		cout << "Quel Cabinet voulez vous creer ?" << endl;
		getline(cin,reponseString);
		cabinet.setNomCabinet(reponseString);
	}

	while (choice != 666 ) {
		cout << " Cabinet " << cabinet.getNomCabinet << " Bonjour, que souhaitez vous faire ?" << endl;
		getline(cin,choice);
		switch (choice) {
		case(1):
			//1 Enregistrer Nouveau Patient
				// Assigner Medecin traitant
				// Nom pr�nom adresse
				// Groupe Sanguin
				// Tel, Numero S�cu

			nouveauDossier = enregisterNouveauPatient();
			if (true){
				list<int> newlist;
				cabinet.getDossiersPatient().insert(nouveauDossier);
			}
			else {
				cout << " Erreur de Saisie du patient."
			}
			break
		case(2):
			cout << " Voulez vous vraiment modifier un patient ? " << endl;
			getline(cin,reponseString);
			if(!reponseString.empty()){
				reponseString.
				if (reponseString.compare("yes") || reponseString.compare("y") || reponseString.compare("Y") || reponseString.compare("YES")
			
			//2 Modifier Patient existant

			//3 Fiche Ordre Alphab�tique

			// Retour
		//2 Pareil Pour Medecin

		//3 Gestion DossierPatient ( Affichage Nom Patient, Num tel, Groupe et Medecin traitant )
			//1 Information Patients
				// Information du rdv
				// Modifier RDV 
				// Afficher le rendez vous suivant
			//2 Changer de medecin traitant
			//3 Programmer un rendez vous
			//4 Saisir une prescription
		//4 Quitter le programme
		default:

		}
	}
};

CabinetMedical lire_fichier() {
	if (true) {
		return CabinetMedical(0);
	}
	else {
		return CabinetMedical(0);
	}
};

DossierPatient enregisterNouveauPatient(){
	string nomPatient prenomPatient adrPatient;
	int telPatient , numPatient ;
	char groupePatient ;
	bool sexePatient ;
	Patient NewPatient;
	DossierPatient nouveauDossier ;
	cout << " bla bla bla" << endl;

	getline(cin,nomPatient);
	getline(cin,prenomPatient);
	getline(cin,adrPatient);
	getline(cin,telPatient);
	getline(cin,numPatient);
	getline(cin,groupePatient);
	getline(cin,sexePatient);

	NewPatient = Patient::Patient(numPatient,groupePatient) : Personne(nomPatient,PrenomPatient,adrPatient,sexePatient,numPatient);
	nouveauDossier = DossierPatient::DossierPatient(NewPatient);
	
	return nouveauDossier;

};

int main( int argc, const char* argv []){
  run();
  return 0;
}

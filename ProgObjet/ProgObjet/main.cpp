

#include "CabinetMedical.h"
#include <iostream> 
#include <string>
#include <fstream>
using namespace std;



void run() {
	CabinetMedical cabinet = CabinetMedical();
	string reponseString;
	int reponseInt;
	int menuChoice;
	int choice;
	bool test;
	DossierPatient nouveauDossier;
	Medecin nouveauMedecin;
	RDV nouveauRDV;

	cout << "Bienvenue dans l'application de " << endl;
	cabinet = lire_fichier();

	if (cabinet.getNomCabinet().compare("NULL") == 0) {
		cout << "Premiere fois" << endl;
		cout << "Quel Cabinet voulez vous creer ?" << endl;
		getline(cin, reponseString);
		cabinet.setNomCabinet(reponseString);
	}

	while (choice != 4) {
		cout << " Cabinet " << cabinet.getNomCabinet << " Bonjour, que souhaitez vous faire ?" << endl;
		cout << "1 : Gestion Patient \n 2 : Gestion Medecin \n 3 : Gestion RDV \n 4 : Quitter \n" << endl;
		cin >> choice;
		switch (choice) {
		case(1):
			menuChoice = 0;
			while (menuChoice != 6) {
				cout << "Que souhaitez vous faire ? \n" << endl;
				cout << "1 : Enregistrer un Patient \n 2 : Supprimer un Patient \n 3 : Modifier un Patient \n 4 : Afficher le dossier d'un Patient \n 5 : Retour \n" << endl;
				cin >> menuChoice;

				switch (menuChoice) {

				case(1):
					cout << "Enregistrement patient" << endl;
					nouveauDossier = enregisterNouveauPatient();
					if (nouveauDossier.exist()) {
						cabinet.getDossiersPatient().push_back(nouveauDossier);
					}
					else {
						cout << " Erreur de Saisie du patient." << endl;
					}
					break;
				case(2):
					cout << "Suppression patient" << endl;
					
					reponseInt=1;
					while (!test && reponseInt != 0) {
						cout << "Saisissez le numero du medecin à supprimer" << endl;
						cin >> reponseInt;
						for (list<Medecin>::iterator it = cabinet.getMedecins().begin(); it != cabinet.getMedecins().end(); ++it) {
							nouveauMedecin = *it;
							if (nouveauMedecin.getNumeroOrdreMedecin() == (reponseInt)) {
								test = true;
								break;
							}
						}
						if (!test) {
							cout << "numero invalide, veuillez réessayer ou tapez 0 pour retourner au menu." << endl;
						}
						else{ 
							nouveauMedecin
					/*	case(3):
						cout << " Voulez vous vraiment modifier un patient ? " << endl;
						getline(cin, reponseString);
						if (!reponseString.empty()) {
						reponseString.
						if (reponseString.compare("yes") || reponseString.compare("y") || reponseString.compare("Y") || reponseString.compare("YES")
						break;
					*/
				case(4):
					break
				}
			}
			break;

			//2 Supprimmer patient
				//3 Modifier patient 
				//4 Afficher dossier patient
				//5 Retour
		case(2):
			//2 Gestion medecin
			menuChoice = 0;
			while (menuChoice != 5) {
				cout << "Que souhaitez vous faire ? \n" << endl;
				cout << "1 : Enregistrer un Medecin \n 2 : Supprimer un Medecin \n 3 : Modifier un Medecin \n 4 : Retour \n" << endl;
				cin >> menuChoice;

				switch (menuChoice) {
				case(1):
					nouveauMedecin = enregisterNouveauMedecin();
					if (nouveauMedecin.exist()) {
						cabinet.getMedecins().push_back(nouveauMedecin);
					}
					else {
						cout << " Erreur de saisie du medecin." << endl;
					}
					cout << " Voulez vous vraiment créer un medecin ? " << endl;
					getline(cin, reponseString);
					if (!reponseString.empty()) {
						if (reponseString.compare("yes") || reponseString.compare("y") || reponseString.compare("Y") || reponseString.compare("YES")) {
						}
					}
					break;
				case(4):
					break;
				}
			}
			break;
				/*//2 Supprimer medecin
				case(2):
					Medecin = supprimerMedecin();
					if (true) {
						list<int> newlist;
						Patient.getsupprimerPatient().insert(supprimerMedecin);
					}
					else {
						cout << " Erreur de saisie du medecin."
					}
					break;


					cout << " Voulez vous vraiment supprimer un medecin ? " << endl;
					getline(cin, reponseString);
					if (!reponseString.empty()) {
						reponseString.
							if (reponseString.compare("yes") || reponseString.compare("y") || reponseString.compare("Y") || reponseString.compare("YES")
					}

			//3 Modifier medecin
				case(3):
					medecin = modifierMedecin();
					if (true) {
						list<int> newlist;
						Medecin.getMedecin()).insert(Medecin);
					}
					else {
						cout << " Erreur de saisie du medecin."
					}
					break;


					cout << " Voulez vous vraiment modifier un medecin ? " << endl;
					getline(cin, reponseString);
					if (!reponseString.empty()) {
						reponseString.
							if (reponseString.compare("yes") || reponseString.compare("y") || reponseString.compare("Y") || reponseString.compare("YES")
					}
			//4 Retour
				*/

			//3 Gestion RDV
		case(3):
			menuChoice = 0;
			while (menuChoice != 5) {
				cout << "Bonjour, que souhaitez vous faire ?" << endl;

				cin >> menuChoice;
				switch (menuChoice) {

					//1 Creer Rdv					
				case(1):
					cout << "veuillez indiquer le numero de Securité sociale du patient." << endl;
					test = false;
					reponseInt = 1;
					while (!test && reponseInt != 0) {
						cin >> reponseInt;
						for (list<DossierPatient>::iterator it = cabinet.getDossiersPatient().begin(); it != cabinet.getDossiersPatient().end(); ++it) {
							nouveauDossier = *it;
							if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == (reponseInt)) {
								test = true;
								break;
							}
						}
						if (!test) {
							cout << "numero invalide, veuillez réessayer ou tapez 0 pour retourner au menu." << endl;
						}
					}
					if (reponseInt != 0) {
						nouveauRDV = enregistrerNouveauRdv(cabinet);
							if (nouveauRDV) {
								nouveauDossier.getRdvs().push_back(nouveauRDV);
								cout << "Rendezvous Cree" << endl;
							}
							else {
								cout << "Erreur dans la création du rendez-vous, veuillez recommencer" << endl;
							}
					}
					break;



				}
			}
			//2	Modifier Rdv
			//3 Supprimer Rdv
			//4 Saisir une prescription
			//5 Retour

		case(4): //Quitter le programme

			}
		}
	};

CabinetMedical lire_fichier() {
	CabinetMedical cabinet;
	ifstream fichier("cabinet.txt", ios::in);

	if (fichier) 
	{
		// ??
		/*
		string Cabinet;
		getline(fichier, Cabinet);
		return (Cabinet);
		fichier.close();
		*/
	}
	else {
		cabinet = CabinetMedical::CabinetMedical(0);
		cerr << "Impossible d'ouvrir le fichier !" << endl;
		return cabinet;
	}
};

DossierPatient enregisterNouveauPatient(){
	string nomPatient, prenomPatient, adrPatient;
	int telPatient , numPatient ;
	char groupePatient ;
	bool sexePatient ;
	Patient NewPatient;
	DossierPatient nouveauDossier ;

	cout << "Veuillez saisir le nom du patient à enregistrer : \n" << endl;
	getline(cin,nomPatient);

	cout << "Veuillez saisir le prenom du nouveau patient : \n" << endl;
	getline(cin,prenomPatient);

	cout << "Veuillez renseigner l'adresse du patient : \n" << endl;
	getline(cin,adrPatient);

	cout <<"Veuillez entrer le numéro de téléphone de contact du patient : \n" << endl;
	cin >> telPatient;

	cout <<"Veuillez renseigner le groupe sanguin du patient : \n" << endl;	
	cin >> groupePatient;



	// Gestion num identique
	cout << "Veuillez entrer le numéro de sécurité sociale du patient : \n" << endl;
	cin >> numPatient;

	cout <<"Quel est le sexe du patient (F : Feminin / M : Masculin) : \n" << endl;
	cin >> sexePatient;
	


	NewPatient = Personne::Personne(nomPatient,prenomPatient,adrPatient,sexePatient,telPatient);
	nouveauDossier = DossierPatient::DossierPatient(NewPatient);
	
	return nouveauDossier;

};

Medecin enregisterNouveauMedecin(){
	string nomMedecin, prenomMedecin, adrMedecin;
	int telMedecin , numMedecin ;
	char specialiteMedecin ;
	bool sexeMedecin ;
	int numeroOrdreMedecin;	
	Medecin NewMedecin;

	cout << "Veuillez saisir le nom du medecin à enregistrer : \n" << endl;
	getline(cin,nomMedecin);

	cout << "Veuillez saisir le prenom du nouveau medecin : \n" << endl;
	getline(cin,prenomMedecin);

	cout << "Veuillez renseigner l'adresse du medecin : \n" << endl;
	getline(cin,adrMedecin);

	cout <<"Veuillez entrer le numéro de téléphone de contact du medecin : \n" << endl;
	cin >> telMedecin;

	cout << "Veuillez renseigner la specialite du medecin : \n" << endl;
	cin >> specialiteMedecin;


	// Gestion des numéros identiques
	cout <<"Veuillez entrer le numéro d'ordre des médecin du medecin : \n" << endl;
	cin >> numeroOrdreMedecin;

	// Gestion du sexe			
	cout <<"Quel est le sexe du medecin (F : Feminin / M : Masculin) : \n" << endl;
	cin >> sexeMedecin;

	NewMedecin = Medecin::Medecin(numMedecin,specialiteMedecin) : Personne(nomMedecin,PrenomMedecin,adrMedecin,sexeMedecin,telMedecin);
	
	return NewMedecin;

};

RDV enregistrerNouveauRdv(CabinetMedical cabinet) {
	RDV rendezvous;
	Date dateRDV;
	int numeroMedecin = 1;
	Medecin medecinCourant;
	bool test = false;
	int jour, mois, annee;
	cout << "Veuillez saisir le nom du medecin pour le rendez-vous \n" << endl;
	while (!test && numeroMedecin!= 0 ){
		cin >> numeroMedecin;
		for (list<Medecin>::iterator it = cabinet.getMedecins().begin(); it != cabinet.getMedecins().end(); ++it) {
			medecinCourant = *it;
			if (medecinCourant..getnumeroOrdreMedecin() == (numeroMedecin)) {
				test = true;
				break;
			}
		}
		if (numeroMedecin != 0) {

			cout << "Veuillez saisir le jour du rdv: \n" << endl;
			getline(cin, jour);
			cout << "Veuillez saisir le mois du rdv: \n" << endl;
			getline(cin, mois);
			cout << "Veuillez saisir l'annee du rdv: \n" << endl;
			getline(cin, annee);
			dateRDV = Date::Date(jour, mois, annee);

			rendezvous = RDV::RDV(medecinCourant, dateRDV);
		else{
		rendezvous.setMedecin(Medecin::Medecin());
		}
	}
	return rendezvous;
};


int main( int argc, const char* argv []){
  run();
  return 0;
};

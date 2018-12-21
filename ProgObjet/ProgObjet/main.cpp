/*
Ecrire dans un fichier :

		ofstream fichier("Cabinet.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

		if(fichier)
		{
				string nomCabinet = nomCabinet;
				int adresseCabinet = adresseCabinet;

				fichier << nomCabinet << adresseCabinet;

				fichier.close();
		}
		else
				cerr << "Impossible d'ouvrir le fichier !" << endl;

		return 0;

	test
Lire dans un Fichier :

		ifstream fichier("Cabinet.txt", ios::in);

		if(fichier)
		{
				string nomCabinet;
				string adresseCabinet;

				fichier >> nomCabinet >> adresseCabinet ;  on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée 

fichier.close();
		}
		else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

		return 0;

		*/

#include "CabinetMedical.h"
#include <iostream> 
#include <string>
#include <fstream>
using namespace std;




CabinetMedical lire_fichier() {
	CabinetMedical cabinet;
	ifstream fichier("cabinet.txt", ios::in);

	if (fichier)
	{

	}
	else {
		cabinet = CabinetMedical::CabinetMedical(0);
		cerr << "Impossible d'ouvrir le fichier !" << endl;
		return cabinet;
	}
};

DossierPatient enregisterNouveauPatient(CabinetMedical cabinet) {
	string nomPatient, prenomPatient, adrPatient, captage;
	int telPatient, numPatient;
	char groupePatient;
	char sexe = 'X';
	bool sexePatient;
	bool test = true;
	Patient NewPatient;
	DossierPatient nouveauDossier;
	list<DossierPatient> InitList;

	cout << " Veuillez saisir le nom du patient a enregistrer : " << endl;
	getline(cin, nomPatient);

	cout << " Veuillez saisir le prenom du nouveau patient : " << endl;
	getline(cin, prenomPatient);

	cout << " Veuillez renseigner l'adresse du patient : " << endl;
	getline(cin, adrPatient);

	cout << " Veuillez entrer le numero de telephone de contact du patient : " << endl;
	cin >> telPatient;
	cin.ignore();
	cout << " Veuillez renseigner le groupe sanguin du patient : " << endl;
	cin >> groupePatient;
	cin.ignore();
	while (sexe != 'F' && sexe != 'f' && sexe != 'M' && sexe != 'm') {
		cout << " Quel est le sexe du Patient (F : Feminin / M : Masculin) : \n" << endl;
		cin >> sexe;
		getline(cin, captage);
	}
	if (sexe == 'F' || sexe == 'f') {
		sexePatient = true;
	}
	else {
		sexePatient = false;
	}
	cout << " Veuillez entrer le numero de securite sociale du patient : \n" << endl;
	InitList = cabinet.getDossiersPatient();
	while (test || numPatient == 0) {
		test = false;
		cin >> numPatient;
		cin.ignore();
		if (!InitList.empty()){
			for (list<DossierPatient>::iterator it = InitList.begin(); it != InitList.end(); ++it) {
				nouveauDossier = *it;
				if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == (numPatient)) {
					test = true;
					break;
				}
			}
		}

		if (test || numPatient == 0 || !InitList.empty()) {
			cout << " Numero d'ordre deja existant ou egal a 0, veuillez en saisir un autre" << endl;
		}
	}

	NewPatient = Patient::Patient(numPatient, groupePatient , nomPatient, prenomPatient, adrPatient, sexePatient, telPatient);
	nouveauDossier = DossierPatient::DossierPatient(NewPatient);

	cout << "\n Le Dossier de : " << nouveauDossier.getPatient().getPrenom() << " " << nomPatient << " a ete cree" << endl;
	return nouveauDossier;

};

DossierPatient modifierPatient(int numPatient) {
	string nomPatient, prenomPatient, adrPatient, captage;
	int telPatient;
	char groupePatient;
	char sexe = 'X';
	bool sexePatient;
	Patient NewPatient;
	DossierPatient nouveauDossier;

	cout << " Veuillez saisir le nom de ce patient  : " << endl;
	getline(cin, nomPatient);

	cout << " Veuillez saisir le prenom du  patient : " << endl;
	getline(cin, prenomPatient);

	cout << " Veuillez renseigner l'adresse du patient : " << endl;
	getline(cin, adrPatient);

	cout << " Veuillez entrer le numero de telephone de contact du patient : " << endl;
	cin >> telPatient;
	cin.ignore();
	cout << " Veuillez renseigner le groupe sanguin du patient : " << endl;
	cin >> groupePatient;
	cin.ignore();
	while (sexe != 'F' && sexe != 'f' && sexe != 'M' && sexe != 'm') {
		cout << " Quel est le sexe du Patient (F : Feminin / M : Masculin) : \n" << endl;
		cin >> sexe;
		getline(cin, captage);
	}
	if (sexe == 'F' || sexe == 'f') {
		sexePatient = true;
	}
	else {
		sexePatient = false;
	}
	NewPatient = Patient::Patient(numPatient, groupePatient, nomPatient, prenomPatient, adrPatient, sexePatient, telPatient);
	nouveauDossier = DossierPatient::DossierPatient(NewPatient);

	cout << "\n Le Dossier de : " << nouveauDossier.getPatient().getPrenom() << " " << nomPatient << " a ete modifie" << endl;
	return nouveauDossier;
};

Medecin enregisterNouveauMedecin(CabinetMedical cabinet) {
	string nomMedecin, prenomMedecin, adrMedecin, specialiteMedecin, captage;
	int telMedecin;
	char sexe = 'X';
	bool sexeMedecin;
	bool test = true;
	int numeroOrdreMedecin = 1;
	Medecin NewMedecin;
	list<Medecin> InitList;

		cout << "Veuillez saisir le nom du medecin à enregistrer : \n" << endl;
	getline(cin, nomMedecin);

	cout << "Veuillez saisir le prenom du nouveau medecin : \n" << endl;
	getline(cin, prenomMedecin);

	cout << "Veuillez renseigner l'adresse du medecin : " << endl;
	getline(cin, adrMedecin);

	cout << "Veuillez entrer le numéro de téléphone de contact du medecin : " << endl;
	cin >> telMedecin;

	cout << "Veuillez renseigner la specialite du medecin :" << endl;
	getline(cin, specialiteMedecin);

	while (sexe != 'F' && sexe != 'f' && sexe != 'H' && sexe != 'h') {
		cout << "Quel est le sexe du medecin (F : Feminin / M : Masculin) : \n" << endl;
		cin >> sexe;
	}
	if (sexe == 'F' || sexe == 'f') {
		sexeMedecin = true;
	}
	else {
		sexeMedecin = false;
	}
	cout << "Veuillez saisir le numéro d'Ordre des Medecin : " << endl;
	InitList = cabinet.getMedecins();
	while (test || numeroOrdreMedecin == 0) {
		test = false;
		cin >> numeroOrdreMedecin;
		cin.ignore();
		if (!InitList.empty()) {
			for (list<Medecin>::iterator it = InitList.begin(); it != InitList.end(); ++it) {
				NewMedecin = *it;
				if (NewMedecin.getnumeroOrdreMedecin() == (numeroOrdreMedecin)) {
					test = true;
					break;
				}
			}
		}

		if (test || numeroOrdreMedecin == 0 || !InitList.empty()) {
			cout << "Numero d'ordre déjà existant ou egal à 0, veuillez en saisir un autre" << endl;
		}
	}


	NewMedecin = Medecin::Medecin(specialiteMedecin, telMedecin, nomMedecin, prenomMedecin, adrMedecin, sexeMedecin, telMedecin);
	cout << "\n Le nouveau médecin, Docteur " << NewMedecin.getNom() << " a ete cree" << endl;
	return NewMedecin;
};

Medecin modifierMedecin(int numeroOrdreMedecin) {
	string nomMedecin, prenomMedecin, adrMedecin, specialiteMedecin;
	int telMedecin;
	char sexe = 'X';
	bool sexeMedecin;
	bool test = true;
	Medecin NewMedecin;

	cout << "Veuillez saisir le nom du medecin : \n" << endl;
	getline(cin, nomMedecin);

	cout << "Veuillez saisir le prenom du medecin : \n" << endl;
	getline(cin, prenomMedecin);

	cout << "Veuillez renseigner l'adresse du medecin : \n" << endl;
	getline(cin, adrMedecin);

	cout << "Veuillez entrer le numéro de téléphone de contact du medecin : \n" << endl;
	cin >> telMedecin;

	cout << "Veuillez renseigner la specialite du medecin : \n" << endl;
	getline(cin, specialiteMedecin);

	while (sexe != 'F' || sexe != 'f' || sexe != 'H' || sexe != 'h') {
		cout << "Quel est le sexe du medecin (F : Feminin / M : Masculin) : \n" << endl;
		cin >> sexe;
	}
	if (sexe == 'F' || sexe == 'f') {
		sexeMedecin = true;
	}
	else {
		sexeMedecin = false;
	}

	NewMedecin = Medecin::Medecin(specialiteMedecin, telMedecin, nomMedecin, prenomMedecin, adrMedecin, sexeMedecin, telMedecin);

	return NewMedecin;

};

RDV enregistrerNouveauRdv(CabinetMedical cabinet) {
	RDV rendezvous = RDV::RDV();
	Date dateRDV;
	int numeroMedecin = 1;
	Medecin medecinCourant;
	bool test = false;
	int jour, mois, annee;
	list<Medecin> InitList = cabinet.getMedecins();
	cout << "Veuillez saisir le nom du medecin pour le rendez-vous \n" << endl;
	while (!test && numeroMedecin != 0) {
		cin >> numeroMedecin;
		for (list<Medecin>::iterator it = InitList.begin(); it != InitList.end(); ++it) {
			medecinCourant = *it;
			if (medecinCourant.getnumeroOrdreMedecin() == (numeroMedecin)) {
				test = true;
				break;
			}
		}
		if (!test) {
			cout << "Veuillez saisir un numero Valide, faites 0 pour annuler" << endl;
		}
	}

	if (numeroMedecin != 0) {

		cout << "Veuillez saisir le jour du rdv: \n" << endl;
		cin >> jour;
		cout << "Veuillez saisir le mois du rdv: \n" << endl;
		cin >> mois;
		cout << "Veuillez saisir l'annee du rdv: \n" << endl;
		cin >> annee;
		dateRDV = Date::Date(jour, mois, annee);

		rendezvous = RDV::RDV(medecinCourant, dateRDV);
	}
	else {
		rendezvous.setDateRdv(Date());
		rendezvous.getDateRdv().setDay(0);
	}

	return rendezvous;
};

void run() {
	CabinetMedical cabinet = CabinetMedical();
	CabinetMedical newcab;
	string reponseString, captage;
	int reponseInt;
	int menuChoice;
	int choice = 0;
	bool test;
	DossierPatient nouveauDossier;
	Medecin nouveauMedecin;
	RDV nouveauRDV;
	list<DossierPatient> InitList;
	list<Medecin> InitMedList;
	list<DossierPatient>::iterator itDossier;
	list<Medecin>::iterator iterMed;

	cout << "\n Bienvenue dans l'application de Gestion de cabinet Medical" << endl;
	cabinet = lire_fichier();

	if (cabinet.getNomCabinet() == "null") {
		cout << "\n Premiere fois" << endl;
		cout << " Quel est le nom du cabinet que vous souhaitez creer ?" << endl;
		getline(cin, reponseString);
		cabinet.setNomCabinet(reponseString);
		cout << "\n A quelle Adresse se trouve ce cabinet ?" << endl;
		getline(cin, reponseString);
		cabinet.setAdresseCabinet(reponseString);
		cabinet.setDossiersPatient(InitList);
		cabinet.setMedecins(InitMedList);
	}

	while (choice != 4) {
		cout << "\n Cabinet " << cabinet.getNomCabinet() << " Bonjour, que souhaitez vous faire ?" << endl;
		cout << " 1 : Gestion Patient \n 2 : Gestion Medecin \n 3 : Gestion RDV \n 4 : Quitter \n" << endl;
		cin >> choice;
		switch (choice) {

		case(1):
			menuChoice = 0;
			while (menuChoice != 5) {
				cout << "\n Que souhaitez vous faire ?" << endl;
				cout << " 1 : Enregistrer un Patient \n 2 : Supprimer un Patient \n 3 : Modifier un Patient \n 4 : Rechercher le dossier d'un patient \n 5 : Retour \n" << endl;
				cin >> menuChoice;
				cin.ignore();
				switch (menuChoice) {

					case(1):
						cout << "\n Enregistrement patient" << endl;
						nouveauDossier = enregisterNouveauPatient(cabinet);
						InitList = cabinet.getDossiersPatient();
						InitList.push_back(nouveauDossier);
						cabinet.setDossiersPatient(InitList);
						break;

					case(2):
						cout << "Suppression patient" << endl;
						InitList = cabinet.getDossiersPatient();
						if (!InitList.empty()) {
							reponseInt = 1;
							test = false;
							while (!test && reponseInt != 0) {
								cout << "Saisissez le numero du Patient à supprimer" << endl;
								cin >> reponseInt;
								getline(cin, captage);
								for (itDossier = InitList.begin(); itDossier != InitList.end(); itDossier++) {
									nouveauDossier = *itDossier;
									if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == (reponseInt)) {
										test = true;
										break;
									}
								}
								if (!test) {
									cout << "numero invalide, veuillez réessayer ou tapez 0 pour retourner au menu." << endl;
								}
								else {
									InitList.erase(itDossier);
									cabinet.setDossiersPatient(InitList);
								}
							}
						}
						else {
							cout << "Main non la liste est vide imbecile !" << endl;
						}
						break;

					case(3):
							cout << "Modification patient, taper 0 pour annuler." << endl;

							if (!InitList.empty()) {
								reponseInt = 1;
								test = false;
								while (!test && reponseInt != 0) {
									cout << "Saisissez le numero du Patient à modifier" << endl;
									cin >> reponseInt;
									getline(cin, captage);
									for (itDossier = InitList.begin(); itDossier != InitList.end(); itDossier++) {
										nouveauDossier = *itDossier;
										if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == (reponseInt)) {
											test = true;
											break;
										}
									}
									if (!test && reponseInt != 0) {
										cout << "numero invalide, veuillez réessayer ou tapez 0 pour retourner au menu." << endl;
									}
									else {
										InitList.erase(itDossier);
										InitList.push_back(modifierPatient(reponseInt));
										cabinet.setDossiersPatient(InitList);
									}
								}
							}
							else {
							cout << "Main non la liste est vide imbecile !" << endl;
							}

						break;

					case(4):
						cout << "\n Recherche de Dossier Patient" << endl;
						InitList = cabinet.getDossiersPatient();
						if (!InitList.empty() ) {
							cout << " Veuillez saisir le numero de securite sociale du patient que vous recherchez" << endl;
							cin >> reponseInt;
							getline(cin, captage);
							test = false;

							if (reponseInt != 0) {
								for (itDossier = InitList.begin(); itDossier != InitList.end(); ) {
									nouveauDossier = *itDossier;
									if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == (reponseInt)) {
										test = true;
										break;
									}
									else {
										itDossier++;
									}
								}
								if (test) {
									nouveauDossier.afficherDossierPatient();
								}
								else {
									cout << " Numero inexistant, Operation impossible, veuillez entrer un numero existant" << endl;
								}
							}
						}
						else {
							cout << "Pas de dossiers patients cree" << endl;
						}
						break;
					}
				}
			break;

		case(2):
			menuChoice = 0;
			while (menuChoice != 5) {
				cout << " Que souhaitez vous faire ? \n" << endl;
				cout << " 1 : Enregistrer un Medecin \n 2 : Supprimer un Medecin \n 3 : Modifier un Medecin \n 4 : Retour \n" << endl;
				cin >> menuChoice;
				cin.ignore();
				switch (menuChoice) {
				case(1):
					nouveauMedecin = enregisterNouveauMedecin(cabinet);
					InitMedList = cabinet.getMedecins();
					InitMedList.push_back(nouveauMedecin);
					cabinet.setMedecins(InitMedList);
					break;

				case(2):
					cout << "Suppression Medecin" << endl;

					reponseInt = 1;
					InitMedList = cabinet.getMedecins();
					if (!InitMedList.empty()) {
						test = false;
						while (!test && reponseInt != 0) {
							cout << "Saisissez le numero du medecin à supprimer" << endl;
							cin >> reponseInt;
							getline(cin, captage);
							for (iterMed = InitMedList.begin(); iterMed != InitMedList.end(); iterMed++) {
								nouveauMedecin = *iterMed;
								if (nouveauMedecin.getnumeroOrdreMedecin() == (reponseInt)) {
									test = true;
									break;
								}
							}
							if (reponseInt != 0) {
								if (test) {
									InitMedList.erase(iterMed);
									cabinet.setMedecins(InitMedList);
								}
								else {
									cout << "numero invalide, veuillez réessayer ou tapez 0 pour retourner au menu." << endl;

								}
							}
						}
					}
					else {
						cout << " Il n'y a pas de medecins actuellement enregistre dans le logiciel" << endl;
					}

				case(3):
					cout << "Modification Medecin, taper 0 pour annuler." << endl;
					reponseInt = 1;
					InitMedList = cabinet.getMedecins();
					if (!InitMedList.empty()) {
						test = false;
						while (!test && reponseInt != 0) {
							cout << "Saisissez le numero du medecin à modifier" << endl;
							cin >> reponseInt;
							getline(cin, captage);
							for (iterMed = InitMedList.begin(); iterMed != InitMedList.end(); ++iterMed) {
								nouveauMedecin = *iterMed;
								if (nouveauMedecin.getnumeroOrdreMedecin() == (reponseInt)) {
									test = true;
									break;
								}
							}
							if (reponseInt != 0) {
								if (test) {
									InitMedList.erase(iterMed);
									nouveauMedecin = modifierMedecin(reponseInt);
									InitMedList.push_back(nouveauMedecin);
									cabinet.setMedecins(InitMedList);
								}
								else {
									cout << "numero invalide, veuillez réessayer ou tapez 0 pour retourner au menu." << endl;
								}
							}
						}
					}

				case(4):
					cout << "Afficher medecin, taper 0 pour annuler." << endl;
					
					break;
				}
			
			}break;

		case(3):
			menuChoice = 0;
			while (menuChoice != 5) {
				cout << " Bonjour, que souhaitez vous faire ?" << endl;

				cin >> menuChoice;
				cin.ignore();
				switch (menuChoice) {
					
				case(1):
					cout << "veuillez indiquer le numero de Securité sociale du patient." << endl;
					test = false;
					reponseInt = 1;
					InitList = cabinet.getDossiersPatient();
					while (!test && reponseInt != 0) {
						cin >> reponseInt;
						getline(cin, captage);
						for ( itDossier = cabinet.getDossiersPatient().begin(); itDossier != cabinet.getDossiersPatient().end(); itDossier++) {
							nouveauDossier = *itDossier;
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
						if (nouveauRDV.getDateRdv().getDay() != 0) {
							nouveauDossier.getRdvs().push_back(nouveauRDV);
							cout << "Rendezvous Cree" << endl;
						}
						else {
							cout << "Erreur dans la création du rendez-vous, veuillez recommencer" << endl;
						}
					}
					break;



				}
			}break;
			//2	Modifier Rdv
			//3 Supprimer Rdv
			//4 Saisir une prescription
			//5 Retour

		case(4):
			break;

		}
	}
};

int main(){
  run();
  return 0;
};


#include "CabinetMedical.h"
#include <iostream> 
#include <string>
#include <fstream>
using namespace std;




CabinetMedical lire_fichier() {
	CabinetMedical cabinet;
	ifstream fichier("cabinet.txt", ios::in);

	if (fichier)
	{

	}
	else {
		cabinet = CabinetMedical::CabinetMedical(0);
		cerr << "Impossible d'ouvrir le fichier !" << endl;
		return cabinet;
	}
};
// No
DossierPatient enregisterNouveauPatient(CabinetMedical cabinet) {
	string nomPatient, prenomPatient, adrPatient, captage;
	int telPatient, numPatient;
	char groupePatient;
	char sexe = 'X';
	bool sexePatient;
	bool test = true;
	Patient NewPatient;
	DossierPatient nouveauDossier;

	cout << " Veuillez saisir le nom du patient a enregistrer : " << endl;
	getline(cin, nomPatient);

	cout << " Veuillez saisir le prenom du nouveau patient : " << endl;
	getline(cin, prenomPatient);

	cout << " Veuillez renseigner l'adresse du patient : " << endl;
	getline(cin, adrPatient);

	cout << " Veuillez entrer le numero de telephone de contact du patient : " << endl;
	cin >> telPatient;
	getline(cin, captage);
	cout << " Veuillez renseigner le groupe sanguin du patient : " << endl;
	cin >> groupePatient;
	getline(cin, captage);
	while (sexe != 'F' && sexe != 'f' && sexe != 'M' && sexe != 'm') {
		cout << " Quel est le sexe du Patient (F : Feminin / M : Masculin) : \n" << endl;
		cin >> sexe;
		getline(cin, captage);
	}
	if (sexe == 'F' || sexe == 'f') {
		sexePatient = true;
	}
	else {
		sexePatient = false;
	}
	cout << " Veuillez entrer le numero de securite sociale du patient : \n" << endl;
	while (test || numPatient == 0) {
		test = false;
		cin >> numPatient;
		getline(cin, captage);
		if (!cabinet.getDossiersPatient().empty()){
			for (list<DossierPatient>::iterator it = cabinet.getDossiersPatient().begin(); it != cabinet.getDossiersPatient().end(); ++it) {
				nouveauDossier = *it;
				if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == (numPatient)) {
					test = true;
					break;
				}
			}
		}
		if (test || numPatient == 0) {
			cout << " Numero d'ordre deja existant ou egal a 0, veuillez en saisir un autre" << endl;
		}
	}

	NewPatient = Patient::Patient(groupePatient, numPatient, nomPatient, prenomPatient, adrPatient, sexePatient, telPatient);
	nouveauDossier = DossierPatient::DossierPatient(NewPatient);

	cout << "\n Le Dossier de Monsieur " << prenomPatient << " " << nomPatient << " a ete cree" << endl;
	return nouveauDossier;

};
// done
Medecin enregisterNouveauMedecin(CabinetMedical cabinet) {
	string nomMedecin, prenomMedecin, adrMedecin, specialiteMedecin;
	int telMedecin;
	char sexe = 'X';
	bool sexeMedecin;
	bool test = true;
	int numeroOrdreMedecin = 1;
	Medecin NewMedecin;

	cout << "Veuillez saisir le nom du medecin à enregistrer : \n" << endl;
	getline(cin, nomMedecin);

	cout << "Veuillez saisir le prenom du nouveau medecin : \n" << endl;
	getline(cin, prenomMedecin);

	cout << "Veuillez renseigner l'adresse du medecin : " << endl;
	getline(cin, adrMedecin);

	cout << "Veuillez entrer le numéro de téléphone de contact du medecin : " << endl;
	cin >> telMedecin;

	cout << "Veuillez renseigner la specialite du medecin :" << endl;
	getline(cin, specialiteMedecin);

	while (sexe != 'F' && sexe != 'f' && sexe != 'H' && sexe != 'h') {
		cout << "Quel est le sexe du medecin (F : Feminin / M : Masculin) : \n" << endl;
		cin >> sexe;
	}
	if (sexe == 'F' || sexe == 'f') {
		sexeMedecin = true;
	}
	else {
		sexeMedecin = false;
	}
	cout << "Veuillez saisir le numéro d'Ordre des Medecin : " << endl;
	while (test || numeroOrdreMedecin == 0) {
		test = false;
		cin >> numeroOrdreMedecin;
		for (list<Medecin>::iterator it = cabinet.getMedecins().begin(); it != cabinet.getMedecins().end(); ++it) {
			NewMedecin = *it;
			if (NewMedecin.getnumeroOrdreMedecin() == (numeroOrdreMedecin)) {
				test = true;
				break;
			}
		}
		if (test) {
			cout << "Numero d'ordre déjà existant ou egal à 0, veuillez en saisir un autre" << endl;
		}
	}


	NewMedecin = Medecin::Medecin(specialiteMedecin, telMedecin, nomMedecin, prenomMedecin, adrMedecin, sexeMedecin, telMedecin);

	return NewMedecin;

};
//Done
Medecin modifierMedecin(int numeroOrdreMedecin) {
	string nomMedecin, prenomMedecin, adrMedecin, specialiteMedecin;
	int telMedecin;
	char sexe = 'X';
	bool sexeMedecin;
	bool test = true;
	Medecin NewMedecin;

	cout << "Veuillez saisir le nom du medecin : \n" << endl;
	getline(cin, nomMedecin);

	cout << "Veuillez saisir le prenom du medecin : \n" << endl;
	getline(cin, prenomMedecin);

	cout << "Veuillez renseigner l'adresse du medecin : \n" << endl;
	getline(cin, adrMedecin);

	cout << "Veuillez entrer le numéro de téléphone de contact du medecin : \n" << endl;
	cin >> telMedecin;

	cout << "Veuillez renseigner la specialite du medecin : \n" << endl;
	getline(cin, specialiteMedecin);

	while (sexe != 'F' || sexe != 'f' || sexe != 'H' || sexe != 'h') {
		cout << "Quel est le sexe du medecin (F : Feminin / M : Masculin) : \n" << endl;
		cin >> sexe;
	}
	if (sexe == 'F' || sexe == 'f') {
		sexeMedecin = true;
	}
	else {
		sexeMedecin = false;
	}

	NewMedecin = Medecin::Medecin(specialiteMedecin, telMedecin, nomMedecin, prenomMedecin, adrMedecin, sexeMedecin, telMedecin);

	return NewMedecin;

};

// done
RDV enregistrerNouveauRdv(CabinetMedical cabinet) {
	RDV rendezvous = RDV::RDV();
	Date dateRDV;
	int numeroMedecin = 1;
	Medecin medecinCourant;
	bool test = false;
	int jour, mois, annee;
	cout << "Veuillez saisir le nom du medecin pour le rendez-vous \n" << endl;
	while (!test && numeroMedecin != 0) {
		cin >> numeroMedecin;
		for (list<Medecin>::iterator it = cabinet.getMedecins().begin(); it != cabinet.getMedecins().end(); ++it) {
			medecinCourant = *it;
			if (medecinCourant.getnumeroOrdreMedecin() == (numeroMedecin)) {
				test = true;
				break;
			}
		}
		if (!test) {
			cout << "Veuillez saisir un numero Valide, faites 0 pour annuler" << endl;
		}
	}

	if (numeroMedecin != 0) {

		cout << "Veuillez saisir le jour du rdv: \n" << endl;
		cin >> jour;
		cout << "Veuillez saisir le mois du rdv: \n" << endl;
		cin >> mois;
		cout << "Veuillez saisir l'annee du rdv: \n" << endl;
		cin >> annee;
		dateRDV = Date::Date(jour, mois, annee);

		rendezvous = RDV::RDV(medecinCourant, dateRDV);
	}
	else {
		rendezvous.setDateRdv(Date());
		rendezvous.getDateRdv().setDay(0);
	}

	return rendezvous;
};

void run() {
	CabinetMedical cabinet = CabinetMedical();
	CabinetMedical newcab;
	string reponseString, captage;
	int reponseInt;
	int menuChoice,sousMenuChoice;
	int choice = 0;
	bool test;
	DossierPatient nouveauDossier;
	Medecin nouveauMedecin;
	RDV nouveauRDV;
	list<Medecin>::iterator iterMed;
	list<DossierPatient> InitList;
	list<Medecin> InitMedList;

	cout << "\n Bienvenue dans l'application de Gestion de cabinet Medical" << endl;
	cabinet = lire_fichier();

	if (cabinet.getNomCabinet() == "null") {
		cout << "\n Premiere fois" << endl;
		cout << " Quel est le nom du cabinet que vous souhaitez creer ?" << endl;
		getline(cin, reponseString);
		cabinet.setNomCabinet(reponseString);
		cout << "\n A quelle Adresse se trouve ce cabinet ?" << endl;
		getline(cin, reponseString);
		cabinet.setAdresseCabinet(reponseString);
		cabinet.setDossiersPatient(InitList);
		cabinet.setMedecins(InitMedList);
	}

	while (choice != 4) {
		cout << "\n Cabinet " << cabinet.getNomCabinet() << " Bonjour, que souhaitez vous faire ?" << endl;
		cout << " 1 : Gestion Patient \n 2 : Gestion Medecin \n 3 : Gestion RDV \n 4 : Quitter \n" << endl;
		cin >> choice;
		switch (choice) {
			//No
		case(1):
			//Gestion Patient
			menuChoice = 0;
			while (menuChoice != 6) {
				cout << "\n Que souhaitez vous faire ?" << endl;
				cout << " 1 : Enregistrer un Patient \n 2 : Supprimer un Patient \n 3 : Modifier un Patient \n 4 : Afficher le dossier d'un Patient \n 5 : Retour \n" << endl;
				cin >> menuChoice;
				getline(cin, captage);

				switch (menuChoice) {

					//done
				case(1):
					cout << "\n Enregistrement patient" << endl;
					nouveauDossier = enregisterNouveauPatient(cabinet);
					if (cabinet.getDossiersPatient().empty()) {
						newcab = CabinetMedical(cabinet.getNomCabinet(),cabinet.getAdresseCabinet(),cabinet.getMedecins(), InitList.push_back(nouveauDossier))
						cabinet.getDossiersPatient().empl
					}
					else {
						cabinet.getDossiersPatient().push_back(nouveauDossier);
					}
					break;
					//No
				case(2):
					/*	cout << "Suppression patient" << endl;

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
							if (!test && reponseInt != 0) {
								cout << "numero invalide, veuillez réessayer ou tapez 0 pour retourner au menu." << endl;
							}
							else{
								cabinet.getMedecins().erase(it);
							}
						}
				case(3):
						cout << "Modification patient, taper 0 pour annuler." << endl;

						reponseInt=1;
						while (!test && reponseInt != 0) {
							cout << "Saisissez le numero du medecin à modifier" << endl;
							cin >> reponseInt;
							for (list<Medecin>::iterator it = cabinet.getMedecins().begin(); it != cabinet.getMedecins().end(); ++it) {
								nouveauMedecin = *it;
								if (nouveauMedecin.getNumeroOrdreMedecin() == (reponseInt)) {
									test = true;
									break;
								}
							}
							if (!test && reponseInt != 0) {
								cout << "numero invalide, veuillez réessayer ou tapez 0 pour retourner au menu." << endl;
							}
							else{
								cabinet.getMedecins().erase(it);
								cabinet.
							}
					break;
						} */

				case(4):
					cout << "\n Affichage des Dossiers Patients" << endl;
					if (!cabinet.getDossiersPatient().empty()) {
						cout << " Veuillez saisir le numero de securite sociale du patient que vous recherchez" << endl;
						cin >> reponseInt;
						getline(cin, captage);
						test = false;
						if (reponseInt != 0) {
							for (list<DossierPatient>::iterator it = cabinet.getDossiersPatient().begin(); it != cabinet.getDossiersPatient().end(); ++it) {
								nouveauDossier = *it;
								if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == (reponseInt)) {
									test = true;
									break;
								}
							}
							if (test) {
								nouveauDossier.afficherDossierPatient();
							}
							else {
								cout << " Numero inexistant, Operation impossible, veuillez entrer un numero existant" << endl;
							}
						}
						else {
							cout << "Numero de securite sociale egal à 0, Operation impossible, veuillez entrer un numero valide" << endl;
						}
					}
					else {
						cout << "Pas de dossiers patients cree" << endl;
					}
					break;
				}
			}break;
	

			//4 Afficher dossier patient
			//5 Retour
	//no
		case(2):
			//2 Gestion medecin
			menuChoice = 0;
			while (menuChoice != 5) {
				cout << " Que souhaitez vous faire ? \n" << endl;
				cout << " 1 : Enregistrer un Medecin \n 2 : Supprimer un Medecin \n 3 : Modifier un Medecin \n 4 : Retour \n" << endl;
				cin >> menuChoice;
				getline(cin, captage);
				switch (menuChoice) {
					//done
				case(1):
					nouveauMedecin = enregisterNouveauMedecin(cabinet);
					cabinet.getMedecins().push_back(nouveauMedecin);
					break;
					//done
				case(2):
					cout << "Suppression Medecin" << endl;

					reponseInt = 1;
					while (!test && reponseInt != 0) {
						test = false;
						cout << "Saisissez le numero du medecin à supprimer" << endl;
						cin >> reponseInt;
						for (list<Medecin>::iterator it = cabinet.getMedecins().begin(); it != cabinet.getMedecins().end(); ++it) {
							nouveauMedecin = *it;
							if (nouveauMedecin.getnumeroOrdreMedecin() == (reponseInt)) {
								test = true;
								iterMed = it;
								break;
							}
						}
						if (reponseInt != 0) {
							if (test) {
								cabinet.getMedecins().erase(iterMed);
							}
							else {
								cout << "numero invalide, veuillez réessayer ou tapez 0 pour retourner au menu." << endl;

							}
						}
					}
					//done
				case(3):
					cout << "Modification Medecin, taper 0 pour annuler." << endl;
					reponseInt = 1;
					while (!test && reponseInt != 0) {
						test = false;
						cout << "Saisissez le numero du medecin à modifier" << endl;
						cin >> reponseInt;
						for (list<Medecin>::iterator it = cabinet.getMedecins().begin(); it != cabinet.getMedecins().end(); ++it) {
							nouveauMedecin = *it;
							if (nouveauMedecin.getnumeroOrdreMedecin() == (reponseInt)) {
								test = true;
								iterMed = it;
								break;
							}
						}
						if (reponseInt != 0) {
							if (test) {
								cabinet.getMedecins().erase(iterMed);
								nouveauMedecin = modifierMedecin(reponseInt);
								cabinet.getMedecins().push_back(nouveauMedecin);
							}
							else {
								cout << "numero invalide, veuillez réessayer ou tapez 0 pour retourner au menu." << endl;
							}
						}
					}
					//no
				case(4):
					cout << "Afficher medecin, taper 0 pour annuler." << endl;
					break;
				}
			}break;


			//3 Gestion RDV
		case(3):
			menuChoice = 0;
			while (menuChoice != 5) {
				cout << " Bonjour, que souhaitez vous faire ?" << endl;

				cin >> menuChoice;
				getline(cin, captage);
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
						if (nouveauRDV.getDateRdv().getDay() != 0) {
							nouveauDossier.getRdvs().push_back(nouveauRDV);
							cout << "Rendezvous Cree" << endl;
						}
						else {
							cout << "Erreur dans la création du rendez-vous, veuillez recommencer" << endl;
						}
					}
					break;



				}
			}break;
			//2	Modifier Rdv
			//3 Supprimer Rdv
			//4 Saisir une prescription
			//5 Retour

		case(4): //Quitter le programme
			break;

		}
	};
};
	// No
//done
int main( int argc, const char* argv []){
  run();
  return 0;
};

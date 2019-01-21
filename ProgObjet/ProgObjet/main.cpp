#include "CabinetMedical.h"
#include <iostream> 
#include <string>
#include <fstream>
using namespace std;

/*
// *************************************************************************************
// Fonction pour ouvrir le fichier de sauvegarde du Cabinet Medicale
// *************************************************************************************
CabinetMedical lire_fichier() {
	CabinetMedical cabinet;
	ifstream fichier("cabinet.txt", ios::in);

	if (fichier)
	{
		string nomCabinet = nomCabinet;
          int adresseCabinet = adresseCabinet;

          fichier << nomCabinet << adresseCabinet;
 
          fichier.close();
		
	}
	else {
		cabinet = CabinetMedical::CabinetMedical(0);
		cerr << "Impossible d'ouvrir le fichier !" << endl;
		return cabinet;
	}
};
*/
// *************************************************************************************
// Fonction pour l'enregistrement d'un nouveau patient
// *************************************************************************************
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

	cout << "Veuillez saisir le nom du patient a enregistrer : " << endl;
	getline(cin, nomPatient);

	cout << "Veuillez saisir le prenom du nouveau patient : " << endl;
	getline(cin, prenomPatient);

	cout << "Veuillez renseigner l'adresse du patient : " << endl;
	getline(cin, adrPatient);

	cout << "Veuillez entrer le numero de telephone de contact du patient : " << endl;
	cin >> telPatient;
	cin.ignore();
	cout << "Veuillez renseigner le groupe sanguin du patient : " << endl;
	cin >> groupePatient;
	cin.ignore();
	while (sexe != 'F' && sexe != 'f' && sexe != 'M' && sexe != 'm') {
		cout << "Quel est le sexe du Patient (F : Feminin / M : Masculin) : " << endl;
		cin >> sexe;
		getline(cin, captage);
	}
	if (sexe == 'F' || sexe == 'f') {
		sexePatient = true;
	}
	else {
		sexePatient = false;
	}
	cout << "Veuillez entrer le numero de securite sociale du patient : " << endl;
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
			cout << "Numero d'ordre deja existant ou egal a 0, veuillez en saisir un autre : " << endl;
		}
	}

	NewPatient = Patient::Patient(numPatient, groupePatient , nomPatient, prenomPatient, adrPatient, sexePatient, telPatient);
	nouveauDossier = DossierPatient::DossierPatient(NewPatient);

	cout << "Le Dossier de : " << nouveauDossier.getPatient().getPrenom() << " " << nomPatient << " a ete cree." << endl;
	return nouveauDossier;

};

// *************************************************************************************
// Fonction pour la modification d'un patient existant
// *************************************************************************************
DossierPatient modifierPatient(int numPatient) {
	string nomPatient, prenomPatient, adrPatient, captage;
	int telPatient;
	char groupePatient;
	char sexe = 'X';
	bool sexePatient;
	Patient NewPatient;
	DossierPatient nouveauDossier;

	cout << "Veuillez saisir le nom de ce patient  : " << endl;
	getline(cin, nomPatient);

	cout << "Veuillez saisir le prenom du  patient : " << endl;
	getline(cin, prenomPatient);

	cout << "Veuillez renseigner l'adresse du patient : " << endl;
	getline(cin, adrPatient);

	cout << "Veuillez entrer le numero de telephone de contact du patient : " << endl;
	cin >> telPatient;
	getline(cin, captage);
	cout << "Veuillez renseigner le groupe sanguin du patient : " << endl;
	cin >> groupePatient;
	getline(cin, captage);
	while (sexe != 'F' && sexe != 'f' && sexe != 'M' && sexe != 'm') {
		cout << "Quel est le sexe du Patient (F : Feminin / M : Masculin) : " << endl;
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

	cout << "Le Dossier de : " << nouveauDossier.getPatient().getPrenom() << " " << nomPatient << " a ete modifie." << endl;
	return nouveauDossier;
};
// *************************************************************************************
// Fonction pour l'enregistrement d'un nouveau medecin
// *************************************************************************************
Medecin enregisterNouveauMedecin(CabinetMedical cabinet) {
	string nomMedecin, prenomMedecin, adrMedecin, specialiteMedecin, captage;
	int telMedecin;
	char sexe = 'X';
	bool sexeMedecin;
	bool test = true;
	int numeroOrdreMedecin = 1;
	Medecin NewMedecin;
	list<Medecin> InitList;

		cout << "Veuillez saisir le nom du medecin a enregistrer : " << endl;
	getline(cin, nomMedecin);

	cout << "Veuillez saisir le prenom du nouveau medecin : " << endl;
	getline(cin, prenomMedecin);

	cout << "Veuillez renseigner l'adresse du medecin : " << endl;
	getline(cin, adrMedecin);

	cout << "Veuillez entrer le numero de telephone de contact du medecin : " << endl;
	cin >> telMedecin;
	getline(cin, captage);
	cout << "Veuillez renseigner la specialite du medecin :" << endl;
	getline(cin, specialiteMedecin);

	while (sexe != 'F' && sexe != 'f' && sexe != 'M' && sexe != 'm') {
		cout << "Quel est le sexe du medecin (F : Feminin / M : Masculin) : " << endl;
		cin >> sexe;
	}
	if (sexe == 'F' || sexe == 'f') {
		sexeMedecin = true;
	}
	else {
		sexeMedecin = false;
	}
	cout << "Veuillez saisir le numero d'Ordre des Medecin : " << endl;
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
			cout << "Numero d'ordre deja existant ou egal a 0, veuillez en saisir un autre : " << endl;
		}
	}


	NewMedecin = Medecin::Medecin(specialiteMedecin, numeroOrdreMedecin, nomMedecin, prenomMedecin, adrMedecin, sexeMedecin, telMedecin);
	cout << "Le nouveau medecin, Docteur " << NewMedecin.getNom() << " a ete cree." << endl;
	return NewMedecin;
};

// *************************************************************************************
// Fonction pour la modification d'un medecin existant
// *************************************************************************************
Medecin modifierMedecin(int numeroOrdreMedecin) {
	string nomMedecin, prenomMedecin, adrMedecin, specialiteMedecin,captage;
	int telMedecin;
	char sexe = 'X';
	bool sexeMedecin;
	bool test = true;
	Medecin NewMedecin;

	cout << "Veuillez saisir le nom du medecin : " << endl;
	getline(cin, nomMedecin);

	cout << "Veuillez saisir le prenom du medecin : " << endl;
	getline(cin, prenomMedecin);

	cout << "Veuillez renseigner l'adresse du medecin : " << endl;
	getline(cin, adrMedecin);

	cout << "Veuillez entrer le numero de telephone de contact du medecin : " << endl;
	cin >> telMedecin;
	getline(cin, captage);

	cout << "Veuillez renseigner la specialite du medecin : " << endl;
	getline(cin, specialiteMedecin);

	while (sexe != 'F' || sexe != 'f' || sexe != 'H' || sexe != 'h') {
		cout << "Quel est le sexe du medecin (F : Feminin / M : Masculin) : " << endl;
		cin >> sexe;
		if (sexe == 'F' || sexe == 'f') {
			sexeMedecin = true;
		}
		else {
			sexeMedecin = false;
		}
	}

	NewMedecin = Medecin::Medecin(specialiteMedecin, numeroOrdreMedecin, nomMedecin, prenomMedecin, adrMedecin, sexeMedecin, telMedecin);

	return NewMedecin;

};

// *************************************************************************************
// Fonction pour l'enregistrement d'un nouveau rendez-vous
// *************************************************************************************
RDV enregistrerNouveauRdv(Medecin medecin, int id) {
	string captage;
	RDV rendezvous = RDV::RDV();
	Date dateRDV;
	
	int jour, mois, annee;
		cout << "Veuillez saisir le jour du rdv: " << endl;
		cin >> jour;
		getline(cin, captage);
		cout << "Veuillez saisir le mois du rdv: " << endl;
		cin >> mois;
		getline(cin, captage);
		cout << "Veuillez saisir l'annee du rdv: " << endl;
		cin >> annee;
		getline(cin, captage);
		dateRDV = Date::Date(jour, mois, annee);
		rendezvous = RDV::RDV(medecin, dateRDV, id);

	return rendezvous;
};

// *************************************************************************************
// Fonction pour l'enregistrement d'une prescription
// *************************************************************************************
Prescription enregistrerPrescription() {
	Prescription sortie;
	Posologie posologie;
	Date date;
	Medicament medicament;
	string typePrescription, jsm, temps, nom, laboratoire,captage;
	int nombreDePrises,mois, jour, annee;

	typePrescription = "medicale";
	cout << "Quel est la frequence de prise du traitement (Jour/Mois/Annees) ? : " << endl;
	getline(cin, jsm);
	cout << "Pendant combien de temps dois on prendre le traitement ? :" << endl;
	getline(cin, temps);
	cout << "Quel est le nom du traitement : " << endl;
	getline(cin, nom);
	cout << "Quelle est le laboratoire du medicament ?" << endl;
	getline(cin, laboratoire);
	cout << "Combien de prises doit prendre le patient par "<< jsm <<" ? : " << endl;
	cin >> nombreDePrises;
	getline(cin, captage);
	cout << "Quel est le jour du debut du traitement ? " << endl;
	cin >> jour;
	getline(cin, captage);
	cout << "Quel est le mois du debut du traitement ? " << endl;
	cin >> mois;
	getline(cin, captage);
	cout << "Quel est l'annee du debut du traitement ? " << endl;
	cin >> annee;
	getline(cin, captage);

	posologie = Posologie(nombreDePrises, jsm, temps);
	date = Date(mois, jour, annee);
	medicament = Medicament(nom, laboratoire);
	sortie = Prescription(typePrescription, posologie, date, medicament);
	return sortie;
};
// *************************************************************************************
// Programme principal
// *************************************************************************************
void run() {
	CabinetMedical cabinet = CabinetMedical();
	CabinetMedical newcab;
	string reponseString, captage;
	int reponseInt;
	int reponseInt2;
	int reponseInt3;
	int reponseInt4;
	int menuChoice;
	int choice = 0;
	bool test;
	DossierPatient nouveauDossier;
	Medecin nouveauMedecin;
	RDV nouveauRDV;
	list<DossierPatient> InitList;
	list<Medecin> InitMedList;
	list<RDV> InitRDV;
	list<Prescription> initPres;
	list<DossierPatient>::iterator itDossier;
	list<Medecin>::iterator iterMed;
	list<RDV>::iterator iterRDV;


	// *************************************************************************************
	// Creation du cabinet pour le premier demarrage de l'application
	// *************************************************************************************'
	cout << "Bienvenue dans l'application de Gestion de cabinet Medical" << endl;
//	cabinet = lire_fichier();

//	if (cabinet.getNomCabinet() == "null") {
//		cout << "Premiere fois" << endl;
		cout << " Quel est le nom du cabinet que vous souhaitez creer ?" << endl;
		getline(cin, reponseString);
		cabinet.setNomCabinet(reponseString);
		cout << "A quelle Adresse se trouve ce cabinet ?" << endl;
		getline(cin, reponseString);
		cabinet.setAdresseCabinet(reponseString);
		cabinet.setDossiersPatient(InitList);
		cabinet.setMedecins(InitMedList);
//	}

	// *************************************************************************************
	// Menu Principal de l'application
	// *************************************************************************************'
	while (choice != 4) {
		cout << "Cabinet " << cabinet.getNomCabinet() << " Bonjour, que souhaitez vous faire ?" << endl;
		cout << " 1 : Gestion Patient \n 2 : Gestion Medecin \n 3 : Gestion RDV \n 4 : Quitter " << endl;
		cin >> choice;
		switch (choice) {

		// *************************************************************************************
		// Menu gestion Patient
		// *************************************************************************************
		case(1):
			menuChoice = 0;
			while (menuChoice != 5) {
				cout << "Que souhaitez vous faire ?" << endl;
				cout << " 1 : Enregistrer un Patient \n 2 : Supprimer un Patient \n 3 : Modifier un Patient \n 4 : Rechercher le dossier d'un patient \n 5 : Retour " << endl;
				cin >> menuChoice;
				getline(cin, captage);
				switch (menuChoice) {

					// *************************************************************************************
					// Enregistrement d'un nouveau patient
					// *************************************************************************************
					case(1):
						cout << "Enregistrement patient" << endl;
						nouveauDossier = enregisterNouveauPatient(cabinet);
						InitList = cabinet.getDossiersPatient();
						InitList.push_back(nouveauDossier);
						cabinet.setDossiersPatient(InitList);
						break;

					// *************************************************************************************
					// Suppression d'un patient existant
					// *************************************************************************************
					case(2):
						cout << "Suppression patient" << endl;
						InitList = cabinet.getDossiersPatient();
						if (!InitList.empty()) {
							reponseInt = 1;
							test = false;
							while (!test && reponseInt != 0) {
								cout << "Saisissez le numero du Patient a supprimer : " << endl;
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
									cout << "Numero invalide, veuillez reessayer ou tapez 0 pour retourner au menu : " << endl;
								}
								else {
									InitList.erase(itDossier);
									cabinet.setDossiersPatient(InitList);
								}
							}
						}
						else {
							cout << "Il n'y a pas de patient a supprimer." << endl;
						}
						break;

					// *************************************************************************************
					// Modification d'un patient existant
					// *************************************************************************************
					case(3):
							cout << "Modification patient, taper 0 pour annuler." << endl;

							if (!InitList.empty()) {
								reponseInt = 1;
								test = false;
								while (!test && reponseInt != 0) {
									cout << "Saisissez le numero du Patient a modifier : " << endl;
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
										cout << "Numero invalide, veuillez reessayer ou tapez 0 pour retourner au menu : " << endl;
									}
									else {
										InitList.erase(itDossier);
										InitList.push_back(modifierPatient(reponseInt));
										cabinet.setDossiersPatient(InitList);
									}
								}
							}
							else {
							cout << "Il n'y a pas de patient a modifier." << endl;
							}

						break;

					// *************************************************************************************
					// Affichage d'un dossier patient
					// *************************************************************************************
					case(4):
						cout << "Recherche de Dossier Patient" << endl;
						InitList = cabinet.getDossiersPatient();
						
						if (!InitList.empty() ) {
							cout << "Veuillez saisir le numero de securite sociale du patient que vous recherchez : " << endl;
							cin >> reponseInt;
							getline(cin, captage);
							test = false;

							if (reponseInt != 0) {
								for (itDossier = InitList.begin(); itDossier != InitList.end(); itDossier++) {
									nouveauDossier = *itDossier;
									if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == (reponseInt)) {
										test = true;
										break;
									}
								}
								if (test) {
									nouveauDossier.afficherDossierPatient();
								}
								else {
									cout << "Numero inexistant, Operation impossible, veuillez entrer un numero existant : " << endl;
								}
							}
						}
						else {
							cout << "Pas de dossiers patients cree." << endl;
						}
						break;
					}
				}
			break;

		// *************************************************************************************
		// Menu Gestion Medecin
		// *************************************************************************************
		case(2):
			
			menuChoice = 0;
			while (menuChoice != 5) {
				cout << "Que souhaitez vous faire ? " << endl;
				cout << " 1 : Enregistrer un Medecin \n 2 : Supprimer un Medecin \n 3 : Modifier un Medecin \n 4 : Rechercher les information d'un Medecin \n 5: Retour "  << endl;
				cin >> menuChoice;
				cin.ignore();
				switch (menuChoice) {

				// *************************************************************************************
				// Enregistrement d'un nouveau medecin
				// *************************************************************************************
				case(1):
					nouveauMedecin = enregisterNouveauMedecin(cabinet);
					InitMedList = cabinet.getMedecins();
					InitMedList.push_back(nouveauMedecin);
					cabinet.setMedecins(InitMedList);
					break;

				// *************************************************************************************
				// Suppression d'un medecin existant
				// *************************************************************************************
				case(2):
					cout << "Suppression Medecin" << endl;

					reponseInt = 1;
					InitMedList = cabinet.getMedecins();
					if (!InitMedList.empty()) {
						test = false;
						while (!test && reponseInt != 0) {
							cout << "Saisissez le numero du medecin a supprimer : " << endl;
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
									cout << "Numero invalide, veuillez reessayer ou tapez 0 pour retourner au menu : " << endl;

								}
							}
						}
					}
					else {
						cout << "Il n'y a pas de medecins actuellement enregistre dans le logiciel." << endl;
					}
					break;

				// *************************************************************************************
				// Modification d'un medecin existant
				// *************************************************************************************
				case(3):
					cout << "Modification Medecin, taper 0 pour annuler." << endl;
					reponseInt = 1;
					InitMedList = cabinet.getMedecins();
					if (!InitMedList.empty()) {
						test = false;
						while (!test && reponseInt != 0) {
							cout << "Saisissez le numero du medecin a modifier : " << endl;
							cin >> reponseInt;
							getline(cin, captage);
							for (iterMed = InitMedList.begin(); iterMed != InitMedList.end(); ++iterMed) {
								nouveauMedecin = *iterMed;
								if (nouveauMedecin.getnumeroOrdreMedecin() == (reponseInt)) {
									test = true;
									break;
								}
							}
							if (test) {
								InitMedList.erase(iterMed);
								InitMedList.push_back(modifierMedecin(reponseInt));
								cabinet.setMedecins(InitMedList);
							}
							else {
								cout << "Numero invalide, veuillez reessayer ou tapez 0 pour retourner au menu : " << endl;
							}
						}
					}
					break;

				// *************************************************************************************
				// Afficher un medecin
				// *************************************************************************************
				case(4):
					cout << "Recherche de Medecin" << endl;
					InitMedList = cabinet.getMedecins();
					if (!InitMedList.empty()) {
						cout << "Veuillez saisir le numero d'Ordre du medecin que vous recherchez : " << endl;
						cin >> reponseInt;
						test = false;

						if (reponseInt != 0) {
							for (iterMed = InitMedList.begin(); iterMed != InitMedList.end(); ++iterMed) {
								nouveauMedecin = *iterMed;
								if (nouveauMedecin.getnumeroOrdreMedecin() == (reponseInt)) {
									test = true;
									break;
								}
							}
							if (test) {
								nouveauMedecin.afficherMedecin();
							}
							else {
								cout << "Numero inexistant, Operation impossible, veuillez entrer un numero existant : " << endl;
							}
						}
					}
					else {
						cout << "Il n'existe pas de Medecins dans la base actuelle." << endl;
					}
					break;
				}
			
			}break;

		// *************************************************************************************
		// Menu Gestion RDV
		// *************************************************************************************
		case(3):
			if (!cabinet.getMedecins().empty() && !cabinet.getDossiersPatient().empty()) {
				menuChoice = 0;
				while (menuChoice != 4) {
					cout << "Bonjour, que souhaitez vous faire ?" << endl;
					cout << " 1 : Creer un RDV \n 2 : Supprimer un RDV \n 3 : Mettre a jour le RDV \n 4 : Retour " << endl;
					cin >> menuChoice;
					cin.ignore();
					switch (menuChoice) {

					// *************************************************************************************
					// Enregistrement d'un nouveau rendez-vous
					// *************************************************************************************
					case(1):

						reponseInt = 1;
						test = false;
						InitList = cabinet.getDossiersPatient();
						cout << "Veuillez indiquer le numero de Securite sociale du patient : " << endl;
						while (reponseInt != 0 && !test) {
							cin >> reponseInt;
							getline(cin, captage);
							for (itDossier = InitList.begin(); itDossier != InitList.end(); itDossier++) {
								nouveauDossier = *itDossier;
								if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == reponseInt) {
									test = true;
									break;
								}
							}
							if (!test && reponseInt != 0) {
								cout << "Numero invalide, veuillez reessayer ou tapez 0 pour retourner au menu." << endl;
							}
						}
						reponseInt2 = 1;
						test = false;
						InitMedList = cabinet.getMedecins();
						while (reponseInt != 0 && reponseInt2 != 0 && !test) {
							cout << "Saisissez le numero du medecin qui prend le rendez-vous : " << endl;
							cin >> reponseInt2;
							getline(cin, captage);
							for (iterMed = InitMedList.begin(); iterMed != InitMedList.end(); ++iterMed) {
								nouveauMedecin = *iterMed;
								if (nouveauMedecin.getnumeroOrdreMedecin() == (reponseInt2)) {
									test = true;
									break;
								}
							}
							if (!test && reponseInt2 != 0) {
								cout << "Numero invalide, veuillez reessayer ou tapez 0 pour retourner au menu." << endl;
							}
							else {
								if (test) {

									InitRDV = nouveauDossier.getRdvs();
									if (!InitRDV.empty()) {
										reponseInt3 = 1;
										while (reponseInt3 != 0 && test) {
											cout << "Donnez un Identifiant au rendez-vous " << endl;
											cin >> reponseInt3;
											getline(cin, captage);
											test = false;
											for (iterRDV = InitRDV.begin(); iterRDV != InitRDV.end(); ++iterRDV) {
												nouveauRDV = *iterRDV;
												if (nouveauRDV.getID() == (reponseInt3)) {
													test = true;
													break;
												}
											}
											if (test && reponseInt3 != 0) {
												cout << "Numero deja utilise, veuillez reessayer ou tapez 0 pour retourner au menu." << endl;
											}
											else {
												if (!test) {
													InitList.erase(itDossier);
													nouveauRDV = enregistrerNouveauRdv(nouveauMedecin, reponseInt3);
													InitRDV.push_back(nouveauRDV);
													nouveauDossier.setRdvs(InitRDV);
													InitList.push_back(nouveauDossier);
													cabinet.setDossiersPatient(InitList);
												}
											}
										}
									}
									else {
										cout << "Donnez un Identifiant au rendez-vous " << endl;
										cin >> reponseInt3;
										InitList.erase(itDossier);
										nouveauRDV = enregistrerNouveauRdv(nouveauMedecin, reponseInt3);
										InitRDV.push_back(nouveauRDV);
										nouveauDossier.setRdvs(InitRDV);
										InitList.push_back(nouveauDossier);
										cabinet.setDossiersPatient(InitList);
									}
									test = true;
								}
							}
						}
						break;

					// *************************************************************************************
					// Supprimer un rendez-vous existant
					// *************************************************************************************
					case(2):
						reponseInt = 1;
						test = false;
						InitList = cabinet.getDossiersPatient();
						cout << "Veuillez indiquer le numero de Securite sociale du patient : " << endl;
						while (reponseInt != 0 && !test) {
							cin >> reponseInt;
							getline(cin, captage);
							for (itDossier = InitList.begin(); itDossier != InitList.end(); itDossier++) {
								nouveauDossier = *itDossier;
								if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == reponseInt) {
									test = true;
									break;
								}
							}
							if (!test && reponseInt != 0) {
								cout << "Numero invalide, veuillez reessayer ou tapez 0 pour retourner au menu." << endl;
							}
						}
						reponseInt2 = 1;
						test = false;
						InitMedList = cabinet.getMedecins();
						while (reponseInt != 0 && reponseInt2 != 0 && !test) {
							cout << "Saisissez le numero du medecin qui prend le rendez-vous : " << endl;
							cin >> reponseInt2;
							getline(cin, captage);
							for (iterMed = InitMedList.begin(); iterMed != InitMedList.end(); ++iterMed) {
								nouveauMedecin = *iterMed;
								if (nouveauMedecin.getnumeroOrdreMedecin() == (reponseInt)) {
									test = true;
									break;
								}
							}
							if (!test && reponseInt2 != 0) {
								cout << "Numero invalide, veuillez reessayer ou tapez 0 pour retourner au menu." << endl;
							}
							else {
								if (test) {

									InitRDV = nouveauDossier.getRdvs();
									if (!InitRDV.empty()){
										reponseInt3 = 1;
										test = false;
										while (reponseInt3 !=0 && !test) {
											cout << "Donnez un Identifiant au rendez-vous " << endl;
											cin >> reponseInt3;
											getline(cin, captage);
											for (iterRDV = InitRDV.begin(); iterRDV != InitRDV.end(); ++iterRDV) {
												nouveauRDV = *iterRDV;
												if (nouveauRDV.getID() == (reponseInt3)) {
													test = true;
													break;
												}
											}
											if (!test && reponseInt3 != 0) {
												cout << "Numero non valide, veuillez reessayer ou tapez 0 pour retourner au menu." << endl;
											}
											else {
												if (test) {
													InitList.erase(itDossier);
													InitRDV.erase(iterRDV);
													nouveauDossier.setRdvs(InitRDV);
													InitList.push_back(nouveauDossier);
													cabinet.setDossiersPatient(InitList);
												}
											}
										}
									}
									else {
										cout << "Il n'existe aucun rendez vous pour ce patient" << endl;
									}
									test = true;
								}
							}
						}
						break;

					// *************************************************************************************
					// Mise a jour d'un rendez-vous existant
					// *************************************************************************************
					case(3):
						reponseInt = 1;
						test = false;
						InitList = cabinet.getDossiersPatient();
						cout << "Veuillez indiquer le numero de Securite sociale du patient : " << endl;
						while (reponseInt != 0 && !test) {
							cin >> reponseInt;
							getline(cin, captage);
							for (itDossier = InitList.begin(); itDossier != InitList.end(); itDossier++) {
								nouveauDossier = *itDossier;
								if (nouveauDossier.getPatient().getNumeroSecuriteSociale() == reponseInt) {
									test = true;
									break;
								}
							}
							if (!test && reponseInt != 0) {
								cout << "Numero invalide, veuillez reessayer ou tapez 0 pour retourner au menu." << endl;
							}
						}
						reponseInt2 = 1;
						test = false;
						InitMedList = cabinet.getMedecins();
						while (reponseInt != 0 && reponseInt2 != 0 && !test) {
							cout << "Saisissez le numero du medecin qui prend le rendez-vous : " << endl;
							cin >> reponseInt2;
							getline(cin, captage);
							for (iterMed = InitMedList.begin(); iterMed != InitMedList.end(); ++iterMed) {
								nouveauMedecin = *iterMed;
								if (nouveauMedecin.getnumeroOrdreMedecin() == (reponseInt)) {
									test = true;
									break;
								}
							}
							if (!test && reponseInt2 != 0) {
								cout << "Numero invalide, veuillez reessayer ou tapez 0 pour retourner au menu." << endl;
							}
							else {
								if (test) {

									InitRDV = nouveauDossier.getRdvs();
									if (!InitRDV.empty()) {
										reponseInt3 = 1;
										test = false;
										while (reponseInt3 != 0 && !test) {
											cout << "Donnez un Identifiant au rendez-vous " << endl;
											cin >> reponseInt3;
											getline(cin, captage);
											for (iterRDV = InitRDV.begin(); iterRDV != InitRDV.end(); ++iterRDV) {
												nouveauRDV = *iterRDV;
												if (nouveauRDV.getID() == (reponseInt3)) {
													test = true;
													break;
												}
											}
											if (!test && reponseInt3 != 0) {
												cout << "Numero non valide, veuillez reessayer ou tapez 0 pour retourner au menu." << endl;
											}
											else {
												if (test) {
													cout << "Voulez vous : \n  1 : modifier le rendez vous \n 2 : ajouter des prescriptions ? \n 3 : sortir" << endl;
													cin >> reponseInt4;
													getline(cin, captage);

													switch (reponseInt4){
													case(1):
														InitList.erase(itDossier);
														InitRDV.erase(iterRDV);
														InitRDV.push_back(nouveauRDV);
														nouveauDossier.setRdvs(InitRDV);
														InitList.push_back(nouveauDossier);
														cabinet.setDossiersPatient(InitList);
														break;
													case(2):
														InitList.erase(itDossier);
														InitRDV.erase(iterRDV);
														initPres = nouveauRDV.getPrescriptions();
														initPres.push_back(enregistrerPrescription());
														nouveauRDV.setPrescriptions(initPres);
														InitRDV.push_back(nouveauRDV);
														nouveauDossier.setRdvs(InitRDV);
														InitList.push_back(nouveauDossier);
														cabinet.setDossiersPatient(InitList);
														break;

													}
												}
											}
										}
									}
									else {
										cout << "Il n'existe aucun rendez vous pour ce patient" << endl;
									}
									test = true;
								}
							}
						}
						break;
					}
				}
			}
			else {
				cout << "Impossible de creer un rendez-vous sans Patient et Medecins !" << endl;
			}
			break;
		}
		

		// *************************************************************************************
		// Sortie du programme
		// *************************************************************************************
	}
};

int main(){
  run();
  return 0;
};

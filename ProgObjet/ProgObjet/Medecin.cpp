// Auteur : DENIAUD B. - AIRAULT D.

#include "Medecin.h" 
using namespace std;


Medecin::Medecin() {};

// Constructeur de Medecin
Medecin::Medecin( string specialite, int numeroOrdreMedecin, string nom, string prenom, string adresse, bool sexe, int num) : Personne(nom, prenom,adresse, sexe, num){
	Medecin::setSpecialite(specialite);
	Medecin::setnumeroOrdreMedecin(numeroOrdreMedecin);
};


// Accesseurs

int Medecin::getnumeroOrdreMedecin(){
	return this->numeroOrdreMedecin;
};

string Medecin::getSpecialite(){
	return this->specialite;
};

void Medecin::setnumeroOrdreMedecin(int numeroOrdreMedecin){
	this->numeroOrdreMedecin=numeroOrdreMedecin;
};

void Medecin::setSpecialite(string specialite){ 
	this->specialite=specialite;
};

// Affichage d'un objet de type Medecin
void Medecin::afficherMedecin(){

	cout << "    nom du medecin : " << Medecin::getNom() << endl;
	cout << "    prenom du medecin : " << Medecin::getPrenom() << endl;
	if (getSexe()) {
		cout << "    Sexe : Femme" << endl;
	}
	else {
		cout << "    Sexe : Homme" << endl;
	}
	cout << "    specialite : " << Medecin::getSpecialite() << endl;
	cout << "    numero d'ordre du medecin : " << Medecin::getnumeroOrdreMedecin() << endl;
	cout << "    adresse : " << Medecin::getAdresse() << endl;
	cout << "    telephone : " << Medecin::getNumeroDeTelephone() << endl;
	 
}

/*
// A faire plus tard.
// Enregistrer un objet de type Medecin dans un fichier
void Medecin::afficherMedecinFichier(string nomFichier){
	ofstream outputFile(nomFichier.c_str(), ios::app); // Ouvrir le fichier
	if(outputFile){ // Si l'ouverture a fonctionnee, ecrire à la suite le medecin
		outputFile << "		* Le medecin est " << this->nom << endl;
		outputFile.close(); // Fermer le fichier
	}
}
*/

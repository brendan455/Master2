// Auteur : DENIAUD B. - AIRAULT D.

#include "Medecin.h"
#include <iostream> 
using namespace std;


// Initialisation du compteur pour la numérotation des objets de type Medecin
int Medecin::compteur=0;

// Constructeur de Medecin
Medecin::Medecin(int ID, string nom, string prenom, int numeroOrdreMedecin, string specialite){
	this->ID=this->compteur; 
	this->nom=nom;
	this->prenom=prenom;
	this->numeroOrdreMedecin=numeroOrdreMedecin;
	this->specialite=specialite;
	this->compteur=this->compteur+1;
}

// Accesseurs

string Medecin::getIDMedecin(){ // Récupérer les ID de Medecin
	return this->ID;
}

string Medecin::getnomMedecin(){ // Récupérer les noms de Medecin
	return this->nom;
}

string Medecin::getprenomMedecin(){ // Récupérer les prénoms de Medecin
	return this->prenom;
}

int Medecin::getnumeroOrdreMedecin(){ // Récupérer numéros d'ordre de Medecin
	return this->numeroOrdreMedecin;
}

string Medecin::getspecialite(){ // Récupérer les specialités de Medecin
	return this->specialite;
}

void Medecin::setIDMedecin(int ID){ // Changer l'ID d'un medecin
	this->ID=ID;
}

void Medecin::setnomMedecin(string nom){ // Changer un nom de medecin
	this->nom=nom;
}

void Medecin::setprenomMedecin(string prenom){ // Changer un prénom de medecin
	this->prenom=prenom;
}

void Medecin::setnnumeroOrdreMedecin(int numeroOrdreMedecin){ // Changer numéro d'ordre de medecin
	this->numeroOrdreMedecin=numeroOrdreMedecin;
}

void Medecin::setSpecialite(string specialite){ // Changer la spécialité d'un medecin
	this->specialite=specialite;
}

// Affichage d'un objet de type Medecin
void Medicament::afficherMedecin(){
	cout << "	- L'ID du medecin est : "<< this->ID <<" Le nom du medecin est : " << this->nom_medecin << "Le prénom du medecin est : " << this->prenom_medecin << "Le numéro d'ordre du medecin est : " << this->numeroOrdreMedecin << " La spécialité du medecin est : " < this->specialite << endl;	
}


// Enregistrer un objet de type Medecin dans un fichier
void Medecin::afficherMedecinFichier(string nomFichier){
	ofstream outputFile(nomFichier.c_str(), ios::app); // Ouvrir le fichier
	if(outputFile){ // Si l'ouverture a fonctionnée, écrire à la suite le medecin
		outputFile << "		* Le medecin est " << this->nom << endl;
		outputFile.close(); // Fermer le fichier
	}
}
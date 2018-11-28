// Auteur : DENIAUD B. - AIRAULT D.

#include "Medicament.h"
#include <iostream> 
using namespace std;


// Initialisation du compteur pour la numérotation des objets de type Medicament
int Medicament::compteur=0;

// Constructeur de Medicament
Medicament::Medicament(int ID, string nom, string laboratoire){
	this->ID=this->compteur; 
	this->nom=nom;
	this->laboratoire=laboratoire;
	this->compteur=this->compteur+1;
}

// Accesseurs

string Medicament::getIDMedicament(){ // Récupérer les ID de Medicament
	return this->ID;
}

string Medicament::getnomMedicament(){ // Récupérer les noms de Medicament
	return this->nom;
}

string Medicament::getlaboratoireMedicament(){ // Récupérer les laboratoires de Medicament
	return this->laboratoire;
}


void Medicament::setIDMedicament(int ID){ // Changer les ID de Medicament
	this->ID=ID;
}

void Medicament::setnomMedicament(string nom){ // Changer les noms de Medicament
	this->nom=nom;
}

void Medicament::setlaboratoireMedicament(string laboratoire){ // Changer les laboratoires de Medicament
	this->laboratoire=laboratoire;
}


// Affichage d'un objet de type Medicament
void Medicament::afficherMedicament(){
	cout << "	- L'ID du médicament est : "<< this->ID <<" Le nom du médicament est : " << this->nom << "Le laboratoire qui fabrique le médicament est : " << this->laboratoire << endl;	
}


// Enregistrer un objet de type Medicament dans un fichier
void Medecin::afficherMedicamentFichier(string nomFichier){
	ofstream outputFile(nomFichier.c_str(), ios::app); // Ouvrir le fichier
	if(outputFile){ // Si l'ouverture a fonctionnée, écrire le nom du medicament
		outputFile << "		* Le medicament est " << this->nom << endl;
		outputFile.close(); // Fermer le fichier
	}
}

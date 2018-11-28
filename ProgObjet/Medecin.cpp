// Auteur : DENIAUD B. - AIRAULT D.

#include "Medecin.h" 
using namespace std;


// Constructeur de Medecin
Medecin::Medecin( string nom, int numeroOrdreMedecin){
	setnomMedecin(nom);
	setnumeroOrdreMedecin(numeroOrdreMedecin);
	setprenomMedecin("inconnu");
	setSpecialite("inconnue");
}

// Accesseurs

string Medecin::getnomMedecin(){ // Récupérer les prénoms de Medecin
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


void Medecin::setnomMedecin(string nom){ // Changer un nom de medecin
	this->nom=nom;
}

void Medecin::setprenomMedecin(string prenom){ // Changer un prénom de medecin
	this->prenom=prenom;
}

void Medecin::setnumeroOrdreMedecin(int numeroOrdreMedecin){ // Changer numéro d'ordre de medecin
	this->numeroOrdreMedecin=numeroOrdreMedecin;
}

void Medecin::setSpecialite(string specialite){ // Changer la spécialité d'un medecin
	this->specialite=specialite;
}

// Affichage d'un objet de type Medecin
void Medicament::afficherMedecin(){
	cout << "	- Le nom du medecin est : " << getnomMedecin() << "Le prénom du medecin est : " 
		<< getprenomMedecin() << "Le numéro d'ordre du medecin est : " 
		<< getnumeroOrdreMedecin() << " La spécialité du medecin est : " < getspecialite() << endl;	
}


// A faire plus tard.
// Enregistrer un objet de type Medecin dans un fichier
void Medecin::afficherMedecinFichier(string nomFichier){
	ofstream outputFile(nomFichier.c_str(), ios::app); // Ouvrir le fichier
	if(outputFile){ // Si l'ouverture a fonctionnée, écrire à la suite le medecin
		outputFile << "		* Le medecin est " << this->nom << endl;
		outputFile.close(); // Fermer le fichier
	}
}

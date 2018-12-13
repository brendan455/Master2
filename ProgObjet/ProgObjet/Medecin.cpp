// Auteur : DENIAUD B. - AIRAULT D.

#include "Medecin.h" 
using namespace std;


Medecin::Medecin() {};

// Constructeur de Medecin
Medecin::Medecin( string specialite, int numeroOrdreMedecin , string nom, string prenom, string adresse, bool sexe, int num){
	Medecin::setSpecialite(specialite);
	Medecin::setnumeroOrdreMedecin(numeroOrdreMedecin);
};


// Accesseurs

int Medecin::getnumeroOrdreMedecin(){ // Récupérer numéros d'ordre de Medecin
	return this->numeroOrdreMedecin;
};

string Medecin::getSpecialite(){ // Récupérer les specialités de Medecin
	return this->specialite;
};

void Medecin::setnumeroOrdreMedecin(int numeroOrdreMedecin){ // Changer numéro d'ordre de medecin
	this->numeroOrdreMedecin=numeroOrdreMedecin;
};

void Medecin::setSpecialite(string specialite){ // Changer la spécialité d'un medecin
	this->specialite=specialite;
};

// Affichage d'un objet de type Medecin
/*void Medecin::afficherMedecin(){
	cout << "	- Le nom du medecin est : " << Medecin::getnomMedecin() << "Le prénom du medecin est : " 
		<< Medecin::getprenomMedecin() << "Le numéro d'ordre du medecin est : " 
		<< Medecin::getnumeroOrdreMedecin() << " La spécialité du medecin est : " << Medecin::getSpecialite() << endl;	
}*/

/*
// A faire plus tard.
// Enregistrer un objet de type Medecin dans un fichier
void Medecin::afficherMedecinFichier(string nomFichier){
	ofstream outputFile(nomFichier.c_str(), ios::app); // Ouvrir le fichier
	if(outputFile){ // Si l'ouverture a fonctionnée, écrire à la suite le medecin
		outputFile << "		* Le medecin est " << this->nom << endl;
		outputFile.close(); // Fermer le fichier
	}
}
*/

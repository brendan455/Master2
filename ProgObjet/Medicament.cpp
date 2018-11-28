// Auteur : DENIAUD B. - AIRAULT D.


#include "Medicament.h"
#include <iostream> 
using namespace std;




// Constructeur de Medicament
Medicament::Medicament(string nom, string laboratoire){
	Medicament::setnomMedicament(nom);
	edicament::setlaboratoireMedicament(laboratoire);
}

// Accesseurs

string Medicament::getnomMedicament(){ // Récupérer les noms de Medicament
	return this->nom;
}

string Medicament::getlaboratoireMedicament(){ // Récupérer les laboratoires de Medicament
	return this->laboratoire;
}


void Medicament::setnomMedicament(string nom){ // Changer les noms de Medicament
	this->nom=nom;
}

void Medicament::setlaboratoireMedicament(string laboratoire){ // Changer les laboratoires de Medicament
	this->laboratoire=laboratoire;
}


// Affichage d'un objet de type Medicament
void Medicament::afficherMedicament(){
	cout << "	- Le nom du médicament est : " << this->nom << "Le laboratoire qui fabrique le médicament est : " << this->laboratoire << endl;	
}

//<<<<<<<<<<<<<<<<<<<<<<<<<          A revenir dessus :                 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Enregistrer un objet de type Medicament dans un fichier
void Medecin::afficherMedicamentFichier(string nomFichier){
	ofstream outputFile(nomFichier.c_str(), ios::app); // Ouvrir le fichier
	if(outputFile){ // Si l'ouverture a fonctionnée, écrire le nom du medicament
		outputFile << "		* Le medicament est " << this->nom << endl;
		outputFile.close(); // Fermer le fichier
	}
}


#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <string>
#include medecin.h
#include dossier.h


using namespace std;

class Cabinet
{
	private: // Attribut
		string nom;
   		string adresse;
    		List(Medecin) medecins;
    		List(Dossier) dossiers,

	public: // Méthodes
	// Constructeur
		Cabinet(string,string);	
	// Accesseurs
		string getNomCabinet(){};
		void setNewNomCabinet(string){};
		
	// Comportement
		void afficherCabinet();
}

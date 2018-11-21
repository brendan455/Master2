
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include medecin.h
#include dossier.h
using namespace std;

class Cabinet
{
	private: // Attribut
		char* nom;
    char* adresse;
    List(Medecin) medecins;
    List(Dossier) dossiers,

	public: // Méthodes
		// Constructeur
	Cabinet(char*,char*);
		
		// Accesseurs
		int getNomCabinet();
		void setNewNomCabinet(char*);
		
		// Affichage
		void afficherCabinet();
}

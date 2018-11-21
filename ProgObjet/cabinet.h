

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <string>
#include medecin.h
#include dossier.h


namespace Cab;

class Cabinet
{
	private: // Attribut
	  std::string nom;
   	std::string adresse;
    std::list(Medecin) medecins;
    std::list(Dossier) dossiers,
	public: // Méthodes
	// Constructeur
	  Cabinet(std::string,std::string);	
	// Accesseurs
		std::string getNomCabinet(){};
		void setNewNomCabinet(std::string){};
	// Comportement
		void afficherCabinet();
}

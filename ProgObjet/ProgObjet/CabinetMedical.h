// Auteur : DENIAUD B. - AIRAULT D.

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "DossierPatient.h"
#include "Medecin.h"


class CabinetMedical
{

private: // Attributs
	std::string nomCabinet;
	std::string adresse;
	std::list<Medecin> medecins;
	std::list<DossierPatient> dossiersPatient;

public: // Méthodes
	// Constructeur
	CabinetMedical();
	CabinetMedical(int);
	CabinetMedical(std::string, std::string, std::list<Medecin>, std::list<DossierPatient>);

	// Accesseurs
	std::string getNomCabinet();
	void setNomCabinet(std::string);

	std::string getAdresseCabinet();
	void setAdresseCabinet(std::string);

	void setDossiersPatient(std::list<DossierPatient>);
	std::list<DossierPatient> getDossiersPatient();

	void setMedecins(std::list<Medecin>);
	std::list<Medecin> getMedecins();

		/*
	void afficherNomAdresseCabinetMedical();


	// Ajouter un objet Medecin
	std::list<Medecin> ajouterMedecin(string);

	// Ajouter un objet Patient
	std::list<Patient> ajouterPatient(string);

	*/
};

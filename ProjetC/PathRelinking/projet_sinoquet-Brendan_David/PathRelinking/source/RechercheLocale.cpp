#include <iostream>
#include <fstream>

#include "../include/RechercheLocale.hpp"
using namespace std;


Solution recherche_locale(Solution solutionInitiale, vector<Solution> solutionsAleatoires) {
	Solution meilleurVoisin;
	Solution solutionFinale = solutionInitiale;
	vector<Solution> voisinage;
	bool amelioration = true;

	// Boucle de la réalisation de la recherche locale
	while (condition && amelioration == false) {
		voisinage = identifier_voisinage(SolutionFinale, solutionsAleatoires);
		meilleurVoisin = identifier_meilleur_voisin(voisinage)
			if (score(meilleurVoisin > score(solutionFinale)) {
				solutionFinale = meilleurVoisin;
			}
			else {
				amelioration = false;
			}
	}
	return (solutionFinale);
}

// Fonction qui identifie le meilleur voisin à partir de du voisinage de notre solution
Solution identifier_meilleur_voisin(vector<Solution> voisinage) {
	Solution meilleureSolution;
	int score_solution = 0;
	// On récupère toute nos solutions du voisinage
	for (vector<Solution>::iterator it = voisinage.begin(); it != voisinage.end(); ++it) {
		// si celle ci à un meilleur score que la meilleure solution actuelle, on garde cette solution.
		if (score_scolution < score(*it)) {
			meilleureSolution = *it;
		};
	}
	return (meilleureSolution)
}
 // Fonction qui determine le voisinage de notre solution. On fixe un seuil de proximité grace à k ( de base 1, dans cet algorithme.)
vector<Solution> identifier_voisinage(Solution solutionCourante, vector<Solution> solutionsAleatoires, int k) {
	vector<Solution> voisinage;
	string snp;
	Solution solutionTest;
	string snpTest;
	int difference;

	// La première itération permet de récuperer nos solutions aléatoires pour determiner si elles font partie du voisinage proche
	for (vector<Solution>::iterator iter2 = solutionsAleatoires.begin(); iter2 != solutionsAleatoires.end(); ++iter2) {
		solutionTest = *iter2;
		difference = solutionCourante.getListeDeSNP().size();

		// La deuxième itération permet de récupérer les différents Identifiant des SNP de la solutionCourante
		for (list<string>::iterator it = solutionCourante.getListeDeSNP().begin(); it != solutionCourante.getListeDeSNP().end(); ++it) {
			snp = *it;

			// La 3ème et derniere itérations permet de récupérer les Identifiants de la solutions Aléatoire sur laquelle on travaille.
			for (list<string>::iterator iter3 = solutionTest.getListeDeSNP().begin(); iter3 != solutionTest.getListeDeSNP().end(); ++iter3) {
				snpTest = *iter3;

				// Si l'un des snp de la solution aléatoire correspond à un SNP de la solution courante, la différence descend d'un cran.
				if (snp.compare(snpTest) == 0) {
					difference = difference - 1;
				}
			}
		}
		// On insère la solution dans notre voisinage si la différence est inférieure à notre seuil de différence.
		if (difference < k && difference != 0) {
			voisinage.insert(solutionTest);
		}
	}
	return voisinage;
}

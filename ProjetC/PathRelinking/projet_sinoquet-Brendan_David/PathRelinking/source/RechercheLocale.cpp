#include <iostream>
#include <fstream>

#include "../include/RechercheLocale.hpp"
using namespace std;


Solution recherche_locale(Solution solutionInitiale, vector<Solution> solutionsAleatoires) {
	Solution meilleurVoisin;
	Solution solutionFinale = solutionInitiale;
	vector<Solution> voisinage;
	bool amelioration = true;

	// Boucle de la r�alisation de la recherche locale
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

// Fonction qui identifie le meilleur voisin � partir de du voisinage de notre solution
Solution identifier_meilleur_voisin(vector<Solution> voisinage) {
	Solution meilleureSolution;
	int score_solution = 0;
	// On r�cup�re toute nos solutions du voisinage
	for (vector<Solution>::iterator it = voisinage.begin(); it != voisinage.end(); ++it) {
		// si celle ci � un meilleur score que la meilleure solution actuelle, on garde cette solution.
		if (score_scolution < score(*it)) {
			meilleureSolution = *it;
		};
	}
	return (meilleureSolution)
}
 // Fonction qui determine le voisinage de notre solution. On fixe un seuil de proximit� grace � k ( de base 1, dans cet algorithme.)
vector<Solution> identifier_voisinage(Solution solutionCourante, vector<Solution> solutionsAleatoires, int k) {
	vector<Solution> voisinage;
	string snp;
	Solution solutionTest;
	string snpTest;
	int difference;

	// La premi�re it�ration permet de r�cuperer nos solutions al�atoires pour determiner si elles font partie du voisinage proche
	for (vector<Solution>::iterator iter2 = solutionsAleatoires.begin(); iter2 != solutionsAleatoires.end(); ++iter2) {
		solutionTest = *iter2;
		difference = solutionCourante.getListeDeSNP().size();

		// La deuxi�me it�ration permet de r�cup�rer les diff�rents Identifiant des SNP de la solutionCourante
		for (list<string>::iterator it = solutionCourante.getListeDeSNP().begin(); it != solutionCourante.getListeDeSNP().end(); ++it) {
			snp = *it;

			// La 3�me et derniere it�rations permet de r�cup�rer les Identifiants de la solutions Al�atoire sur laquelle on travaille.
			for (list<string>::iterator iter3 = solutionTest.getListeDeSNP().begin(); iter3 != solutionTest.getListeDeSNP().end(); ++iter3) {
				snpTest = *iter3;

				// Si l'un des snp de la solution al�atoire correspond � un SNP de la solution courante, la diff�rence descend d'un cran.
				if (snp.compare(snpTest) == 0) {
					difference = difference - 1;
				}
			}
		}
		// On ins�re la solution dans notre voisinage si la diff�rence est inf�rieure � notre seuil de diff�rence.
		if (difference < k && difference != 0) {
			voisinage.insert(solutionTest);
		}
	}
	return voisinage;
}

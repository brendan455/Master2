#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "children.hpp"

using namespace std;

vector<vector<double>> select_pairs_of_individuals_to_be_crossed(int n_pairs_selected_parents, vector<vector<double>>& population_tab, int snp){
  random_device random;
  mt19937 rng(random());
  uniform_int_distribution<int> gen(0,population_tab.size()-1);

  vector<vector<double>> children_tab;
  vector<int> check;

  bool random1Already, random2Already;

  unsigned i, j;

  int nbAleatoire_header1, nbAleatoire_header2;

  if (n_pairs_selected_parents*2 >population_tab.size()){
    cout << "Not enough people in a population to create number of parent's pairs you want.\nPlease, be careful and check that n_pairs_selected_parents*2 <= n" << endl;
    exit(0);
  }

  for (i=0; i < n_pairs_selected_parents*2; i+=2){
    nbAleatoire_header1 = gen(rng);
    nbAleatoire_header2 = gen(rng);
    random1Already = true;
    random2Already = true;

    children_tab.push_back(vector<double>(5));
    children_tab.push_back(vector<double>(5));

    while (random1Already || random2Already || (nbAleatoire_header1 == nbAleatoire_header2)) {
      if (nbAleatoire_header1 == nbAleatoire_header2){
        nbAleatoire_header2 = gen(rng);
      }

      random1Already = false;
      random2Already = false;

      for (j = 0; j < check.size(); j++){
        if (nbAleatoire_header1 == check[j]){
          nbAleatoire_header1 = gen(rng);
          random1Already = true;
        }
      }

      for (j = 0; j < check.size(); j++){
        if (nbAleatoire_header2 == check[j]){
          nbAleatoire_header2 = gen(rng);
          random2Already = true;
        }
      }

      if (snp == 2){
        if (population_tab[nbAleatoire_header1][0] == population_tab[nbAleatoire_header2][1]){
          nbAleatoire_header1 = gen(rng);
          random1Already = true;
          random2Already = true;
        }
        if (population_tab[nbAleatoire_header1][1] == population_tab[nbAleatoire_header2][0]) {
          nbAleatoire_header2 = gen(rng);
          random1Already = true;
          random2Already = true;
        }
      } else if (snp == 3){
        if ((population_tab[nbAleatoire_header1][0] == population_tab[nbAleatoire_header2][2]) || (population_tab[nbAleatoire_header1][1] == population_tab[nbAleatoire_header2][2])){
          nbAleatoire_header1 = gen(rng);
          random1Already = true;
          random2Already = true;
        }
        if ((population_tab[nbAleatoire_header1][2] == population_tab[nbAleatoire_header2][0]) || (population_tab[nbAleatoire_header1][2] == population_tab[nbAleatoire_header2][1])) {
          nbAleatoire_header2 = gen(rng);
          random1Already = true;
          random2Already = true;
        }

      } else {
        cout << "Wrong number of SNP when selecting parents." << endl;
        exit(0);
      }

    }
    check.push_back(nbAleatoire_header1);
    check.push_back(nbAleatoire_header2);

    children_tab[i] = population_tab[nbAleatoire_header1];
    children_tab[i][3] = -1;
    children_tab[i][4] = nbAleatoire_header1;
    children_tab[i+1] = population_tab[nbAleatoire_header2];
    children_tab[i+1][3] = -1;
    children_tab[i+1][4] = nbAleatoire_header2;


  }
  return (children_tab);
}


void create_two_children_for_each_selected_pairs_of_parents(int snp, vector<vector<double>>& children_tab){
  unsigned i,j;
  int snp_p1_1, snp_p1_2, snp_p1_3, snp_p2_1, snp_p2_2, snp_p2_3;
  if (snp == 2){
    for (j=0; j<children_tab.size(); j+=2){
        snp_p1_1 = children_tab[j][0];
        snp_p1_2 = children_tab[j][1];
        snp_p2_1 = children_tab[j+1][0];
        snp_p2_2 = children_tab[j+1][1];

        if (snp_p1_1 > snp_p2_2){
          children_tab[j][0] = snp_p2_2;
          children_tab[j][1] = snp_p1_1;
        } else {
          children_tab[j][0] = snp_p1_1;
          children_tab[j][1] = snp_p2_2;
        }
        if (snp_p2_1 > snp_p1_2){
          children_tab[j+1][0] = snp_p1_2;
          children_tab[j+1][1] = snp_p2_1;
        } else {
          children_tab[j+1][0] = snp_p2_1;
          children_tab[j+1][1] = snp_p1_2;
        }
    }
  } else if (snp == 3){
    for (j=0; j<children_tab.size(); j+=2){
        snp_p1_1 = children_tab[j][0];
        snp_p1_2 = children_tab[j][1];
        snp_p1_3 = children_tab[j][2];
        snp_p2_1 = children_tab[j+1][0];
        snp_p2_2 = children_tab[j+1][1];
        snp_p2_3 = children_tab[j+1][2];

        children_tab[j][0] = snp_p1_1;
        children_tab[j][1] = snp_p1_2;
        children_tab[j][2] = snp_p2_3;
        children_tab[j+1][0] = snp_p2_1;
        children_tab[j+1][1] = snp_p2_2;
        children_tab[j+1][2] = snp_p1_3;

        if (snp_p1_1 > snp_p2_3){
          children_tab[j][0] = snp_p2_3;
          children_tab[j][1] = snp_p1_1;
          children_tab[j][2] = snp_p1_2;
        } else if (snp_p1_2 > snp_p2_3) {
          children_tab[j][0] = snp_p1_1;
          children_tab[j][1] = snp_p2_3;
          children_tab[j][2] = snp_p1_2;
        } else {
          children_tab[j][0] = snp_p1_1;
          children_tab[j][1] = snp_p1_2;
          children_tab[j][2] = snp_p2_3;
        }

        if (snp_p2_1 > snp_p1_3){
          children_tab[j+1][0] = snp_p1_3;
          children_tab[j+1][1] = snp_p2_1;
          children_tab[j+1][2] = snp_p2_2;
        } else if (snp_p2_2 > snp_p1_3) {
          children_tab[j+1][0] = snp_p2_1;
          children_tab[j+1][1] = snp_p1_3;
          children_tab[j+1][2] = snp_p2_2;
        } else {
          children_tab[j+1][0] = snp_p2_1;
          children_tab[j+1][1] = snp_p2_2;
          children_tab[j+1][2] = snp_p1_3;
        }
    }

  } else {
    cout << "Wrong number of SNP when generating children." << endl;
    exit(0);
  }


}

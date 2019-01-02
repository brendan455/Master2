#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

vector<vector<double>> initialize_population(int n, int snp, vector<string>& header_tab){
  random_device random;
  mt19937 rng(random());
  uniform_int_distribution<int> gen(1,header_tab.size()-1);
  unsigned int i,j;
  int nbAleatoire_header1, nbAleatoire_header2, nbAleatoire_header3, temp;
  vector<vector<double>> population_tab;

  for (i = 0; i < n; i++){
    population_tab.push_back(vector<double>(5));
    if(snp == 2){
      nbAleatoire_header1 = gen(rng) ;
      nbAleatoire_header2 = gen(rng) ;
      while (nbAleatoire_header1 >= nbAleatoire_header2){
        if (nbAleatoire_header1 == nbAleatoire_header2) {
          nbAleatoire_header2 = gen(rng) ;
        }
        if (nbAleatoire_header1>nbAleatoire_header2) {
          temp = nbAleatoire_header1;
          nbAleatoire_header1 = nbAleatoire_header2;
          nbAleatoire_header2 = temp;
        }
      }

      population_tab[i][0] = nbAleatoire_header1;
      population_tab[i][1] = nbAleatoire_header2;
      population_tab[i][2] = 0;
      population_tab[i][3] = -1;
      population_tab[i][4] = 0;

    } else if(snp==3) {
      nbAleatoire_header1 =gen(rng);
      nbAleatoire_header2 =gen(rng);
      nbAleatoire_header3 =gen(rng);
      while ((nbAleatoire_header1 >= nbAleatoire_header2) || (nbAleatoire_header1 >= nbAleatoire_header3) || (nbAleatoire_header2 >= nbAleatoire_header3)) {
        if ((nbAleatoire_header1 == nbAleatoire_header2) || (nbAleatoire_header1 == nbAleatoire_header3)) {
          nbAleatoire_header1 =gen(rng);
        }
        if (nbAleatoire_header2==nbAleatoire_header3) {
          nbAleatoire_header2 =gen(rng);
        }
        if ((nbAleatoire_header1>nbAleatoire_header2) && (nbAleatoire_header1>nbAleatoire_header3)){
          temp = nbAleatoire_header1;
          nbAleatoire_header1 = nbAleatoire_header2;
          nbAleatoire_header2 = nbAleatoire_header3;
          nbAleatoire_header3 = temp;
          if (nbAleatoire_header1>nbAleatoire_header2) {
            temp = nbAleatoire_header1;
            nbAleatoire_header1 = nbAleatoire_header2;
            nbAleatoire_header2 = temp;
          }
          break;
        }
        if ((nbAleatoire_header2>nbAleatoire_header1) && (nbAleatoire_header2>nbAleatoire_header3)){
          temp = nbAleatoire_header2;
          nbAleatoire_header2 = nbAleatoire_header3;
          nbAleatoire_header3 = temp;
          if (nbAleatoire_header1>nbAleatoire_header2) {
            temp = nbAleatoire_header1;
            nbAleatoire_header1 = nbAleatoire_header2;
            nbAleatoire_header2 = temp;
          }
          break;
        }
        if ((nbAleatoire_header3>nbAleatoire_header1) && (nbAleatoire_header3>nbAleatoire_header2)){
          if (nbAleatoire_header1>nbAleatoire_header2) {
            temp = nbAleatoire_header1;
            nbAleatoire_header1 = nbAleatoire_header2;
            nbAleatoire_header2 = temp;
          }
        }
      }
      population_tab[i][0] = nbAleatoire_header1;
      population_tab[i][1] = nbAleatoire_header2;
      population_tab[i][2] = nbAleatoire_header3;
      population_tab[i][3] = -1;
      population_tab[i][4] = 0;
    }

    population_tab[i].pop_back();
  }
  return(population_tab);
}


void update_population(vector<vector<double>> &population_tab, vector<vector<double>> &children_tab) {
  unsigned int i;
  for(i=0;i<children_tab.size();i++){
    if(children_tab[i][3] < population_tab[children_tab[i][4]][3]){
      population_tab[children_tab[i][4]][0] = children_tab[i][0];
      population_tab[children_tab[i][4]][1] = children_tab[i][1];
      population_tab[children_tab[i][4]][2] = children_tab[i][2];
      population_tab[children_tab[i][4]][3] = children_tab[i][3];
      population_tab[children_tab[i][4]][4] = children_tab[i][4];
    }
  }
}

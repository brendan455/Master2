#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/math/distributions/chi_squared.hpp>

#include "statistic.hpp"

using namespace std;

vector<vector<double>> chiSquare_tab_creation(int n, vector<vector<double>> chiSquare_tab){
  unsigned i, j;
  if (n == 2){
    for(j=0; j<2; j++){
      chiSquare_tab.push_back(vector<double>(9));
      for (i=0; i<chiSquare_tab[j].size(); i++){
        chiSquare_tab[j][i]=0;
      }
      chiSquare_tab[j].pop_back();
    }
  } else if (n == 3){
    for(j=0; j<2; j++){
      chiSquare_tab.push_back(vector<double>(27));
      for (i=0; i<chiSquare_tab[j].size(); i++){
        chiSquare_tab[j][i]=0;
      }
      chiSquare_tab[j].pop_back();
    }
  }
  return(chiSquare_tab);
}



void chiSquare_tab_reset(vector<vector<double>> & chiSquare_tab){
  unsigned i, j;
  for(j=0; j<2; j++){
    for (i=0; i<=chiSquare_tab[j].size(); i++){
      chiSquare_tab[j][i]=0;
    }
  }
}

int perform_one_mutation_per_children(int snp, int *geno_snp1, int* geno_snp2, int* geno_snp3, double prob_mutation){
  random_device random;
  mt19937 rng(random());
  uniform_int_distribution<int> gen(0,100);
  int value = gen(rng);
  uniform_int_distribution<int> nb_deux(0,1);
  int nb_a_choisir = nb_deux(rng);
  if(value<= prob_mutation*100) {
    if(snp==2){
      random_device random;
      mt19937 rng(random());
      uniform_int_distribution<int> gen(0,1);
      int value = gen(rng);
      if(value == 0) {
        if(*geno_snp1 == 0){
          if(nb_a_choisir==0){
            *geno_snp1 = 1;
          } else {
            *geno_snp1 = 2;
          }
        } else if(*geno_snp1 == 1) {
          if(nb_a_choisir==0){
            *geno_snp1 = 0;
          } else {
            *geno_snp1 = 2;
          }
        } else {//geno snp == 2
          if(nb_a_choisir==0){
            *geno_snp1 = 0;
          } else {
            *geno_snp1 = 1;
          }
        }
      } else {// value = 1
        if(*geno_snp2 == 0){
          if(nb_a_choisir==0){
            *geno_snp2 = 1;
          } else {
            *geno_snp2 = 2;
          }
        } else if(*geno_snp2 == 1) {
          if(nb_a_choisir==0){
            *geno_snp2 = 0;
          } else {
            *geno_snp2 = 2;
          }
        } else {//geno snp == 2
          if(nb_a_choisir==0){
            *geno_snp2 = 0;
          } else {
            *geno_snp2 = 1;
          }
        }
      }
    } else if(snp == 3){
      random_device random;
      mt19937 rng(random());
      uniform_int_distribution<int> gen(0,1);
      int value = gen(rng);
      if(value == 0) {
        if(*geno_snp1 == 0){
          if(nb_a_choisir==0){
            *geno_snp1 = 1;
          } else {
            *geno_snp1 = 2;
          }
        } else if(*geno_snp1 == 1) {
          if(nb_a_choisir==0){
            *geno_snp1 = 0;
          } else {
            *geno_snp1 = 2;
          }
        } else {//geno snp == 2
          if(nb_a_choisir==0){
            *geno_snp1 = 0;
          } else {
            *geno_snp1 = 1;
          }
        }
      } else if(value == 1){// value = 1
        if(*geno_snp2 == 0){
          if(nb_a_choisir==0){
            *geno_snp2 = 1;
          } else {
            *geno_snp2 = 2;
          }
        } else if(*geno_snp2 == 1) {
          if(nb_a_choisir==0){
            *geno_snp2 = 0;
          } else {
            *geno_snp2 = 2;
          }
        } else {//geno snp == 2
          if(nb_a_choisir==0){
            *geno_snp2 = 0;
          } else {
            *geno_snp2 = 1;
          }
        }
      } else {
        if(*geno_snp3 == 0){
          if(nb_a_choisir==0){
            *geno_snp3 = 1;
          } else {
            *geno_snp3 = 2;
          }
        } else if(*geno_snp3 == 1) {
          if(nb_a_choisir==0){
            *geno_snp3 = 0;
          } else {
            *geno_snp3 = 2;
          }
        } else {//geno snp == 2
          if(nb_a_choisir==0){
            *geno_snp3 = 0;
          } else {
            *geno_snp3 = 1;
          }
        }
      }
    }
    return(42);
  }
  return(0);
}

void chiSquare_calculation(int snp, vector<vector<double>>& population_tab, vector<vector<int>>& geno_tab, vector<int>& pheno_tab, double prob_mutation){
  unsigned i, j, theorique_i, theorique_j, chi_square_i, chi_square_j;
  int sum0, sum1;
  double snp1, snp2, snp3, score, num, pval;
  int geno_snp1;
  int geno_snp2;
  int geno_snp3;
  vector<vector<double>> chiSquare_tab;
  vector<vector<double>> theorique_chiSquare_tab;

  chiSquare_tab = chiSquare_tab_creation(snp, chiSquare_tab);
  theorique_chiSquare_tab = chiSquare_tab_creation(snp, theorique_chiSquare_tab);
  bool mutation_to_do;
  int mutation_done = 0;
  if(prob_mutation==0){
    mutation_to_do = false;
  } else {
    mutation_to_do = true;
  }


  if (snp == 2){
    for (i = 0; i < population_tab.size(); i++){
      if (population_tab[i][3]==-1){
        chiSquare_tab_reset(chiSquare_tab);
        chiSquare_tab_reset(theorique_chiSquare_tab);
        snp1 = population_tab[i][0];
        snp2 = population_tab[i][1];
        sum0 = 0;
        sum1 = 0;
        score = 0;
        //cout << "compteur i: " << i << endl;

        for (j=0; j<geno_tab.size(); j++){
          geno_snp1 = geno_tab[j][snp1];
          geno_snp2 = geno_tab[j][snp2];
          geno_snp3 = geno_tab[j][snp3];
          if (mutation_to_do == true) {
            mutation_done = perform_one_mutation_per_children(snp, &geno_snp1, &geno_snp2, &geno_snp3, prob_mutation);
          }
          if(mutation_done == 42) {
            mutation_to_do = false;
          }
        //   cout << j << endl;
        //   cout << geno_snp1 << endl;
        //   cout << geno_snp2 << endl;
        //   cout << pheno_tab[j] << endl;
          if (geno_snp1 == 0 && geno_snp2 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][0] += 1;
            } else if (pheno_tab[j] == 1){
              chiSquare_tab[1][0] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 0 && geno_snp2 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][1] += 1;
            } else if (pheno_tab[j] == 1){
              chiSquare_tab[1][1] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 0 && geno_snp2 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][2] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][2] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][3] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][3] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][4] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][4] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][5] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][5] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][6] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][6] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][7] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][7] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][8] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][8] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else {
            cout << "Genotype file might be wrong.\nPlease check if value are only 0, 1 or 2 (except the header)." << endl;
            exit(0);
          }
        }

        for (chi_square_j=0; chi_square_j < chiSquare_tab.size(); chi_square_j++){
          for (chi_square_i=0; chi_square_i <= chiSquare_tab[chi_square_j].size(); chi_square_i++){
            if (chi_square_j == 0){
              sum0 += chiSquare_tab[chi_square_j][chi_square_i];
            } else if (chi_square_j == 1){
              sum1 += chiSquare_tab[chi_square_j][chi_square_i];
            } else {
              cout << "Something went wrong.\nError during 'sum line' chi square for 2 SNP." << endl;
              exit(0);
            }
          }
        }

        for (theorique_j = 0; theorique_j < theorique_chiSquare_tab.size(); theorique_j++){
          for (theorique_i = 0; theorique_i <= theorique_chiSquare_tab[theorique_j].size();theorique_i++){
            if (theorique_j == 0){
              theorique_chiSquare_tab[theorique_j][theorique_i] = ((sum0*(chiSquare_tab[theorique_j][theorique_i]+chiSquare_tab[theorique_j+1][theorique_i]))/(sum0+sum1));
            } else if (theorique_j == 1){
              theorique_chiSquare_tab[theorique_j][theorique_i] = ((sum1*(chiSquare_tab[theorique_j-1][theorique_i]+chiSquare_tab[theorique_j][theorique_i]))/(sum0+sum1));
            } else {
              cout << "Something went wrong.\nError during theorique chi square for 2SNP." << endl;
              exit(0);
            }
          }
        }

        for (chi_square_j=0; chi_square_j < chiSquare_tab.size(); chi_square_j++){
          for (chi_square_i=0; chi_square_i < chiSquare_tab[chi_square_j].size(); chi_square_i++){
            num = chiSquare_tab[chi_square_j][chi_square_i] - theorique_chiSquare_tab[chi_square_j][chi_square_i];
            if (theorique_chiSquare_tab[chi_square_j][chi_square_i] == 0){
              continue;
            }else {
              score += (num*num)/theorique_chiSquare_tab[chi_square_j][chi_square_i];
            }
          }
        }

        boost::math::chi_squared_distribution<double> chi2_dist(8);
        pval = 1 - boost::math::cdf(chi2_dist, score);
        population_tab[i][3] = pval;

        // cout << "_________________________________________________________________" << endl;
        // cout << "SNP " << snp1 << " " << snp2 << endl;
        // cout << "tab 1" << endl;
        // for (chi_square_j=0; chi_square_j<chiSquare_tab.size(); chi_square_j++){
        //   for (chi_square_i=0; chi_square_i<=chiSquare_tab[chi_square_j].size(); chi_square_i++){
        //     cout << chiSquare_tab[chi_square_j][chi_square_i] << "  ";
        //   }
        //   cout << endl;
        // }
        // cout << "tab 2" << endl;
        // for (theorique_j=0; theorique_j<chiSquare_tab.size(); theorique_j++){
        //   for (theorique_i=0; theorique_i<=chiSquare_tab[theorique_j].size(); theorique_i++){
        //     cout << theorique_chiSquare_tab[theorique_j][theorique_i]  << "  ";
        //   }
        //   cout << endl;
        // }
        // cout << "pval " << population_tab[i][3] << endl;
        // cout << "_________________________________________________________________" << endl;
      }
    }


  } else if (snp == 3) {
    for (i = 0; i < population_tab.size(); i++){
      if (population_tab[i][3]==-1){
        chiSquare_tab_reset(chiSquare_tab);
        chiSquare_tab_reset(theorique_chiSquare_tab);
        snp1 = population_tab[i][0];
        snp2 = population_tab[i][1];
        snp3 = population_tab[i][2];
        sum0 = 0;
        sum1 = 0;
        score = 0;
        //cout << "compteur i: " << i << endl;

        for (j=0; j<geno_tab.size(); j++){
          geno_snp1 = geno_tab[j][snp1];
          geno_snp2 = geno_tab[j][snp2];
          geno_snp3 = geno_tab[j][snp3];
          if (mutation_to_do == true) {
            mutation_done = perform_one_mutation_per_children(snp, &geno_snp1, &geno_snp2, &geno_snp3, prob_mutation);
          }
          if(mutation_done == 42) {
            mutation_to_do = false;
          }
        //cout << "SNP " << snp1 << " " << snp2 << endl;
        //   cout << j << endl;
        //   cout << geno_snp1 << endl;
        //   cout << geno_snp2 << endl;
        //   cout << pheno_tab[j] << endl;
          if (geno_snp1 == 0 && geno_snp2 == 0 && geno_snp3 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][0] += 1;
            } else if (pheno_tab[j] == 1){
              chiSquare_tab[1][0] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 0 && geno_snp2 == 0 && geno_snp3 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][1] += 1;
            } else if (pheno_tab[j] == 1){
              chiSquare_tab[1][1] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 0 && geno_snp2 == 0 && geno_snp3 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][2] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][2] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 0 && geno_snp2 == 1 && geno_snp3 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][3] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][3] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 0 && geno_snp2 == 1 && geno_snp3 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][4] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][4] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 0 && geno_snp2 == 1 && geno_snp3 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][5] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][5] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 0 && geno_snp2 == 2 && geno_snp3 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][6] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][6] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 0 && geno_snp2 == 2 && geno_snp3 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][7] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][7] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 0 && geno_snp2 == 2 && geno_snp3 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][8] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][8] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 0 && geno_snp3 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][9] += 1;
            } else if (pheno_tab[j] == 1){
              chiSquare_tab[1][9] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 0 && geno_snp3 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][10] += 1;
            } else if (pheno_tab[j] == 1){
              chiSquare_tab[1][10] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 0 && geno_snp3 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][11] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][11] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 1 && geno_snp3 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][12] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][12] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 1 && geno_snp3 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][13] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][13] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 1 && geno_snp3 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][14] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][14] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 2 && geno_snp3 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][15] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][15] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 2 && geno_snp3 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][16] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][16] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 1 && geno_snp2 == 2 && geno_snp3 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][17] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][17] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 0 && geno_snp3 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][18] += 1;
            } else if (pheno_tab[j] == 1){
              chiSquare_tab[1][18] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 0 && geno_snp3 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][19] += 1;
            } else if (pheno_tab[j] == 1){
              chiSquare_tab[1][19] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 0 && geno_snp3 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][20] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][20] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 1 && geno_snp3 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][21] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][21] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 1 && geno_snp3 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][22] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][22] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 1 && geno_snp3 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][23] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][23] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 2 && geno_snp3 == 0){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][24] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][24] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 2 && geno_snp3 == 1){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][25] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][25] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else if (geno_snp1 == 2 && geno_snp2 == 2 && geno_snp3 == 2){
            if (pheno_tab[j] == 0){
              chiSquare_tab[0][26] += 1;
            } else if (pheno_tab[j] == 1) {
              chiSquare_tab[1][26] += 1;
            } else {
              cout << "Phenotype file might be wrong.\nPlease check if value are only 0 or 1 (except the header)." << endl;
              exit(0);
            }
          } else {
            cout << "Genotype file might be wrong.\nPlease check if value are only 0, 1 or 2 (except the header)." << endl;
            exit(0);
          }
        }

        for (chi_square_j=0; chi_square_j < chiSquare_tab.size(); chi_square_j++){
          for (chi_square_i=0; chi_square_i <= chiSquare_tab[chi_square_j].size(); chi_square_i++){
            if (chi_square_j == 0){
              sum0 += chiSquare_tab[chi_square_j][chi_square_i];
            } else if (chi_square_j == 1){
              sum1 += chiSquare_tab[chi_square_j][chi_square_i];
            } else {
              cout << "Something went wrong.\nError during 'sum line' chi square for 2 SNP." << endl;
              exit(0);
            }
          }
        }

        for (theorique_j = 0; theorique_j < theorique_chiSquare_tab.size(); theorique_j++){
          for (theorique_i = 0; theorique_i <= theorique_chiSquare_tab[theorique_j].size();theorique_i++){
            if (theorique_j == 0){
              theorique_chiSquare_tab[theorique_j][theorique_i] = (sum0*(chiSquare_tab[theorique_j][theorique_i]+chiSquare_tab[theorique_j+1][theorique_i])/(sum0+sum1));
            } else if (theorique_j == 1){
              theorique_chiSquare_tab[theorique_j][theorique_i] = (sum0*(chiSquare_tab[theorique_j-1][theorique_i]+chiSquare_tab[theorique_j][theorique_i])/(sum0+sum1));
            } else {
              cout << "Something went wrong.\nError during theorique chi square for 2SNP." << endl;
              exit(0);
            }
          }
        }

        for (chi_square_j=0; chi_square_j < chiSquare_tab.size(); chi_square_j++){
          for (chi_square_i=0; chi_square_i < chiSquare_tab[chi_square_j].size(); chi_square_i++){
            num = chiSquare_tab[chi_square_j][chi_square_i] - theorique_chiSquare_tab[chi_square_j][chi_square_i];
            if (theorique_chiSquare_tab[chi_square_j][chi_square_i] == 0){
              continue;
            }else {
              score += (num*num)/theorique_chiSquare_tab[chi_square_j][chi_square_i];
            }
          }
        }

        boost::math::chi_squared_distribution<double> chi2_dist(26);
        pval = 1 - boost::math::cdf(chi2_dist, score);
        population_tab[i][3] = pval;

        // cout << "_________________________________________________________________" << endl;
        // cout << "SNP " << snp1 << " " << snp2 << " " << snp3 <<endl;
        // cout << "tab 1" << endl;
        // for (chi_square_j=0; chi_square_j<chiSquare_tab.size(); chi_square_j++){
        //   for (chi_square_i=0; chi_square_i<=chiSquare_tab[chi_square_j].size(); chi_square_i++){
        //     cout << chiSquare_tab[chi_square_j][chi_square_i] << "  ";
        //   }
        //   cout << endl;
        // }
        // cout << "tab 2" << endl;
        // for (theorique_j=0; theorique_j<chiSquare_tab.size(); theorique_j++){
        //   for (theorique_i=0; theorique_i<=chiSquare_tab[theorique_j].size(); theorique_i++){
        //     cout << theorique_chiSquare_tab[theorique_j][theorique_i]  << "  ";
        //   }
        //   cout << endl;
        // }
        // cout << "pval " << population_tab[i][3] << endl;
        // cout << "_________________________________________________________________" << endl;
      }
    }

  } else {
    cout << "Pattern you search is too long.\nPlease give a pattern size of 2 or 3." << endl;
    exit(0);
  }
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include "parsing.hpp"
#include "statistic.hpp"
#include "population.hpp"
#include "quickSort.hpp"
#include "children.hpp"




using namespace std;


// exemple de ligne de code pour lancer l'algo :
// ./Genetic_alorithm ../Simu_naive1/Naif1_1_Genotype.txt ../Simu_naive1/Naif1_1_Phenotype.txt


int main(int argc, char *argv[]) {

  if(argc < 4)
  {
      cerr << "Missing parameter :\n" << "\t./executable <path_to_genotypes> <path_to_phenotypes>" << endl;
      exit(-1);
  }

  //Variable
  string genoFile = argv[1];
  string phenoFile = argv[2];
  string outputFile = argv[3];

  unsigned i = 0;
  unsigned j = 0;

  int n, n_it, n_pairs_selected_parents, k, snp;

  double prob_mutation;

  vector<string> header_tab;
  vector<int> pheno_tab;
  vector<vector<int>> geno_tab;
  vector<vector<double>> population_tab, children_tab;

  parameters_parsing(&n, &n_it, &n_pairs_selected_parents, &k, &snp, &prob_mutation);

  //Parsing of genotype and phenotype files
  header_tab = header_file_parsing(genoFile, header_tab);
  geno_tab = geno_file_parsing(genoFile, geno_tab);
  pheno_tab = pheno_file_parsing(phenoFile, pheno_tab);

  // creation of 1 solution
  //boost::numeric::ublas::matrix<int> tablo = initialiser_solution(snp, header_tab, geno_tab);

  population_tab = initialize_population(n, snp, header_tab);
  chiSquare_calculation(snp, population_tab, geno_tab, pheno_tab,0);

  quickSort(population_tab, 0, n-1);

  // cout << "nouveau_________________________________________________________________" << endl;
  // for (j=0; j<population_tab.size(); j++){
  //     for (i=0; i<=population_tab[j].size(); i++){
  //       cout << population_tab[j][i] << " ";
  //     }
  //     cout << endl;
  //   }
  // cout << "_________________________________________________________________" << endl;

  int z=0;

  while (z < n_it){
    children_tab = select_pairs_of_individuals_to_be_crossed(n_pairs_selected_parents, population_tab, snp);

    // for (j=0; j<children_tab.size(); j++){
    //   for (i=0; i<=children_tab[j].size(); i++){
    //     cout << children_tab[j][i] << "  ";
    //   }
    //   cout << "\n"<< endl;
    // }
    // cout << "___________croisement____________" << endl;

    create_two_children_for_each_selected_pairs_of_parents(snp, children_tab);

    // for (j=0; j<children_tab.size(); j++){
    //   for (i=0; i<=children_tab[j].size(); i++){
    //     cout << children_tab[j][i] << "  ";
    //   }
    //   cout << "\n"<< endl;
    // }
    // cout << "_____________chi2______________" << endl;

    chiSquare_calculation(snp, children_tab, geno_tab, pheno_tab, prob_mutation);
    update_population(population_tab,children_tab);
    quickSort(population_tab, 0, n-1);

    // for (j=0; j<children_tab.size(); j++){
    //   for (i=0; i<=children_tab[j].size(); i++){
    //     cout << children_tab[j][i] << "  ";
    //   }
    //   cout << "\n"<< endl;
    // }
    // cout << "___________________________" << endl;

    z++;
  }


  ofstream output(outputFile.c_str());
  if(output)
    {
        output << "Parameters used :\n" << endl;
        output << "\tGenotype file path = " << genoFile << endl;
        output << "\tPhenotype file path = " << phenoFile << endl;
        output << "\tNumber of iteration n_it = " << n_it << endl;
        output << "\tNumber of pairs of parents n_pairs_selected_parents = " << n_pairs_selected_parents << endl;
        output << "\tMutation probability prob_mutation = " << prob_mutation << endl;
        output << "\tNumber of best individuals k = " << k << endl;
        output << "\tNumber of SNP snp = " << snp << endl;
        output << "\n\n" << endl;
        output << "Best solutions are : \n" << endl;
        if (k > population_tab.size()){
          k = population_tab.size();
        }
        if (snp == 2){
          for (i=0; i<k; i++){
            output << "{" << header_tab[population_tab[i][0]-1] << "," << header_tab[population_tab[i][1]-1] << "}" << "\tScore = " << population_tab[i][3] << endl;
          }
        } else if (snp == 3){
          for (i=0; i<k; i++){
            output << "{" << header_tab[population_tab[i][0]-1] << "," << header_tab[population_tab[i][1]-1] << "," << header_tab[population_tab[i][2]-1] << "}" << "\tScore = " << population_tab[i][3] << endl;
          }
        }



    }
    else
    {
        cout << "ERROR. Can't find RESULTS directory." << endl;
    }

}

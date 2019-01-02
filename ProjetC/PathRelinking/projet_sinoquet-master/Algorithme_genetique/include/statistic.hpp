#ifndef statistic_hpp
#define statistic_hpp

using namespace std;

vector<vector<double>> chiSquare_tab_creation(int, vector<vector<double>>);
void chiSquare_calculation(int snp, vector<vector<double>>& population_tab, vector<vector<int>>& geno_tab, vector<int>& pheno_tab, double prob_mutation);
void chiSquare_reset(vector<vector<double>> & chiSquare_tab);
int perform_one_mutation_per_children(int snp, int *geno_snp1, int* geno_snp2, int* geno_snp3, double prob_mutation);
#endif

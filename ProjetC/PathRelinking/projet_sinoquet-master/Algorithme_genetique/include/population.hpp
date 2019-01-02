#ifndef population_hpp
#define population_hpp

boost::numeric::ublas::matrix<int> initialiser_solution(int, vector<string>, vector<vector<int>>);

vector<vector<double>> initialize_population(int n, int snp, vector<string>& header_tab);

void update_population(vector<vector<double>> &population_tab, vector<vector<double>> &children_tab);

#endif

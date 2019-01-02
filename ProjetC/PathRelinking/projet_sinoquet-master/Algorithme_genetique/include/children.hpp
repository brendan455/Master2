#ifndef children_hpp
#define children_hpp

using namespace std;

vector<vector<double>> select_pairs_of_individuals_to_be_crossed(int n_pairs_selected_parents, vector<vector<double>>& population_tab, int snp);
void create_two_children_for_each_selected_pairs_of_parents(int snp, vector<vector<double>>& children_tab);

#endif

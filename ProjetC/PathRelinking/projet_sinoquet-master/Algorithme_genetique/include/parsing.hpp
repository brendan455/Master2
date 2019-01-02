#ifndef parsing_hpp
#define parsing_hpp

using namespace std;

vector<string> header_file_parsing(string, vector<string>);
vector<vector<int>> geno_file_parsing(string , vector<vector<int>>);
vector<int> pheno_file_parsing(string, vector<int>);
vector<string> split(string const&, char);
void parameters_parsing(int*, int*, int*, int*, int*, double*);
#endif

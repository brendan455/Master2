#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "parsing.hpp"

using namespace std;

vector<string> header_file_parsing(string genoFile, vector<string> header_tab){
  /*
    Function use to extract header in genotype file.
    It take as input the path of file and an empty vector.
    Output is the full vector.
  */
  ifstream openGenoFile(genoFile.c_str());
  if (openGenoFile) {
    unsigned i = 0;
    string reading, name;
    getline(openGenoFile, reading);
    while(i <= reading.size()){
      if (reading[i]==',' || i == reading.size()){
        header_tab.push_back(name);
        name = "";
      } else {
        name += reading[i];
      }
      i++;
    }
  } else {
    cerr << "Error during header extraction" << endl;
    exit(-1);
  }
  return(header_tab);
}


vector<vector<int>> geno_file_parsing(string genoFile, vector<vector<int>> geno_tab){
  /*
    Function use to extract each value for each SNP in genotype file.
    It take as input the path of file and an empty 2D vector.
    Output is the full 2D vector.
  */
  ifstream openGenoFile(genoFile.c_str());
  if (openGenoFile){
    unsigned i = 0;
    unsigned j = 0;
    string reading;
    getline(openGenoFile, reading);
    while(getline(openGenoFile, reading)){
      geno_tab.push_back(vector<int>((reading.size()-1)/2));
      for (i=0; i<=reading.size(); i++){
        if (reading[i] == '0'){
          geno_tab[j][(i+1)/2] = 0;
        } else if (reading[i] == '1'){
          geno_tab[j][(i+1)/2] = 1;
        } else if (reading[i] == '2'){
          geno_tab[j][(i+1)/2] = 2;
        } else {
          continue;
        }
      }
      j++;
    }
  } else {
    cerr << "Error during genotype extraction" << endl;
    exit(-1);
  }
  return(geno_tab);
}


vector<int> pheno_file_parsing(string phenoFile, vector<int> pheno_tab){
  /*
    Function use to extract each phenotype in phenotype file.
    It take as input the path of file and an empty vector.
    Output is the full vector.
  */
  ifstream openPhenoFile(phenoFile.c_str());
  if (openPhenoFile) {
    string reading;
    getline(openPhenoFile, reading);
    while (getline(openPhenoFile, reading)) {
      if (reading[0] == '1') {
        pheno_tab.push_back(1);
      } else {
        pheno_tab.push_back(0);
      }
    }
  } else {
    cerr << "Error during phenotype extraction" << endl;
    exit(-1);
  }
  return(pheno_tab);
}



vector<string> split(string const& s, char delim)
{
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim))
        tokens.push_back(item);
    return tokens;
}

void parameters_parsing(int* n, int* n_it, int* n_pairs_selected_parents, int* k, int* snp, double* prob_mutation) {
  ifstream file("./parameters.txt");
  if(file)
  {
    string line;
    while (!file.eof())
    {
      getline(file, line);
      if (line.length() != 0 && line[0] != '#')
      {
      //recuperer les parametres
        vector<string> token = split(line, ' ');
        string const key = token[0];
        string value = token[1];
        if(key == "n"){
          *n = atof(value.c_str());
        } else if(key == "n_it") {
          *n_it = atof(value.c_str());
        } else if(key == "n_pairs_selected_parents"){
          *n_pairs_selected_parents = atof(value.c_str());
        } else if (key == "prob_mutation") {
          *prob_mutation = atof(value.c_str());
        } else if (key == "k") {
          *k = atof(value.c_str());
        } else if (key == "snp") {
          *snp = atof(value.c_str());
        }
      }
    }
  }
  else
  {
      cerr << "Error while opening parameters.txt !\n";
  }
  return;
}

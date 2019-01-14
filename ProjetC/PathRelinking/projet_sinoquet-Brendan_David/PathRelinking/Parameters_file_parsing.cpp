#include "Parameters_file_parsing.hpp"

#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;


//=================================================
// Constructor
//=================================================
Parameters_file_parsing::Parameters_file_parsing()
{
	ifstream file("./PARAMETERS.txt");
	if (file)
	{
		string line;
		while (!file.eof())
		{
			getline(file, line);
			if (line.length() != 0 && line[0] != '#')
			{
				import_line(line);
			}
		}
	}
	else
	{
		std::cerr << "Error while opening PARAMETERS.txt !\n";
	}
}

//=================================================
// Parameters_file_parsing : import_line
//=================================================
void Parameters_file_parsing::import_line(string const& line)
{
	vector<string> token = this->split(line, ' ');
	string const& key = token[0];
	string & value = token[1];

	if (key == "header")
		header = atoi(value.c_str());

	else if (key == "separator")
	{
		if (value == "\t")
			separator = '\t';
		else
			separator = value.at(0);
	}
	else if (key == "n")

		n = atoi(value.c_str());

	else if (key == "n_it")
		n_it = atoi(value.c_str());

	else if (key == "nc")
		nc = atoi(value.c_str());

	else if (key == "nt")
		nt = atoi(value.c_str());

	else if (key == "prob_mutation")
		prob_mutation = atof(value.c_str());

	else if (key == "freq_niching")
		freq_niching = atof(value.c_str());

	else if (key == "alpha")
        alpha_rate = atof(value.c_str());

	else {}

}

//=================================================
// Parameters_file_parsing : split
//=================================================
vector<string> Parameters_file_parsing::split(string const& s, char delim)
{
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim))
		tokens.push_back(item);
	return tokens;
}

//=================================================
// Parameters_file_parsing : list_parameters
//=================================================
void Parameters_file_parsing::list_parameters() const
{
	cout << "########### PARAMETERS ###########\n" << "header => " << header << endl
		<< "n => " << n << endl
		<< "n_it => " << n_it << endl
		<< "nc => " << nc << endl
		<< "nt => " << nt << endl
		<< "prob_mutation => " << prob_mutation << endl
		<< "freq_niching => " << freq_niching << endl
		<< "#################################" << endl;
}

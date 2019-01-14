#ifndef PARAMETERS_FILE_PARSING_H
#define PARAMETERS_FILE_PARSING_H

#include <string>
#include <vector>

class Parameters_file_parsing
{
public:
	Parameters_file_parsing();
	void import_line(std::string const& line);
	void list_parameters() const;

	// Parameters given in the OPTIONS.txt file
	// Reachable from any class that include the current header (Option_file_parsing.hpp)
	int header;
	char separator;
	int n;
	int n_it;
	int nc;
	int nt;
	float prob_mutation;
	float freq_niching;
	float alpha_rate;

	std::string genos_file;
	std::string phenos_file;


private:
	std::vector<std::string> split(std::string const& s, char delim);

};

#endif // PARAMETERS_FILE_PARSING_H


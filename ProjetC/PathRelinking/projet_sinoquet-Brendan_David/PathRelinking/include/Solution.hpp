#ifndef SOLUTION_hpp
#define SOLUTION_hpp
#include <string>
#include <list>
class Solution {
private:
	std::list<std::string> listeDeSnp;
	int score;
public:
	//Constructeur
	Solution();
	Solution(std::list<std::string>,int);

	//Accesseurs
	std::list<std::string> getListeDeSNP();
	void setListeSnp(std::list<std::string>);
	int getScore() :
	void setScore(int);


};

#endif

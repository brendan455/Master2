#include <vector>
#include <string>
#include "..\include\Solution.hpp"

using namespace std;

Solution::Solution() {};
Solution::Solution(list<string> listeSNP, int score) {
	Solution::setScore(score);
	Solution::setListeSnp(listeSNP);
};

list<string> Solution::getListeDeSNP() {
	return this->listeDeSnp;
};

void Solution::setListeSnp(list<string> listeSNP) {
	this->listeDeSnp = listeSNP;
}
void Solution::setScore(int score){
	this->score = score;
};

int Solution::getScore(){
	return this->score;
}:


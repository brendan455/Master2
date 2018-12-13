// Auteur : DENIAUD B. - AIRAULT D.

#ifndef DATE_H
#define DATE_H
class Date
{
private: // Attribut
	int month;
	int day;
	int year;

public: // Méthodes
// Constructeur
		Date();
    	Date(int,int,int);
	
// Accesseur
	void setDay(int);
	int getDay();
	void setMonth(int);
	int getMonth();
	void setYear(int);
	int getYear();
		
// Affichage
	// Affichage d'un date au format XX/XX/XXXX
    void affichage1();
	// Affichage d'un date au format XX/MOIS/XXXX
	void affichage2(int mois);
	// Affichage d'un date au format MOIS/XX/XXXX
	void affichage3(int mois);
	
};
#endif 

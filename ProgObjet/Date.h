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
    	Date(int month,int day,int year);
	
// Accesseur
	void setDay(int);
	int getDay();
	void setMonth(int);
	int getMonth();
	void setYear(int);
	int getYear();
		
// Affichage
	// Affichage d'un date au format XX/XX/XXXX
    	void affichage();
	// Affichage d'un date au format XX/MOIS/XXXX
	void affichage2();
	// Affichage d'un date au format MOIS/XX/XXXX
	void affichage3();
	
};
#endif 

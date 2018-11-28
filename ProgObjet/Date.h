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
    Date(int month,int day,int year);

    // Affichage
    void Debut();
    void Fin();
    void display2();
    void increment();
};
#endif 
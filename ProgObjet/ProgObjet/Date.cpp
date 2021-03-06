// Auteur : DENIAUD B. - AIRAULT D.

#include "Date.h" 
#include <iostream>
#include <string>
using namespace std;




Date::Date() {}
Date::Date(int month, int day, int year){	
	string captage;
	while (year < 1900 || year > 2100) {
		cout << "Annee Invalide, veuillez saisir une annee comprise entre 1900 et 2100" << endl;
		cin >> year;
		getline(cin, captage);
	}
	while (month < 1 || month > 12) {
		cout << "Mois Invalide, veuillez saisir un mois compris entre 1 et 12" << endl;
		cin >> month;
		getline(cin, captage);
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		while (day < 1 || day > 31) {
			cout << "Jour Invalide, veuillez saisir un jour compris entre 1 et 31" << endl;
			cin >> day;
			getline(cin, captage);
		}
	}
	else {
		if (month != 2) {
			while (day < 1 || day > 30) {
				cout << "Jour Invalide, veuillez saisir un jour compris entre 1 et 30" << endl;
				cin >> day;
				getline(cin, captage);
			}
		}
		else {
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				while (day < 1 || day > 29) {
					cout << "Jour Invalide, veuillez saisir un jour compris entre 1 et 29" << endl;
					cin >> day;
					getline(cin, captage);
				}
			}
			else {
				while (day < 1 || day > 28) {
					cout << "Jour Invalide, veuillez saisir un jour compris entre 1 et 28" << endl;
					cin >> day;
					getline(cin, captage);
				}
			}
		}
	}
	Date::setMonth(month);
	Date::setDay(day);
	Date::setYear(year);
};

	//Accesseur
void Date::setDay(int day){
	this->day=day;
};
int Date::getDay(){
	return this->day;
};
void Date::setMonth(int month){
	this->month=month;
};
int Date::getMonth(){
	return this->month;
};
void Date::setYear(int year){
	this->year=year;
};
int Date::getYear(){
	return this->year;
};

// Affichage d'une date au format XX/XX/XXXX
void Date::affichage1()
{
    cout << day <<'/'<< month << '/' << year << endl;
}

// Affichage d'une date au format XX/MOIS/XXXX

void Date::affichage2()
{
    string month;
    switch(getMonth())
    {
        case 1:
			month ="January";
            break;

        case 2:
			month ="February";
            break;

        case 3:
			month ="March";
            break;

        case 4:
			month ="April";
            break;

        case 5:
			month ="May";
            break;

        case 6:
			month ="June";
            break;

        case 7:
			month ="July";
            break;

        case 8:
			month ="August";
            break;

        case 9:
			month ="September";
            break;

        case 10:
			month ="October";
            break;

        case 11:
			month ="November";
            break;

        case 12:
			month ="December";
            break;
    }

	cout << day << '/' << month << '/' << year << endl;
}

// Affichage d'une date au format MOIS/XX/XXXX
void Date::affichage3()
{
    string Month;
    switch(getMonth())
    {
        case 1:
            Month="January";
            break;

        case 2:
            Month="February";
            break;

        case 3:
            Month="March";
            break;

        case 4:
            Month="April";
            break;

        case 5:
            Month="May";
            break;

        case 6:
            Month="June";
            break;

        case 7:
            Month="July";
            break;

        case 8:
            Month="August";
            break;

        case 9:
            Month="September";
            break;

        case 10:
            Month="October";
            break;

        case 11:
            Month="November";
            break;

        case 12:
            Month="December";
            break;
    }

    cout << Month << '/' << day << '/' << year << endl;
}

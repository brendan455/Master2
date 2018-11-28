// Auteur : DENIAUD B. - AIRAULT D.

#include "Date.h" 
#include <iostream>
#include <cassert> 

using namespace std;

// Code du contructeur de Date
Date::Date()
{
    month = 1; // Valeur défaut
    day = 1; // Valeur défaut
    year = 2000; // Valeur défaut
}

              
Date::Date(int Month,int Day,int Year)
{
    if((Month < 1||Month > 12)||(Day < 1||Day > 31)||(Year < 1900||Year > 2020))
    {
        std::cout<<"Invalid"<<std::endl;

    }
    else
    {
        month = Month;
        day = Day;
        year = Year;
    }
}


void Date::increment()
{
    day += 1;
    assert(day >= 1 && day <= 31);
    if(month == 2 && day == 28 || day == 29)
    {
      if(year % 4 || year % 400)
       {
	 std::cout<<"Thats a Leap Year"<<std::endl;
	 // Mois += 1;
	 day += 1 ;
	 // Année ++;
	 assert(day >= 1 && day <= 31);
	 assert(month >= 1 && month <= 12);
       }
     }
    
}

// Affichage d'un élément de type Debut
void Date::Debut()
{
    std::cout<<day<<'/'<<month<<'/'<<year<<std::endl;
}

// Affichage d'un élément de type Fin
void Date::Fin()
{
    std::cout<<day<<'/'<<month<<'/'<<year<<std::endl;
}

// Affichage d'un date au format XX/MOIS/XXXX
void Date::display2()
{
    string Month;
    switch(month)
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

    std::cout<<Month<<'/'<<day<<'/'<<year<<std::endl;
}

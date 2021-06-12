/* 
 * File:   NumDays.h
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 9:17 PM
 * Purpose: Header file for NumDays Class that stores the number of days an employee works
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
private:
    int hrs;
    float days;
public:
    NumDays();
    NumDays(int h);
    //Mutator Functions
    void setHrs(int h) { 
        hrs=h; 
        setDays(); }
    void setDays() { days=hrs/8.0; }
    //Accessor Functions
    int getHrs() { return hrs; }
    float getDays() { return days; }
    //Overload Functions
    NumDays operator+(const NumDays &);
    NumDays operator-(const NumDays &);
    NumDays operator++();
    NumDays operator++(int);
    NumDays operator--();
    NumDays operator--(int);
};

#endif /* NUMDAYS_H */


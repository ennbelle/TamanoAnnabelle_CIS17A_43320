/* 
 * File:   Date.h
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 5:24 PM
 * Purpose: Date Class (including Exceptions)
 */

#ifndef DATE_H
#define DATE_H

class Date {
    //Private class content
    private:
        int day;
        int mo;
        int yr;
    //Public class content
    public:
        //Default Constructor
        Date();
        //Exception Classes
        class InvDay { };
        class InvMo { };
        //Mutator Functions
        void setDay(int d);
        void setMo(int m);
        void setYr(int y) { yr=y; }
        //Accessor Functions
        int getDay() const { return day; }
        int getMo() const { return mo; }
        int getYr() const { return yr; }
        //Print Format
        void prntF1();  //Print in format 1: MM/DD/YYYY
        void prntF2();  //Print in Format 2: Month DD, YYYY
        void prntF3();  //Print in Format 3: DD Month YYYY
        void moEng();   //Printing Month in English
};

#endif /* DATE_H */



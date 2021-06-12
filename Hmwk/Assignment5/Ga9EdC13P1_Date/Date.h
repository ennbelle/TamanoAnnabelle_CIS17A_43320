/* 
 * File:   Date.h
 * Author: Annabelle Tamano
 * Created on May 12, 2021, 9:31 PM
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
        Date();
        void setDay(int d) { day=d; }
        void setMo(int m) { mo=m; }
        void setYr(int y) { yr=y; }
        int getDay() const { return day; }
        int getMo() const { return mo; }
        int getYr() const { return yr; }
        void prntF1();  //Print in format 1: MM/DD/YYYY
        void prntF2();  //Print in Format 2: Month DD, YYYY
        void prntF3();  //Print in Format 3: DD Month YYYY
        void moEng();   //Printing Month in English
};

#endif /* DATE_H */


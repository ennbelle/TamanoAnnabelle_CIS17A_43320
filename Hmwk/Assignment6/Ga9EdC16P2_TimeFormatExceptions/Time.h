/* 
 * File:   Time.h
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 1:33 PM
 * Purpose: Time Class (w/ Exceptions)
 */

#ifndef TIME_H
#define TIME_H

class Time {
protected:
    int hour;
    int min;
    int sec;
public:
    //Default Constructor
    Time();
    //Constructor
    Time(int h,int m,int s);
    //Accessor Functions
    int gHour() const { return hour; }
    int gMin() const { return min; }
    int gSec() const { return sec; }
    //Mutator Functions
    void sHour(int h) { hour=h; }
    void sMin(int m) { min=m; }
    void sSec(int s) { sec=s; }
};

#endif /* TIME_H */


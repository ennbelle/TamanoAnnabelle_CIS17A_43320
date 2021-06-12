/* 
 * File:   MilTime.h
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 1:43 PM
 * Purpose: Military Time Class (w/Exceptions)
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

class MilTime:public Time {
private:
    int milHr;
    int milSec;
public:
    //Default Constructor
    MilTime();
    //Constructor
    MilTime(int mh,int ms);
    void setTime(int mh,int ms);
    //Exception Classes
    class BadHr { };
    class BadSec { };
    //Accessor Functions
    int gHr() { return milHr; }
    int gStdHr() { return gHour(); }
    int gSc() { return milSec; }
    //Mutator Functions
    void sHr(int mh);
    void sSc(int ms);
};

#endif /* MILTIME_H */


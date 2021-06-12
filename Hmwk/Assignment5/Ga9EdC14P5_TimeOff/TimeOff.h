/* 
 * File:   TimeOff.h
 * Author: Annabelle Tamano
 * Created on May 23, 2021, 10:08 PM
 * Purpose: Time off header file
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H
#include "NumDays.h"

class TimeOff {
private:
    int moWork; //months worked at company
    NumDays msdays; //Max Sick Days
    NumDays staken; //Sick Days Taken
    NumDays mvdays; //Max Vacation Days
    NumDays vtaken; //Vacation Days Taken
    static NumDays munpaid; //Max Unpaid Days
    NumDays unpaidt;   //Unpaid Taken
public:
    TimeOff();
    TimeOff(int mw,int st,int vt);
    void print();
};

#endif /* TIMEOFF_H */


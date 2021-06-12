/* 
 * File:   TimeOff.cpp
 * Author: Annabelle Tamano 
 * Created on May 23, 2021, 10:08 PM
 * Purpose: Time Off member Functions
 */
#include <iostream>
using namespace std;

#include "TimeOff.h"
#include "NumDays.h"

//Static Variables
NumDays TimeOff::munpaid(112);

//Default Constructor
TimeOff::TimeOff() {
    int moWork=0; //months worked at company
    NumDays msdays; //Max Sick Days
    NumDays staken; //Sick Days Taken
    NumDays mvdays; //Max Vacation Days
    NumDays vtaken; //Vacation Days Taken
    NumDays unpaidt;   //Unpaid Taken
}

//Programmer-Defined Constructor
TimeOff::TimeOff(int mw,int st,int vt) {
    int temp=0;
    moWork=mw;
    temp=((moWork*8)>240)?240:moWork*8;
    msdays.setHrs(temp);
    temp=((moWork*12)>240)?240:moWork*12;
    mvdays.setHrs(temp);
    staken.setHrs(st);
    vtaken.setHrs(vt);
    unpaidt=(staken-msdays)+(vtaken-mvdays);
    if(unpaidt.getHrs()<0) unpaidt.setHrs(0);
}

void TimeOff::print() {
    cout<<"Max Unpaid Days Available: "<<munpaid.getDays()<<endl;
    cout<<"Max Sick Days: "<<msdays.getDays()<<endl;
    cout<<"Max Vacation Days: "<<mvdays.getDays()<<endl;
    cout<<"Sick Days Taken: "<<staken.getDays()<<endl;
    cout<<"Vacation Days Taken: "<<vtaken.getDays()<<endl;
    cout<<"Unpaid Days Off Taken: "<<unpaidt.getDays()<<endl;
    if(munpaid.getDays()<unpaidt.getDays()) cout<<"Warning: You've exceed number of days for unpaid leave! You must consult with HR immediately.\n";
}



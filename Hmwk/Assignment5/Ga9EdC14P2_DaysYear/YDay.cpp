/* 
 * File:   YDay.cpp
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 6:50 PM
 * Purpose: Member Functions for Days in Year (YDay)
 */

#include <iostream>
using namespace std;

#include "YDay.h"

//Static Variables
int YDay::lmo[12]={31,28,31,30,31,30,31,31,30,31,30,31};
string YDay::moname[12]={"January","February","March","April","May","June","July",
                         "August","September","October","November","December"};

//Default Constructor
YDay::YDay() {
    day=0; }

//Programmer-Defined Constructor
YDay::YDay(int d) {
    day=d; }

//Print Function in Month-Day Format
void YDay::print() {
    int td=day;
    int mo=0;
    
    while(td>lmo[mo]) {
        td-=lmo[mo];
        mo++; }
    
    cout<<"Day "<<day<<" is "<<moname[mo]<<" "<<td;
}




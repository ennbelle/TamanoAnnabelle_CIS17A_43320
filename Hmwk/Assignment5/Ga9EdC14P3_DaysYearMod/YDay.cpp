/* 
 * File:   YDay.cpp
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 7:50 PM
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
    day=0;
    works=true; }

//Programmer-Defined Constructor
YDay::YDay(int d) {
    day=d; }

//Modified Programmer-Defined Constructor
YDay::YDay(string m, int d) {
    int ind=-1;
    works=false;
    day=d;
    
    for(int i=0;i<12;i++) {
        if(m==moname[i]) {
            ind=i;
            works=true;
            break; }
    }
    
    if(ind<0) {
        cout<<"Sorry the information you entered is not valid.\n";
    }else {
        //validate: makes sure that the days entered are fit within the month entered
        day=(day>lmo[ind])?lmo[ind]:day;
        //add rest of the days
        if(ind!=0) {
            for(int i=0;i<ind;i++) {
                day+=lmo[i]; }
        }
    }
}

//Print Function in Month-Day Format
void YDay::print() {
    int td=day;
    int mo=0;
    
    while(td>lmo[mo]) {
        td-=lmo[mo];
        mo++; }
    
    cout<<"Day "<<day<<" is "<<moname[mo]<<" "<<td;
}

//Overload ++ operator
YDay YDay::operator++(int) {
    YDay temp(day);
    day++;
    return temp; }

//Overload -- operator
YDay YDay::operator--(int) {
    YDay temp(day);
    day--;
    return temp; }
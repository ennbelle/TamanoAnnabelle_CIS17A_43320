/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 23, 2021, 7:59 PM
 * Purpose: Time off program
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "NumDays.h"
#include "TimeOff.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    int mw; //months worked
    int st; //sick hours taken
    int vt; //vacation hours taken
    cout<<"Enter months worked at company: ";
    cin>>mw;
    mw=(mw<0)?0:mw;
    cout<<"Enter hours of sick leave taken: ";
    cin>>st;
    st=(st<0)?0:st;
    cout<<"Enter hours of vacation leave taken: ";
    cin>>vt;
    vt=(vt<0)?0:vt;
    TimeOff emp1(mw,st,vt);
    
    //Output
    emp1.print();
    //Clean Up and Exit Program
    return 0;
}


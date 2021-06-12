/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 1:02 PM
 * Purpose: Time & MilTime Class Driver (Demonstrating Exceptions)
 */

//System Libraries
#include <iostream>
#include <valarray>
using namespace std;

//User Libraries
#include "MilTime.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    MilTime t1;
    int h=0;
    int s=0;
    
    //Map Original Input to Output
    cout<<"Enter Miltary Time ( e.g. 2359 -> 11:59 PM ): ";
    cin>>h;
    cout<<"Enter Seconds: ";
    cin>>s;
    try {
        t1.setTime(h,s);
        cout<<"Miltary Format - ";
        if(t1.gHr()<1000) { cout<<"0"; }
        cout<<t1.gHr()<<":";
        if(t1.gSc()<10) { cout<<"0"; }
        cout<<t1.gSc()<<endl;
        cout<<"Standard Format - "<<t1.gStdHr()<<":";
        if(t1.gMin()<10) { cout<<"0"; }
        cout<<t1.gMin()<<":";
        if(t1.gSec()<10) { cout<<"0"; }
        cout<<t1.gSec();
        if(t1.gHr()>1159) { cout<<" PM"<<endl; }
        else { cout<<" AM"<<endl; }
    }
    catch(MilTime::BadHr) {
        cout<<"ERROR: The military format hour provided is out of range."<<endl; }
    catch(MilTime::BadSec) {
        cout<<"ERROR: The seconds provided are out of range."<<endl;
    }
    
    
    //Clean Up & Exit Program
    return 0;
}


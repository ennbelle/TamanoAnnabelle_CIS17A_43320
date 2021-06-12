/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 1:02 PM
 * Purpose: Time & MilTime Class Driver
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "MilTime.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    int h=0;
    int s=0;
    
    //Map Original Input to Output
    cout<<"Enter Miltary Time ( e.g. 2359 -> 11:59 PM ): ";
    cin>>h;
    cout<<"Enter Seconds: ";
    cin>>s;
    MilTime t1(h,s);
    
    //Print Original
    cout<<"Military Format - ";
    if(t1.gHr()<1000) { cout<<0; }
    cout<<t1.gHr()<<":";
    if(t1.gSc()<10) { cout<<0; }
    cout<<t1.gSc()<<endl;
    cout<<"Standard Format - "<<t1.gStdHr()<<":";
    if(t1.gMin()<10) { cout<<0; }
    cout<<t1.gMin()<<":";
    if(t1.gSec()<10) { cout<<0; }
    cout<<t1.gSec();
    if(t1.gHr()>1159) { cout<<" PM"<<endl; }
    else { cout<<" AM"<<endl; }
    
    //Change Time and Output
    cout<<endl<<"Changing Time..."<<endl;
    cout<<"Enter NEW Military Time: ";
    cin>>h;
    cout<<"Enter NEW Seconds: ";
    cin>>s;
    t1.setTime(h,s);
        cout<<"Miltary Format - ";
    if(t1.gHr()<1000) { cout<<0; }
    cout<<t1.gHr()<<":";
    if(t1.gSc()<10) { cout<<0; }
    cout<<t1.gSc()<<endl;
    cout<<"Standard Format - "<<t1.gStdHr()<<":";
    if(t1.gMin()<10) { cout<<0; }
    cout<<t1.gMin()<<":";
    if(t1.gSec()<10) { cout<<0; }
    cout<<t1.gSec();
    if(t1.gHr()>1159) { cout<<" PM"<<endl; }
    else { cout<<" AM"<<endl; }
    
    
    //Clean Up & Exit Program
    return 0;
}


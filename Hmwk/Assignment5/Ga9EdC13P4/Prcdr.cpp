/* 
 * File:   Prcdr.cpp
 * Author: Annabelle
 * Created on May 20, 2021, 1:22 PM
 */

//System Library
#include <iostream>
#include <iomanip>
using namespace std;

//User Library
#include "Prcdr.h"

//Constructor
Prcdr::Prcdr() {
    pname="";
    date="";
    prname="";
    charge=0.0f; }

//Programmer-Defined Constructor
Prcdr::Prcdr(string pn,string d, string prn, float c) {
    pname=pn;
    date=d;
    prname=prn;
    charge=c; }

//outp() Function
void Prcdr::outp() {
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Procedure Name: "<<pname
            <<"\nDate: "<<date
            <<"\nPractitioner: "<<prname
            <<"\nCharge: $"<<charge;
}


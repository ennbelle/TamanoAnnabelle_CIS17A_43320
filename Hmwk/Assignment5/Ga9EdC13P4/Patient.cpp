/* 
 * File:   Patient.cpp
 * Author: Annabelle Tamano
 * 
 * Created on May 19, 2021, 11:12 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Patient.h"

//Default Constructor
Patient::Patient() {
    fname="";
    mname="";
    lname="";
    add="";
    city="";
    stte="";
    zpCode=0;
    fnum=0;
    eName="";
    eFnum=0; }

//Programmer-Defined Constructor
Patient::Patient(string fn,string mn,string ln, string a, string ct,
        string st,int zc,int f,int ef,string en) {
    //Change
    fname=fn;
    mname=mn;
    lname=ln;
    add=a;
    city=ct;
    stte=st;
    zpCode=zc;
    fnum=f;
    eFnum=ef;
    eName=en; }

//outp() Function
void Patient::outp() {   
    cout<<"Name: "<<fname<<" "<<mname<<" "<<lname<<"\nAddress: "<<
            add<<" "<<city<<", "<<stte<<" "<<zpCode<<"\nPhone Number: "<<
            fnum<<"\nEmergency Contact: "<<eName;
    cout<<"\nPhone Number: "<<eFnum;
}

/* 
 * File:   Emp.cpp
 * Author: Annabelle Tamano
 * Created on May 26,2021, 11:22 AM
 */

//System Libraries
using namespace std;

//User Libraries
#include "Emp.h"

//Default Constructor
Emp::Emp() {
    name=new char[80];
    empNum=0;
    hDate=new char[15]; }

//Programmer-Defined Constructor
Emp::Emp(char* n,int en,char* hd) {
    name=new char[strlen(n+1)];
    hDate=new char[strlen(hd+1)];
    name=n;
    empNum=en;
    hDate=hd; }



/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 9:13 PM
 * Purpose: Driver for NumDays Class
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "NumDays.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    int h1=0;
    int h2=0;
    
    //Get Information from User
    cout<<"Enter hours worked by employee #1: ";
    cin>>h1;
    h1=(h1<0)?(h1*-1):h1;
    NumDays emp1(h1);
    cout<<"Enter hours worked by employee #2: ";
    cin>>h2;
    h2=(h2<0)?(h2*-1):h2;
    NumDays emp2(h2);
    
    //Process then Output
    cout<<"Days worked by employee #1: "<<emp1.getDays()<<endl;
    cout<<"Days worked by employee #2: "<<emp2.getDays()<<endl;
    
    NumDays add1;
    add1=emp1+emp2;
    cout<<"Both employee hours added: "<<add1.getHrs()<<endl;
    
    NumDays sub1;
    sub1=emp1-emp2;
    cout<<"Difference between both employee hours: "<<sub1.getHrs()<<endl;
    
    ++emp1;
    cout<<"Number of days worked after prefix increment of employee #1: "<<emp1.getDays()<<endl;
    
    --emp1;
    cout<<"Number of days worked after prefix decrement of employee #1: "<<emp1.getDays()<<endl;
    
    emp2++;
    cout<<"Number of days worked after postfix increment of employee #2: "<<emp2.getDays()<<endl;
    
    emp2--;
    cout<<"Number of days worked after postfix decrement of employee #2: "<<emp2.getDays()<<endl;
    
    
    //Clean Up & Exit Program
    return 0;
}


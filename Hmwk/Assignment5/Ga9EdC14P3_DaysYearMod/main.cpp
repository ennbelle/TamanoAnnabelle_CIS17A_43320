/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 7:48 PM
 * Purpose: Driver for Days in Year Class (YDay)
 */

//System libraries
#include <iostream>
using namespace std;

//User Libraries
#include "YDay.h"
//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variable
    string um; //User Input
    int ud;    //User Input Day
    
    //Map Input to Output
    cout<<"Enter month name (NOTE: Case-sensitive.): ";
    cin>>um;
    cout<<"Enter day of month (1-31): ";
    cin>>ud;
    ud=(ud<1)?1:(ud>31)?31:ud;
    YDay d1(um,ud);
    
    //Output
    if(d1.getWrks()==true) {
        d1.print();
        d1++;
        cout<<"\n\nIncrement One Day...\n";
        d1.print();
        d1--;
        cout<<"\n\nDecrement One Day...\n";
        d1.print();
    }
    
    //Clean Up & Exit Function
    return 0;
}

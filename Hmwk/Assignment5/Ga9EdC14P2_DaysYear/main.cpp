/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 6:46 PM
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
    YDay d1;
    int ud; //User Input
    
    //Map Input to Output
    cout<<"Enter Day of Year (1-365): ";
    cin>>ud;
    ud=(ud<1)?1:(ud>365)?365:ud;
    d1.setD(ud);
    
    //Output
    d1.print();
    
    //Clean Up & Exit Function
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 6th, 2021, 2:20 PM
 * Purpose:  Our First Class
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
using namespace std;

//User Libraries
#include "array.h"

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int size=100;
    int perLine=10;
    Array array(size);
    //Initialize all known variables
    cout<<"Before Sorting"<<endl;
    array.prntAry(perLine);
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    array.markSrt();
    
    //Display the Inputs/Outputs
    cout<<"After Sorting"<<endl;
    array.prntAry(perLine);

    //Clean up the code, close files, deallocate memory, etc....
    
    //Exit stage right
    return 0;
}


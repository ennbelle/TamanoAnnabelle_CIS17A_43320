/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 12, 2021, 9:28 PM
 * Purpose: Date
 *          Stores the Date in a class that can print it in all three formats:
 *          12/25/2018
 *          December 25, 2018
 *          25 December 2018
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Date.h" 

//Global Constant

//Function Prototypes

//Function Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    Date exmpl; //Class to store date
    int temp=0; //temporary value
    
    //Map Inputs to Outputs
    //Get Date
    cout<<"Enter Day(1-31): ";
    cin>>temp;
    temp=(temp<1)?1:(temp>31)?31:temp; //validate that number is between 1-31
    exmpl.setDay(temp);
    //Get Month
    cout<<"Enter Month(1-12): ";
    cin>>temp;
    temp=(temp<1)?1:(temp>12)?12:temp; //validate that number is between 1-12
    exmpl.setMo(temp);
    //Get Year
    cout<<"Enter Year: ";
    cin>>temp;
    exmpl.setYr(temp);
    
    //Output
    cout<<endl<<"Printing Date..."<<endl;
    cout<<"Format 1: ";
    exmpl.prntF1();
    cout<<endl<<"Format 2: ";
    exmpl.prntF2();
    cout<<endl<<"Format 3: ";
    exmpl.prntF3();
    cout<<endl<<endl;
    
    //Exit and Clean up Function
    return 0;
}


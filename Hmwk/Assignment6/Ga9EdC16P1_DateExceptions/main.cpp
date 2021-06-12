/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 4:54 PM
 * Purpose: Driver of Date Class - Displays Use of Exceptions
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
    bool fp=true; //function properly
    
    //Map Inputs to Outputs
    //Get Date
    cout<<"Enter Day(1-31): ";
    cin>>temp;
    
    try { exmpl.setDay(temp); }
    catch (Date::InvDay) {
        cout<<"Error: The day entered is out of range."<<endl; 
        fp=false;}
    
    if(fp==true) {
        //Get Month
        cout<<"Enter Month(1-12): ";
        cin>>temp;
        try { exmpl.setMo(temp); }
        catch (Date::InvMo) {
            cout<<"Error: The month entered is out of range."; 
            fp=false; }
        
        if(fp==true) {
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
            cout<<endl<<endl; }
    }
    
    //Exit and Clean up Function
    return 0;
}


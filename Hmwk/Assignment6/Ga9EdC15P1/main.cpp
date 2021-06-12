/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 26, 2021, 11:19 AM
 * Purpose: Driver Program for Emp & PWorker Classes
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "PWorker.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    char n[]="Elaine";
    char hd[]="12/20/2020";
    PWorker wrkr(n,1050,hd,2,13.59);
    
    //Output
    cout<<"Employee: "<<wrkr.gName()<<endl
            <<"Employee Number: "<<wrkr.gENum()<<endl
            <<"Hire Date: "<<wrkr.gHDate()<<endl
            <<"Shift: ";
    if(wrkr.gShft()==1) {
        cout<<"Day";
    } else {
        cout<<"Night"; }
    cout<<endl<<"Pay Rate: $"<<wrkr.gPRate()<<endl;
    
    //Clean Up and End Program
    return 0;
}


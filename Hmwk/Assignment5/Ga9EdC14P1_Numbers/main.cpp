/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 5:52 PM
 * Purpose: Driver for Number Class
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Nums.h"
//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    int n=0;
    Nums cn;
    
    //Map inputs to outputs
    cout<<"Enter a number from 0-9999: ";
    cin>>n;
    n=(n<0)?0:(n>9999)?9999:n; //Validate Information to stay in range 0-9999
    cn.setN(n);
    
    //output
    cn.print();
    
    //Clean Up & Exit Program
    return 0;
}


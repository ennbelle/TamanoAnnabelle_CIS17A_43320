/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 30, 2021, 2:15 PM
 * Purpose: Create Absolute Value Template
 */

//System libraries
#include <iostream>
using namespace std;

//User Libraries
template<class T>
T getAbs(T val) {
    if(val<0) { return (val*-1); }
    else { return val; }
}
//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize Variables
    int i;
    float f;
    char c;
    
    //Process
    cout<<"Enter positive or negative integer value: ";
    cin>>i;
    cout<<"Enter positive or negative float value: ";
    cin>>f;
    cout<<"Enter positive or negative char value: ";
    cin>>c;
    
    //Output
    cout<<endl<<endl<<"Absolute value of int ("<<i<<"): "<<getAbs(i)<<endl;
    cout<<"Absolute value of float ("<<f<<"): "<<getAbs(f)<<endl;
    cout<<"Absolute value of char ("<<c<<"): "<<getAbs(c)<<endl;
    
    //Clean up and Exit
    return 0;
}


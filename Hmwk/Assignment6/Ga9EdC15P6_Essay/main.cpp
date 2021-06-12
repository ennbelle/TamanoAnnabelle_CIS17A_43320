/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 2:45 PM
 * Purpose: Essay Class Driver
 */

//System Libraries
#include <iostream>
#include <cctype>
using namespace std;

//User Libraries
#include "Essay.h"

//Global Constants

//Function Prototype
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    float g;
    float s;
    float cl;
    float cnt;
    char opt;
    
    //Map Input to Output
    cout<<"Enter Essay Grade Details!\n";
    cout<<"(NOTE: If the value entered is under 0 or over the maximum value indicated,\n"
            <<"the program will automatically change the value to 0 or the maximum value!)\n";
    cout<<"Grammar (30 pts): ";
    cin>>g;
    cout<<"Spelling (20 pts): ";
    cin>>s;
    cout<<"Correct Length (20 pts): ";
    cin>>cl;
    cout<<"Content (30 pts): ";
    cin>>cnt;
    Essay s1(g,s,cl,cnt);
    
    //Output
    cout<<endl<<"RESULTS..."<<endl;
    cout<<"Essay Grade: "<<s1.gLttr()<<endl;
    cout<<"Would you like to see a break down of your score? (\'y\' or \'n\')  ";
    cin>>opt;
    if (tolower(opt)=='y') { s1.prnt(); }
    cout<<endl<<"Goodbye!"<<endl;
    
    //CLean Up & End Program
    return 0;
}


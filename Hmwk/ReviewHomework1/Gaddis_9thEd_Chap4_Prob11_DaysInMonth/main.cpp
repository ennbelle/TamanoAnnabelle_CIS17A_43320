/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 6, 2021, 9:01 AM
 * Purpose: This program asks the user to input month and year and outputs the
 *          number of days in that month, keeping in mind whether the year is a 
 *          leap year.
 */

//System Libraries
#include <iostream> // I/O Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays

// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) {
    // Initialize the Random Number Seed
    
    // Declare Variables
    unsigned short month;
    unsigned short year;
    unsigned char i;
    const unsigned char days[]={31,28,31,30,31,30,31,31,30,31,30,31,29};
    
    // Initialize Variables
    month=0;
    year=0;
    i=0;
    
    // Map Input to Outputs -> Process
    cout<<"Enter a month (1-12): ";
    cin>>month;
    while (month<1||month>12){
        cout<<"That is not a valid value for month! Enter a month (1-12): ";
        cin>>month;
    }
    
    cout<<"Enter a year: ";
    cin>>year;
    
    if(month==2){
        if(year%100==0 && year%400==0)
            i=12;
        else if (year%4==0)
            i=12;
        else
            i=1;
    }else{
        i=month-1;
    }
    
    // Display Inputs/Outputs
    cout<<"There are "<<static_cast<int>(days[i])<<" days!"<<endl;
    
    // Exit the program - Cleanup
    return 0;
}


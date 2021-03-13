/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 6, 2021, 9:34 AM
 * Purpose: This program predicts the size of a population of organisms based 
 *          on the starting number of organisms, their average daily population
 *          increase (as a percentage), and the number of days they will multiply.
 */

//System Libraries
#include <iostream> // I/O Library
#include <iomanip>  // Format Library
#include <cmath>    // For the pow function
using namespace std;


// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays

// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) {
    // Initialize the Random Number Seed
    
    // Declare Variables
    unsigned short days;     // number of days observing the population growth
    unsigned char i;         // index
    float avgIncr;           // average percentage increase per day
    
    // Initialize Variables
    i=0;
    avgIncr=0.0f;
    
    // Map Input to Outputs -> Process
    do {
        cout<<"Enter number of days observing species growth (WARNING: can't be less than 1): ";
        cin>>days;
    } while(days<1);
    
    unsigned short dlyPop[days];   // set size of array for daily population
    
    do {
        cout<<"Enter initial population (WARNING: can't be less than 2): ";
        cin>>dlyPop[i];
    } while(dlyPop[i]<2);
    
    do {
        cout<<"Enter percentage of average population increase per day (WARNING: can't be  negative): ";
        cin>>avgIncr;
    } while(avgIncr<0.0f);
    
    for(i=1;i<days;i++) {
        dlyPop[i]=dlyPop[0]*pow(1.0f+avgIncr,static_cast<float>(i));
    }
    
    // Display Inputs/Outputs
    cout<<endl<<setw(6)<<"Day"<<setw(20)<<"Population Size"<<endl;
    for(i=0;i<days;i++) {
       cout<<setw(5)<<i+1<<setw(15)<<dlyPop[i]<<endl; }
    
    // Exit the program - Cleanup
    return 0;
}


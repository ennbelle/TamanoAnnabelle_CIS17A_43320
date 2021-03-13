/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on February 26, 2021, 1:12 AM
 * Purpose: This program converts Celsius temperatures to Fahrenheit temperatures
 */

//System Libraries
#include <iostream> // I/O Library
#include <iomanip>  // Format Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays
const float CF=9.0f/5.0f;   // degrees in Celsius to degrees in Fahrenheit
// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) {
    // Initialize the Random Number Seed
    
    // Declare Variables
    float C,    // stores temperature degrees Celsius
          F;    // stores temperature in degrees Fahrenheit
    
    // Initialize Variables
    C=0.0f;
    F=0.0f;
    
    // Map Input to Outputs -> Process
    cout<<"Input the temperature (in degrees Celsius): ";
    cin>>C;
    F=CF*C+32;
    
    // Display Inputs/Outputs
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<C<<" degrees Celsius = "<<F<<" degrees Fahrenheit";
    
    // Exit the program - Cleanup
    return 0;
}

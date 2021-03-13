/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 7, 2021, 8:36 PM
 * Purpose: This program converts Fahrenheit temperatures from 0 to 20 degrees 
 *          into Celsius, then prints out a table displaying the results. 
 */


//System Libraries
#include <iostream> // I/O Library
#include <iomanip>  // Format Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays
const float FC=5.0f/9.0f;   // degrees in Celsius to degrees in Fahrenheit

// Function Prototypes
float celsius(char); //Function converts Fahrenheit to Celsius

// Execution Begins Here
int main(int argc, char** argv) {
    // Initialize the Random Number Seed
    
    // Declare Variables
    char f;         // Temperature in Degrees Fahrenheit
    float c[20];    // Array to hold Temperatures in Degrees Celsius
    
    // Initialize Variables
    
    // Map Input to Outputs -> Process
    // Go through all Fahrenheit temperatures and call function to convert to Celsius
    for ( f = 0; f <= 20; f++) {
        c[f] = celsius(f);
    }
    
    // Display Inputs/Outputs
    cout << setprecision(1) << fixed << showpoint;
    cout << "CELSIUS TEMPERATURE TABLE\n";
    cout << setw(10) << "Fahrenheit" << setw(10) << "Celsius\n";
    
    for ( f = 0; f <= 20; f++) {
        cout << setw(5) << static_cast<int>(f) << setw(13) << c[f] << endl;
    }
    
    // Exit the program - Cleanup
    return 0;
}

// Convert from Fahrenheit to Celsius
float celsius( char f ) {
    return FC*(f-32);
}
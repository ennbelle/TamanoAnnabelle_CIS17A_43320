/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on February 26, 2021, 2:51 AM
 * Purpose: This program converts US Dollars to Japanese Yen and Euro.
 */

//System Libraries
#include <iostream> // I/O Library
#include <iomanip>  // Format Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays
const float JPYUSD=106.93f;   // Rate of Japanese Yens per US Dollar
const float EUROUSD=0.83f;   // Rate of Euros per US Dollar

// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) {
    // Initialize the Random Number Seed
    
    // Declare Variables
    float jpy,      // stores currency in yen
          eur,    // stores currency in euros
          usd;      // stores currency in dollar
    
    // Initialize Variables
    jpy=0.0f;
    eur=0.0f;
    usd=0.0f;
    
    // Map Input to Outputs -> Process
    cout<<"This program converts U.S. Dollars to Japanese Yen and Euros.\n\n"
        <<"U.S. Dollars = $";
    cin>>usd;
    
    jpy=usd*JPYUSD;
    eur=usd*EUROUSD;
    
    // Display Inputs/Outputs
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"\nJapanese Yen = "<<jpy<<" JPY"
            <<"\nEuro = "<<eur<<" EUR";
    
    // Exit the program - Cleanup
    return 0;
}


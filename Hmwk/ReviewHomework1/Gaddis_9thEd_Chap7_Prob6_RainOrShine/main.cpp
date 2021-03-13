/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 7, 2021, 9:44 PM
 * Purpose: This program stores an amateur meteorologist's weather condition data
 *          for the past year's three-month summer season in a 2D (3X30) array from
 *          a file "RainOrShine.txt". Note the data does not count any data for the
 *          31st of any month. The program then creates a report that displays for
 *          each month and for the whole three-month period, how many days were rainy,
 *          how many days were cloudy, and how many were sunny. It also reports
 *          which of the three months had the largest number of rainy days.
 */

//System Libraries
#include <iostream> // I/O Library
#include <iomanip>  // Format Library
#include <fstream>  // I/O File Stream Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays

// Function Prototypes
unsigned char mstRain(const unsigned char[]); // finds which month has most rainy days
unsigned char cntTtl(const unsigned char[]);    // counts total number of days

// Execution Begins Here
int main(int argc, char** argv) {
    // Initialize the Random Number Seed
    
    // Declare Variables
    ifstream inFile;        // input file stream that holds weather
    char weather[3][30];    // 2D array that holds weather data for summer
    unsigned char rainMo;   // holds numerical value of which month has most rain
    unsigned char ttlRain;  // holds total rainy days of all three months
    unsigned char ttlSun;   // holds total sunny days of all three months
    unsigned char ttlCld;   // holds total cloudy days of all three months
    
    // Initialize Variables
    inFile.open("RainOrShine.txt"); //open text file to be used in program
    string months[3]={"June","July","August"};  // holds Month name
    unsigned char rainy[3]={0,0,0}; // holds number of rainy days each month
    unsigned char sunny[3]={0,0,0}; // holds number of sunny days each month
    unsigned char cloudy[3]={0,0,0}; // holds number of cloudy days each month
    
    // Map Input to Outputs -> Process
    for(unsigned char m=0;m<3;m++) {
        for(unsigned char d=0;d<30;d++) {
            inFile>>weather[m][d]; //get weather data from input file stream
            //count number of sunny, rainy, and cloudy days each month
            // this operates on the assumption that the input file stream only
            // contains characters 'R','S', and 'C'
            if (weather[m][d]=='R') {rainy[m]+=1;}
            else if(weather[m][d]=='S') {sunny[m]+=1;}
            else {cloudy[m]+=1;}
        }
    }
    
    rainMo=mstRain(rainy); // call mstRain function to get month that has most rain
    ttlRain=cntTtl(rainy);  // call cntTtl function to  find total rainy days
    ttlSun=cntTtl(sunny);   // call cntTtl function to  find total sunny days
    ttlCld=cntTtl(cloudy);  // call cntTtl function to  find total cloudy days
    
    // Display Inputs/Outputs
    cout<<"SUMMER WEATHER REPORT\n"
        <<"NOTE:This program does not calculate the 31st day of the months.\n\n";
    cout<<setw(20)<<"Rainy Days"<<setw(14)<<"Sunny Days"<<setw(15)<<"Cloudy Days\n";
    for(unsigned char i=0;i<3;i++) {
        cout<<setw(7)<<months[i]<<setw(8)<<static_cast<int>(rainy[i])
                <<setw(14)<<static_cast<int>(sunny[i])
                <<setw(13)<<static_cast<int>(cloudy[i])<<endl;
    }
    cout<<setw(7)<<"Total"<<setw(8)<<static_cast<int>(ttlRain)
            <<setw(14)<<static_cast<int>(ttlSun)
            <<setw(13)<<static_cast<int>(ttlCld)<<endl;
    
    cout<<"\nThe month with the most rainy days is "<<months[rainMo]<<".\n";
    
    // Exit the program - Cleanup
    inFile.close();
    return 0;
}

// Start mstRain Function - calculate which month has the most rainy days
unsigned char mstRain(const unsigned char rain[]) {
    // Declare Variables in mstRain Function
    unsigned char indMst;   // Index of Most Rain
    
    // Initialize Variables
    indMst=0;
    
    // Map Input to Outputs -> Process
    // Loop through rain array and compare each value to find the month with the most rainy days
    for(unsigned char i=0;i<3;i++) {
        if (rain[indMst]<rain[i]) {
            indMst=i; }
    }
    
    // Exit Function -> Return Value
    return indMst;
}

//Start cntTtl Function - calculate total number of days that a weather condition occurs
unsigned char cntTtl(const unsigned char wthrCon[]) {
    //Declare Variables in cntTtl Function
    unsigned char ttl;  // holds total number of days
    
    // Initialize Variables
    ttl=0;
    
    // Process
    for(unsigned char i=0;i<3;i++) {
        ttl+=wthrCon[i]; }
    
    // Exit Function -> Return Value
    return ttl;
}


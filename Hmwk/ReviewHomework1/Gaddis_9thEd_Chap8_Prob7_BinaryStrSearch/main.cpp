/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 7, 2021, 11:36 PM
 * Purpose: This program modifies the binary search function so it searches an
 *          array of strings and tests the function with a driver program.
 */

//System Libraries
#include <iostream> // I/O Library
#include <string>  // String Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays

// Function Prototypes
void slctnSo(string [],const unsigned char); //This function does the selection sort
void swap(string&,string&);
char bnrySe(string [],const char,string);

// Execution Begins Here
int main(int argc, char** argv) {
    // Initialize the Random Number Seed
    
    // Declare Variables
    string srchNam;     // name to be searched in names array
    char fndInd;   // Index name (srchNam) is found in names array
    
    // Initialize Variables
    const unsigned char NAMENUM=20;     // number of names in names array
    string names[NAMENUM]={"Collins, Bill","Smith, Bart","Allen, Jim","Griffin, Jim",
                           "Stamey, Marty","Rose, Geri","Taylor, Terri","Johnson, Jill",
                           "Allison, Jeff","Looney, Joe", "Wolfe, Bill","James, Jean",
                           "Weaver, Jim", "Pore, Bob", "Rutherford, Greg","Javens, Renee",
                           "Harrison, Rose","Setzer, Cathy","Pike, Gordon","Holland, Beth"};
    
    // Map Input to Outputs -> Process
    // Show unsorted array
    cout<<"UNSORTED NAMES: \n";
    for(unsigned char i=0;i<NAMENUM;i++) {cout<<names[i]<<endl;}
    //Short array then display
    slctnSo(names,NAMENUM);
    cout<<"\nSORTED NAMES:\n";
    for(unsigned char i=0;i<NAMENUM;i++) {cout<<names[i]<<endl;}
    
    // prompt user to enter name to be searched for
    cout<<"\nEnter name to be searched for in array: ";
    getline(cin,srchNam);
    // Find using binary search function
    fndInd=bnrySe(names,NAMENUM,srchNam);
    
    // Display Inputs/Outputs
    if (fndInd==-1){cout<<srchNam<<" is not in the list!";}
    else {cout<<names[fndInd]<<" is found in position "<<static_cast<int>(fndInd);}
    
    // Exit the program - Cleanup
    return 0;
}

// swap function - swaps position of two strings
void swap(string& str1,string& str2) {
    string temp=str1;
    str1=str2;
    str2=temp;   
}

// selection sort function
void slctnSo(string array[],const unsigned char size) {
    // Declare and Initialize variables
    unsigned char minInd;
    string minVal;
    
    // Process
    for(unsigned char i=0;i<(size-1);i++) {
        minInd=i;
        minVal=array[i];
        // find minValue
        for(unsigned char j=i+1;j<size;j++) {
            if(array[j]<minVal) {
                minVal=array[j];
                minInd=j; }
        }
        // call swap function
        swap(array[minInd],array[i]);
    }
}

// binary search function
char bnrySe(string arr[],char size, string srch) {
    // Declare Variables
    unsigned char start;    // holds position of starting element of search
    unsigned char end;      // holds position of ending element of search
    unsigned char mid;      // holds position of midpoint of search
    
    // Initialize variables
    start=0;
    end=size-1;
    
    // Process: Binary Search
    while(start<=end) {
        mid=(start+end)/2;
        if(arr[mid]==srch) {return mid;}
        else if(arr[mid]>srch) {end=mid-1;}
        else {start=mid+1;}
    }
    
    //Exit Function 
    return -1;
}
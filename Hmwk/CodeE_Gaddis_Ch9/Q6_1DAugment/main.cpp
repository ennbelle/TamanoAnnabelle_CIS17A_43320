/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 28, 2021, 12:33 PM
 * Purpose: Augment a 1D Array
 */

//System Libraries
#include <iostream> // I/O Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays

// Function Prototypes
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int *array, //holds user inputed array
        arySize; //holds array size
    //Fill Array
    array=getData(arySize);
    //Augment array so first element is 0
    int *augAry=augment(array,arySize);
    //Print Both Arrays
    prntAry(array,arySize);
    cout<<endl;
    prntAry(augAry,arySize+1);
    //Exit Program -- Clean Up
    delete [] array;
    delete [] augAry;
    return 0;
}

//getData Function
int *getData(int& n) {
    cin>>n;
    //Allocate Memory
    int *ary=new int[n];
    //Fill the Array
    for(unsigned char i=0;i<n;i++) {
        cin>>*(ary+i); }
    //Exit the Function
    return ary;
}

//augment Function
int *augment(const int *ary,int n) {
    //Allocate Memory
    int *aug=new int[n+1];
    //Fill new array
    *aug=0;
    for(unsigned char i=0;i<n;i++){
        aug[i+1]=ary[i]; }
    //Exit the Function
    return aug;
}

//prntAry Function
void prntAry(const int *ary,int n) {
    for(unsigned char i=0;i<n;i++) {
        cout<<*(ary+i);
        if(i!=(n-1)) cout<<" "; }
}


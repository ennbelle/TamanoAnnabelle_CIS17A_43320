/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 28, 2021, 11:24 AM
 * Purpose: Create successive sum array
 */

//System Libraries
#include <iostream> // I/O Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays

// Function Prototypes
int *getData(int &);          //Return the array size and the array from the inputs
int *sumAry(const int *,int); //Return the array with successive sums
void prntAry(const int *,int);//Print the array

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int *array, //holds user inputed array
        arySize; //holds array size
    //Fill Array
    array=getData(arySize);
    //Fill Successive Sum Array from User Input
    int *smAry=sumAry(array,arySize);
    //Print Both Arrays
    prntAry(array,arySize);
    cout<<endl;
    prntAry(smAry,arySize);
    //Exit the Program -- Clean Up
    delete [] array;
    delete [] smAry;
    return 0;
}

//getData Function
int *getData(int& n) {
    cin>>n;
    //Allocate Memory for user inputed array
    int *ary=new int[n];
    //Fill Array
    for(unsigned char i=0;i<n;i++) {
        cin>>*(ary+i); }
    //Exit Function
    return ary;
}

//sumAry Function
int *sumAry(const int *ary,int n) {
    //Allocate Memory
    int *sum=new int[n];
    //Fill Array by Successive Sum 
    *sum=*ary; //sum[0]=ary[0]
    for(unsigned char i=1;i<n;i++) {
        *(sum+i)=*(sum+(i-1))+*(ary+i); }
    //Exit Function
    return sum;
}

//prntAry Function
void prntAry(const int *ary,int n) {
    for(unsigned char i=0;i<n;i++) {
        cout<<*(ary+i);
        if(i!=(n-1)) cout<<" "; }
}
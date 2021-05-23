/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 27, 2021, 5:49 PM
 * Purpose: Find Median using Dynamic Memory Allocation
 */

//System Libraries
#include <iostream> // I/O Library
#include <iomanip>  //Format  Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays

// Function Prototypes
int *getData(int&); //Return the array size and the array
void prntDat(const int*,int); //Print the integer array
float *median(int*,int); //Fill the median array with float array size, the median, and the integer array data
void prntMed(const float*,int); //Print Median array
void mrkSort(int *,int); //Sort function
void minPos(int*,int,int); //Get minimum position to sort
void swap(int*,int*); //Swap when sorting
int *copy(const int *,int); //Copy functions

// Execution Begins Here
int main(int argc, char** argv) {
    // Declare Variables
    int *ary,
        arySize;
    
    //Fill array
    ary=getData(arySize);
    prntDat(ary,arySize);
    cout<<endl;
    
    //Get median
    float *mdnAry=median(ary,arySize);
    prntMed(mdnAry,arySize+2);

    // Exit the program - Cleanup
    delete [] ary;
    delete [] mdnAry;
    return 0;
}

//getData Function
int *getData(int& n) {
    cin>>n;
    //Allocate memory
    int *array=new int[n];

    //Fill in array
    for(unsigned char i=0;i<n;i++){
        cin>>*(array+i); }
   
    //Exit Function
    return array;
}

//sort Function
void mrkSort(int *ary,int n) {
    for(unsigned char i=0;i<n-1;i++){
        minPos(ary,n,i); }
}

//minPos Function
void minPos(int *ary,int n,int pos){
    for(unsigned char i=pos+1;i<n;i++){
        if(ary[pos]>ary[i]) swap(ary+pos,ary+i); }
}

//swap Function
void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

//prntDat Function
void prntDat(const int *ary,int n) {
    for(unsigned char i=0;i<n;i++) {
        cout<<*(ary+i);
        if(i!=(n-1)) cout<<" "; }
}

//copy Function
int *copy(const int *a,int n){
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(unsigned char i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

//median Function
float *median(int *ary,int sz) {
    float mdn;
    unsigned int medPos;
    //Allocate memory for srtAry to copy ary for sorting
    int *srtAry=copy(ary,sz);
    //sort array
    mrkSort(srtAry,sz);
    //calculate median
    if(sz%2) mdn=srtAry[sz/2]; 
    else mdn=(srtAry[sz/2]+srtAry[(sz/2)-1])/static_cast<float>(2);
    
    //Allocate Memory for median array
    float *mdnAry=new float[sz+2];
    //Fill in median Array
    mdnAry[0]=sz+2;
    mdnAry[1]=mdn;
    medPos=2;
    for(unsigned char i=0;i<sz;i++) {
        mdnAry[medPos]=ary[i];
        medPos++; }
    
    //Exit program - cleanup
    delete [] srtAry;
    return mdnAry;
}

//prntMed Function
void prntMed(const float *ary,int n) {
    cout<<*(ary)<<" "<<setprecision(2)<<fixed<<showpoint;
    for(unsigned char i=1;i<n;i++) {
        cout<<*(ary+i);
        if(i!=(n-1)) cout<<" "; }
}
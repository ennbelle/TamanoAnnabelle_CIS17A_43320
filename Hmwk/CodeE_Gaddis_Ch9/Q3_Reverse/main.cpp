/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 27, 2021, 7:41 PM
 * Purpose: This program uses dynamic memory allocation to read and reverse array
 */

//System Libraries
#include <iostream> // I/O Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays

// Function Prototypes
int *getData(int &);    //Fill the Array
int *sort(const int*,int); //Sort smallest to largest
int *reverse(const int*,int);   //Sort in reverse order
void prntDat(const int*,int);   //Print the array
void minPos(int*,int,int);  //Find min position to sort
void swap(int*,int*);   //Swap two values in dynamically allocated array
int *copy(const int *,int);

// Execution Begins Here
int main(int argc, char** argv) {
    // Initialize the Random Number Seed

    // Declare Variables
    int arySize=0,//The array/set size
        *ary;//Pointer to the array
    
    //Fill in array
    ary=getData(arySize);
    
    //sort array
    int *srtAry=sort(ary,arySize);
    prntDat(srtAry,arySize);
    cout<<endl;
    
    //reverse array
    int *rvrsAry=reverse(srtAry,arySize);
    prntDat(rvrsAry,arySize);
    
    // Exit the program - Cleanup
    delete [] ary;
    delete [] srtAry;
    delete [] rvrsAry;
    return 0;
}

//getData Function
int *getData(int& n) {
    cin>>n;
    //Allocate memory
    int *array=new int[n];

    //Fill in array
    for(int i=0;i<n;i++){
        cin>>*(array+i); }
   
    //Exit Function
    return array;
}

//sort Function
int *sort(const int *ary,int n) {
    int *srtAry=copy(ary,n);
    for(int i=0;i<n-1;i++){
        minPos(srtAry,n,i); }
    
    return srtAry;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

//minPos Function
void minPos(int *ary,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(ary+pos)>*(ary+i))
            swap(ary+pos,ary+i); }
}

//swap Function
void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

//reverse Function
int *reverse(const int *ary,int n) {
    unsigned char rvrsPos=0;
    int *rvrsAry=new int[n];
    
    for(char i=(n-1);i>=0;i--) {
        *(rvrsAry+rvrsPos)=*(ary+i);
        rvrsPos++;
    }
    
    //Exit function
    return rvrsAry;
}

//prntDat Function
void prntDat(const int *ary,int n) {
    for(int i=0;i<n;i++) {
        cout<<*(ary+i);
        if(i!=(n-1)) cout<<" "; }
}
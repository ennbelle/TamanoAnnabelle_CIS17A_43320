/*
* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 2, 2021, 3:26 PM
 * Purpose: Array/File Functions - This program demonstrates reading and writing
 *          to binary files.
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
void aryfl(fstream&,int*,short&); //array to file function
void flary(fstream&,int*,short); //file to array function
int* getArr(short&);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string fln;         //File Name
    fstream binFile;    //binary file
    int *ary;           //pointer of int array
    int *nary;          //new array from writing array
    short n=0;          //number of integers in array
    
    //Input data needed
    cout<<"Enter file name to work with: ";
    cin>>fln;
    
    //Open File Name
    binFile.open(fln,ios::out|ios::binary);
    
    cout<<"1. Writing Array to File\n";
    aryfl(binFile,ary,n);
    binFile.close();
    
    binFile.open(fln,ios::in|ios::binary);    
    cout<<"2.Reading Array from File\n";
    flary(binFile,nary,n);
    
    //Clean Up & Exit Program
    binFile.close();
    return 0;
}

//******************************************************************************
//                      Array to File Function
//******************************************************************************
void aryfl(fstream& out,int* arr,short& n) {
    //Initialize array and write into file
    arr=getArr(n);
    out.write(reinterpret_cast<char *>(&arr),sizeof(arr));
    
    //Clean Up and Exit Function
    delete []arr;
}

//******************************************************************************
//                      File to Array Function
//******************************************************************************
void flary(fstream& in,int* arr, short n) {
    arr=new int[n];
    
    in.read(reinterpret_cast<char *>(&arr),n*sizeof(int));
    
    for(int i=0;i<n;i++) {
        cout<<*(arr+i)<<" "; }
    
    //Clean Up and Exit Function
    delete []arr;
}

//******************************************************************************
//                         Get Array Data Function
//******************************************************************************
int* getArr(short& n) {
    //Get size of array
    cout<<"Enter size of integer array: ";
    cin>>n;
    
    //Get Integers
    int* arr=new int[n];
    for(int i=0;i<n;i++) {
        cout<<"Input integer: ";
        cin>>arr[i]; }
    
    return arr;
}


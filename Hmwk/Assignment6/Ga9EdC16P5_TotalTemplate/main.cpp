/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 30, 2021, 9:01 PM
 * Purpose: Driver for Total Template
 */

//System libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
template <class T>
T total(T *ptr,int size) {
    T ttl=0;
    
    for(int i=0;i<size;i++) {
        ttl+=static_cast<T>(ptr[i]); }
    
    return ttl; }

template <class T>
void prnt(T *ptr,int size) {
    for(int i=0;i<size;i++) {
        cout<<ptr[i]<<" "; }
    cout<<endl;
    
}

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    int fsize;
    int isize;
    
    //Process
    cout<<"Enter size of float array: ";
    cin>>fsize;
    cout<<"Enter size of integer array: ";
    cin>>isize;
    float *fptr=new float[fsize];
    int *iptr=new int[isize];
    cout<<"Input float Array: "<<endl;
    for(int f=0;f<fsize;f++) {
        cout<<(f+1)<<".) ";
        cin>>fptr[f]; }
    cout<<endl<<"Input int Array: "<<endl;
    for(int i=0;i<isize;i++) {
        cout<<(i+1)<<".) ";
        cin>>iptr[i]; }
    
    //Output
    cout<<"float Array: \n";
    prnt(fptr,fsize);
    cout<<"float Array Total: "<<total(fptr,fsize)<<endl<<endl;
    cout<<"int Array: \n";
    prnt(iptr,isize);
    cout<<"float Array Total: "<<total(iptr,isize)<<endl;
    
    //Clean Up and Exit
    delete []fptr;
    delete []iptr;
    return 0;
}


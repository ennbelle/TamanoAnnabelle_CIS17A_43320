/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 6th, 2021, 2:20 PM
 * Purpose:  Array Class Specification
 */

#include "array.h"
#include <iostream>
using namespace std;

//Function Implementations
void Array::markSrt(){
    //Find the smallest element in List i
    for(int i=0;i<size-1;i++){
        //Swap as you go to place the smallest element at the top
        for(int j=i+1;j<size;j++){
            //Logic swap
            if(data[i]>data[j]){
                data[i]=data[i]^data[j];
                data[j]=data[i]^data[j];
                data[i]=data[i]^data[j];
            }
        }
    }
}


void Array::prntAry(int perLine){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void Array::filAray(int n){
    //Declare and allocate the array
    n=n<2?2:n;
    data=new int[n];
    size=n;
    for(int i=0;i<n;i++){
        data[i]=rand()%90+10;//2 Digit Random Array
    }
}

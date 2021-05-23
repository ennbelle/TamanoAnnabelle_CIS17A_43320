/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Purpose:  Driver program to test out the statistics problem.
 *           Problem 3 - Midterm
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    
    // Find Mode Size
    int maxF=1; //temporary store for max frequency
    int temp=1; //temporary count
    int nModes=0;
    //Find the max frequency
    for(unsigned char i=1;i<(array->size);i++){
        if(array->data[i]!=array->data[i-1]) {
            if(temp>maxF&&temp>=2) maxF=temp;
                temp=1; }
        else temp++; }
    if(temp>maxF&&temp>=2)maxF=temp;
    //Find the number of modes
    temp=1;    
    for(unsigned char i=1;i<(array->size);i++){
        if(array->data[i]!=array->data[i-1]) {
            if(temp==maxF&&temp>=2) nModes++;
                temp=1; }
        else temp++; }
    if(temp==maxF&&temp>=2) nModes++;
    
    //Fill Modes
    int modePos=0; //mode position
    stats->mode->size=nModes;
    //Fill if size is not zero
    if(nModes!=0) {
        stats->mode->data=new int[nModes];
    temp=1;
    for(unsigned char i=1;i<(array->size);i++){
        if(array->data[i]!=array->data[i-1]) {
            if(temp==maxF) {
                stats->mode->data[modePos]=static_cast<int>(array->data[i-1]);
                modePos++; }
                temp=1; }
        else temp++; }
    if(temp==maxF){ stats->mode->data[modePos]=static_cast<int>(array->data[static_cast<int>(array->size)-1]); }
    }
    
    //Fill modFreq in Stats struct
    stats->modFreq=maxF;
    
    //Find and Fill Median
    int medPos=0;
    stats->median=0;
    medPos=static_cast<int>(array->size)/2;
    if(static_cast<int>(array->size)%2) {
        stats->median=static_cast<int>(array->data[medPos]);
    }
    else {
        stats->median=(static_cast<int>(array->data[medPos]) + static_cast<int>(array->data[medPos-1]))/2.0; }
    
    //Find and Fill Average
    int ttl=0;
    for(unsigned char i=1;i<(array->size);i++) {
        ttl+=static_cast<int>(array->data[i]);}
    stats->avg=static_cast<float>(ttl)/static_cast<int>(array->size);
    return stats;
}
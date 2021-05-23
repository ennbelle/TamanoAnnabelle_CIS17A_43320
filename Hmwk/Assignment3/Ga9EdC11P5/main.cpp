/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 6, 2021, 5:23 PM
 * Purpose: Take the weather statistics program from challenge 4 and implement enumerated data types
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct MoWthr{
    float ttlRn; //total rainfall
    short hTemp; //highest temperature
    short lTemp; //lowest temperature
    float avgTemp; }; //average temperature
    
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int i,sz; //index and size of array (as indicated by user input)
    float avgR; //average rain
    short loTemp; //lowest temperature of year 
    short hiTemp; //highest temperature of year
    short hiInd;  //highest month
    short loInd;  //lowest month
    float avgYrT;   //average temperature throughout year
    float rSum=0;     //rain sum
    float avgTSum=0;  //avg temperature sum
    
    enum Month {JAN,FEB,MAR,APR,MAY,JUN,JULY,AUG,SEPT,OCT,NOV,DEC};
    MoWthr year[12];
    
    //Get Data
    i=JAN;
    cout<<"Enter the total rainfall for the month:"<<endl;
    
    while(cin>>year[i].ttlRn && i<=DEC) {
        if(i!=JAN) cout<<"Enter the total rainfall for the month:"<<endl;
        cout<<"Enter the high temp:"<<endl;
        cin>>year[i].hTemp;
        year[i].hTemp=(year[i].hTemp>140)?140:(year[i].hTemp<-100)?-100:year[i].hTemp;
        cout<<"Enter the low temp:"<<endl;
        cin>>year[i].lTemp; 
        year[i].lTemp=(year[i].lTemp>140)?140:(year[i].lTemp<-100)?-100:year[i].lTemp;
        year[i].avgTemp=(year[i].hTemp+year[i].lTemp)/static_cast<float>(2); 
        i++;
    }
    sz=i;
    
    //find average monthly rainfall
    for(i=JAN;i<=sz;i++) {
        rSum+=year[i].ttlRn; }
    avgR=rSum/sz;
    
    //find highest temp
    hiInd=JAN;
    hiTemp=year[JAN].hTemp;
    for(i=JAN;i<=sz;i++) {
        if(year[i].hTemp>hiTemp) {
            hiInd=i;
            hiTemp=year[i].hTemp; }
    }
    
    //find lowest temp
    loInd=JAN;
    loTemp=year[JAN].lTemp;
    for(i=JAN;i<sz;i++) {
        if(year[i].lTemp<loTemp) {
            loInd=i;
            loTemp=year[i].lTemp; }
    }
    
    //find average temperature
    for(i=JAN;i<sz;i++) {
        avgTSum+=year[i].avgTemp; }
    avgYrT=avgTSum/sz;
    
    //Output Data
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Average monthly rainfall:"<<avgR<<endl;
    cout<<setprecision(0)<<noshowpoint;
    cout<<"High Temp:"<<hiTemp<<endl;
    cout<<"Low Temp:"<<loTemp<<endl;
    cout<<setprecision(1)<<fixed<<showpoint;
    cout<<"Average Temp:"<<avgYrT;
    
    //Exit Program
    return 0;
}
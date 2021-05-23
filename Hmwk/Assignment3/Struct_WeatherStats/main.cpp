/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 5, 2021, 6:59 PM
 * Purpose: Utilizes structure to collect weather statistics and print out average
 *          rainfall, lowest temperature, highest temperature, and average temperature.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct MoWthr{
    string mo; //month
    int ttlRn; //total rainfall
    int lTemp; //lowest temperature
    int hTemp; //highest temperature
    int avgTemp; }; //average temperature
    
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getDat(MoWthr[],const int);
int findH(const MoWthr[],const int);
int findL(const MoWthr[],const int);
float avgRn(const MoWthr[], const int);
int yrAvgT(const MoWthr[], const int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float avgR;
    int loInd;
    int hiInd;
    int avgYrT;
    
    const int MO=12;
    MoWthr year[12];
    
    //Get Data
    getDat(year,MO);
    avgR=avgRn(year,MO);
    loInd=findL(year,MO);
    hiInd=findH(year,MO);
    avgYrT=yrAvgT(year,MO);
    
    //Output Data
    cout<<setprecision(1)<<fixed<<showpoint;
    cout<<"Average Rainfall "<<avgR<<" inches/month"<<endl;
    cout<<setprecision(0)<<noshowpoint;
    cout<<"Lowest Temperature "<<year[loInd].mo<<"  "<<year[loInd].lTemp<<" Degrees Fahrenheit"<<endl;
    cout<<"Highest Temperature "<<year[hiInd].mo<<"  "<<year[hiInd].hTemp<<" Degrees Fahrenheit"<<endl;
    cout<<"Average Temperature for the year "<<avgYrT<<" Degrees Fahrenheit"<<endl;
    
    //Exit Program
    return 0;
}

//getDat Function
void getDat(MoWthr yr[], const int MO) {
    for(short i=0;i<MO;i++) {
        cin>>yr[i].mo;
        cin>>yr[i].ttlRn;
        cin>>yr[i].lTemp;
        cin>>yr[i].hTemp; 
        yr[i].avgTemp=(yr[i].hTemp+yr[i].lTemp)/2; }
}

//findH function
int findH(const MoWthr yr[],const int MO) {
    int highInd=0;
    int highVal=yr[0].hTemp;
    
    for(int i=0;i<MO;i++) {
        if(yr[i].hTemp>highVal) {
            highInd=i;
            highVal=yr[i].hTemp; }
    }
    
    return highInd;
}

//findL function
int findL(const MoWthr yr[],const int MO) {
    int lowInd=0;
    int lowVal=yr[0].lTemp;
    
    for(int i=0;i<MO;i++) {
        if(yr[i].lTemp<lowVal) {
            lowInd=i;
            lowVal=yr[i].lTemp; }
    }
    
    return lowInd;
}

//avgRn Function
float avgRn(const MoWthr yr[], const int MO) {
    int sum=0;
    float avg=0.0f;
    
    for(int i=0;i<MO;i++) {
        sum+=yr[i].ttlRn;
    }
    
    avg=static_cast<float>(sum)/MO;
    return avg;
}

//yrAvgTemp Function
int yrAvgT(const MoWthr yr[], const int MO) {
    int sum=0;
    float avgF;
    float tempF;
    int avgI;
    
    for(int i=0;i<MO;i++) {
        sum+=yr[i].avgTemp;
    }
    
    avgF=static_cast<float>(sum)/MO;
    tempF=static_cast<int>(avgF)+0.5;
    
    if(avgF>=tempF) avgI=static_cast<int>(avgF)+1;
    else avgI=static_cast<int>(avgF);
    
    return avgI;
}
/* 
 * File:   MilTime.cpp
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 1:43 PM
 * Purpose: Military Time Class
 */
#include "Time.h"
#include "MilTime.h"

//Default Constructor
MilTime::MilTime():Time() {
    milHr=0;
    milSec=0; }

//Constructor
MilTime::MilTime(int mh,int ms):Time() {
    //Declare Variables used for Constructor
    int h;
    int m;
    
    //Validate Information Taken
    int tmh=mh; //temporary
    if((tmh%100)>59) {
        tmh+=100;
        tmh-=60; }
    mh=(tmh<0)?0:(tmh>2359)?2359:tmh;
    ms=(ms<0)?0:(ms>59)?59:ms;
    
    //Set
    milHr=mh;
    milSec=ms;
    
    //Fill Time Class
    h=mh/100;
    if(h>12) {
        h%=12;
        if(h==0) { h=12; }
    }
    m=mh%100;
    sHour(h);
    sMin(m);
    sSec(ms);
}

//set Time Function
void MilTime::setTime(int mh, int ms) {
    //Declare Variables
    int h;
    int m;
    
    //Validate Information Taken
    int tmh=mh; //temporary
    if((tmh%100)>59) {
        tmh+=100;
        tmh-=60; }
    mh=(tmh<0)?0:(tmh>2359)?2359:tmh;
    ms=(ms<0)?0:(ms>59)?59:ms;
    
    //Set
    milHr=mh;
    milSec=ms;
    
    //Fill Time Class
    h=mh/100;
    if(h>12) {
        h%=12;
        if(h==0) { h=12; }
    }
    m=mh%100;
    sHour(h);
    sMin(m);
    sSec(ms);
}



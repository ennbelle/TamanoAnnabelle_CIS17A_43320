/* 
 * File:   MilTime.cpp
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 1:43 PM (w/ Exceptions)
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
    //Declare Variables
    int h;
    int m;
    
    if(mh>=0&&mh<=2359&&(mh%100)<60) {
        milHr=mh;
        
        if((mh/100)==0) { h=12; }
        else if((mh/100)>12) { h=(mh/100)%12; }
        else { h=mh/100; }
        m=mh%100;
        sHour(h);
        sMin(m); 
    }else {
        throw BadHr(); }
    
    if(ms>=0&&ms<=59) {
        milSec=ms;
        sSec(ms);    
    } else {
        throw BadSec(); }
}

//set Time Function
void MilTime::setTime(int mh, int ms) {
    //Declare Variables
    int h;
    int m;
    
    if(mh>=0&&mh<=2359&&(mh%100)<60) {
        milHr=mh;
        
        if((mh/100)==0) { h=12; }
        else if((mh/100)>12) { h=(mh/100)%12; }
        else { h=mh/100; }
        m=mh%100;
        sHour(h);
        sMin(m); 
    }else {
        throw BadHr(); }
    
    if(ms>=0&&ms<=59) {
        milSec=ms;
        sSec(ms);    
    } else {
        throw BadSec(); }
}

//set military hours
void MilTime::sHr(int mh) {
    //Declare Variables
    int h;
    int m;
    
    if(mh>=0&&mh<=2359&&(mh%100)<60) {
        milHr=mh;
        
        if((mh/100)==0) { h=12; }
        else if((mh/100)>12) { h=(mh/100)%12; }
        else { h=mh/100; }
        m=mh%100;
        sHour(h);
        sMin(m); 
    }else {
        throw BadHr(); }
}

//set military seconds
void MilTime::sSc(int ms) {
    if(ms>=0&&ms<=59) {
        milSec=ms;
        sSec(ms);    
    } else {
        throw BadSec(); }
}

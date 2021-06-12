/* 
 * File:   Essay.cpp
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 3:44 PM
 * Purpose: Essay "is a" Graded Actvity
 */
#include <iostream>
#include "GActvty.h"
using namespace std;

#include "Essay.h"

//Default Constructor
Essay::Essay():GActvty() {
    grmmr=0.0f;
    spllng=0.0f;
    crlen=0.0f;
    cntnt=0.0f; }

//Constructor
Essay::Essay(float g,float s,float cl,float cnt):GActvty() {
    //Validate Inputted Data
    g=(g<0.0)?0.0:(g>30.0)?30.0:g;
    s=(s<0.0)?0.0:(s>20.0)?20.0:s;
    cl=(cl<0.0)?0.0:(cl>20.0)?20.0:cl;
    cnt=(cnt<0.0)?0.0:(cnt>30.0)?30.0:cnt;
    
    //Set to Member Variables
    grmmr=g;
    spllng=s;
    crlen=cl;
    cntnt=cnt;
    sScr(ttlE());
}

float Essay::ttlE() {
    return (grmmr+spllng+crlen+cntnt); }

void Essay::prnt() {
    cout<<"Essay Score Breakdown"<<endl;
    cout<<"Grammar (30 pts)........."<<grmmr<<endl;
    cout<<"Spelling (20 pts)........"<<spllng<<endl;
    cout<<"Correct Length (20 pts).."<<crlen<<endl;
    cout<<"Content (30 pts)........."<<cntnt<<endl;
    cout<<"Total (100 pts).........."<<ttlE()<<endl;
}



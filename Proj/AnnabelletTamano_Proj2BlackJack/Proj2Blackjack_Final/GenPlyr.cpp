/* 
 * File:   GenPlyr.cpp
 * Author: Annabelle Tamano
 * Created on June 8, 2021, 8:19 AM
 * Purpose: GenPlyr Class 
 */

//System Libraries
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "NumGen.h"
#include "Player.h"


#include "GenPlyr.h"

//******************************************************************************
//Static Variables
//******************************************************************************
char GenPlyr::randNam[35][40] {"Abby","Alana","Amaya","Austin","Azher",
                            "Barris","Billie","Bibby","Brayden","Brando",
                            "Cami","Caster","Cleo","Connie","Crystal",
                            "Damien","Denny","Droso","Duke","Dyson",
                            "Elle","Emia","Enricho","Enzo","Ephri",
                            "Fantasia","Finn","Fiona","Foma","Fuschia",
                            "Gavin","Gemma","George","Giana","Ginny"};

//******************************************************************************
// Default Constructor
//******************************************************************************
GenPlyr::GenPlyr():Player() {
    bet=0;
    won=0;
}

//******************************************************************************
//generate Player at Random
//******************************************************************************
 void GenPlyr::genPlyr(int rN) {
     NumGen<int> n;
     srand(time(0));
     setName(randNam[rN]); 
     bet=n.genNum(50,2); 
 }
 
 //******************************************************************************
//Print General Player Lobby Information
 //******************************************************************************
 void GenPlyr::prnInfo() {
     for(int i=0;i<strlen(name);i++) {
         cout<<name[i];
     }
     cout<<":   $"<<bet;
 }
 
 //******************************************************************************
 //Set Bet Function
 //******************************************************************************
void GenPlyr::setBet(int b) {
    if(b>=2&&b<=50) {
        bet=b;
    }
    else {
        throw BadBet();
    }
}
/* 
 * File:   Player.cpp
 * Author: Annabelle Tamano
 * Created on June 7, 2021, 4:12 PM
 * Purpose: Player Class
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Card.h"
#include "NumGen.h"
#include "Player.h"

//******************************************************************************
//Default Constructor
// input - n/A
// output - N/A
//******************************************************************************
Player::Player() {
    nCards=0;
    ttlPt=0; 
    hit=true;
    bust=false;}
 
//******************************************************************************
//Add Card Function
// input - char f and char s
// output - none
//******************************************************************************
 void Player::addCard(char f, char s) {
     hand[nCards].setCard(f,s);
     
     ttlPt+=hand[nCards].getPt();
     if(f=='A'&&ttlPt>21) {
         ttlPt-=10;
     }
     
     nCards++;
 }
 
 //******************************************************************************
 //prnPlyr Function - Prints Player
 // input - N/A
 // output - N/A
 //******************************************************************************
 void Player::prnPlyr() {
     for(int i=0;i<strlen(name);i++) {
         cout<<name[i]; 
     }
     
     cout<<":   ";
     for(int i=0;i<nCards;i++) {
         hand[i].prnCard();
         cout<<"   "; 
     }
     
     cout<<"Total: "<<ttlPt;
     if (bust==true) { 
         cout<<"   BUST!"; 
     }
     else if(hit==false&&bust==false) { 
         cout<<"  STAND!"; 
     }
 }
 
 //******************************************************************************
 //Randomize Hit or Stand
 // input - N/A
 // output - bool
 //******************************************************************************
 void Player::randHS() {
     //Random number seed
     srand(time(0));
     NumGen<int> n;
     
     //Randomize
     int r=n.genNum(1,0);
     
     //Assign to true or false
     if(r==0) {
         hit=true;
     } 
     else{
         hit=false;
     }
 }
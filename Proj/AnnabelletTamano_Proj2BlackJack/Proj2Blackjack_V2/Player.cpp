/* 
 * File:   Player.cpp
 * Author: Annabelle Tamano
 * Created on June 7, 2021, 4:12 PM
 * Purpose: Player Class
 */
#include <iostream>
using namespace std;

#include "Card.h"

#include "Player.h"

//Default Constructor
Player::Player() {
    nCards=0;
    ttlPt=0; 
    hit=true; }
 
//Add Card Function
 void Player::addCard(char f, char s) {
     hand[nCards].setCard(f,s);
     ttlPt+=hand[nCards].getPt();
     nCards++;
 }
 
 //prnPlyr Function - Prints Player
 void Player::prnPlyr() {
     for(int i=0;i<strlen(name);i++) {
         cout<<name[i]; }
     cout<<":   ";
     for(int i=0;i<nCards;i++) {
         hand[i].prnCard();
         cout<<"   "; }
     cout<<"Total: "<<ttlPt;
     if (ttlPt>21&&hit==false) { cout<<"   BUST!"; }
 }
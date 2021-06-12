/* 
 * File:   Dealer.cpp
 * Author: Annabelle Tamano 
 * Created on June 8, 2021, 8:07 AM
 * Purpose: Dealer Class
 */
#include <iostream>
#include "Player.h"
using namespace std;
#include "Dealer.h"

//Default Constructor
Dealer::Dealer():Player() {
    move=false;
    setName("Dealer");
}

//Print Incomplete Hand for when Move is False
void Dealer::prnPart() {
    cout<<getName()<<":   ";
    hand[0].prnCard();
    cout<<"   [ HIDDEN ]";
}
/* 
 * File:   Dealer.h
 * Author: Annabelle Tamano
 * Created on June 8, 2021, 8:07 AM
 * Purpose: Dealer Class Header
 */

#ifndef DEALER_H
#define DEALER_H
#include "Player.h"
using namespace std;

class Dealer:public Player {
private:
    bool move; //false=all general players still drawing cards; true=dealer's move
public:
    //Default Constructor
    Dealer();
    //Accessor Functions
    bool getMove() { return move; }
};

#endif /* DEALER_H */


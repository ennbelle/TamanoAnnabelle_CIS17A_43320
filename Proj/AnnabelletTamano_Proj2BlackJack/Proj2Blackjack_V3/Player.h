/* 
 * File:   Player.h
 * Author: Annabelle Tamano
 * Created on June 7, 2021, 4:12 PM
 * Purpose: Card Class Header
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <cstring>
using namespace std;

class Player {
protected:
    char *name=new char[40];      //Player Name
    Card *hand=new Card[12];    //Player Hand
    int nCards;                 //Number of Cards in hand
    int ttlPt;                  //Total Points
    bool hit;                   // true = hit, false = stand or bust
public:
    //Default Constructor
    Player();
    //Accessor Methods
    char *getName() { return name; }
    int getTP() { return ttlPt; }
    bool getHS() { return hit; }
    //Mutator Methods
    void setName(char* n) { 
        strlcpy(name,n,40); }
    void addCard(char f, char n);
    void setHS(bool opt) { hit=opt; }
    //Other Functions
    void prnPlyr();
    ~Player() {
        delete []name;
        delete []hand;
    }
};

#endif /* PLAYER_H */


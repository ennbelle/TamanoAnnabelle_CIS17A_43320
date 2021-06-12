/* 
 * File:   Player.h
 * Author: Annabelle Tamano
 * Created on June 7, 2021, 4:12 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
using namespace std;

class Player {
private:
    string name;      //Player Name
    Card *hand=new Card[12];    //Player Hand
    int ttlPt;                  //Total Points
    bool hit;                   // true = hit, false = stand or bust
    static string randNam[7];
public:
    //Default Constructor
    Player();
    //Accessor Methods
    string getName() { return name; }
    int getTP() { return ttlPt; }
    bool getHS() { return hit; }
    //Mutator Methods
    void addCard(char f, char n);
    void setHS(bool opt) { hit=opt; }
    ~Player() {
        delete []hand;
    }
};

#endif /* PLAYER_H */


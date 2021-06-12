/* 
 * File:   Player.h
 * Author: Annabelle Tamano
 * Created on June 7, 2021, 4:12 PM
 * Purpose: Card Class Header
 */

#ifndef PLAYER_H
#define PLAYER_H

//System Libraries
#include <cstring>
using namespace std;

//User Libraries
#include "Card.h"

class Player {
protected:
    char *name=new char[40];      //Player Name
    Card *hand=new Card[12];    //Player Hand
    int nCards;                 //Number of Cards in hand
    int ttlPt;                  //Total Points
    bool hit;                   // true = hit, false = stand or bust
    bool bust;                  //Weather Player Busts or Not
public:
    //Default Constructor
    Player();
    
    //Accessor Methods
    char *getName() {
        return name; 
    }    //Gets name
    int getTP() { 
        return ttlPt; 
    }       //Gets total points
    bool getHS() { 
        return hit; 
    }        //Gets Hit or Stand
    bool getBust() { 
        return bust; 
    }
    
    //Mutator Methods
    void setName(char* n) {             //Sets name of Player
        strlcpy(name,n,40); 
    }   
    void addCard(char f, char n);       //Adds a Card to Hand
    void setHS(bool opt) { hit=opt; }   //Set Hit or Stand
    void setBust(bool b) { bust=b; }    //Set bust
    
    //Other Functions
    void prnPlyr(); //Prints Player's hand
    void randHS();  //Randomizes Hit or Stand
    
    //Deconstructor
    ~Player() {
        delete []name;
        delete []hand;
    }
};

#endif /* PLAYER_H */
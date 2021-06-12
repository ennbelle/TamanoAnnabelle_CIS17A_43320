/* 
 * File:   Deck.h
 * Author: Annabelle Tamano
 * Created on June 8, 2021, 11:07 AM
 * Purpose: Deck Class
*/

#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck {
private:
    Card *deck=new Card[52];
    int *index=new int[52];
    static char stdFace[13];
    static char stdSuit[4];
public:
    //Default Constructor
    Deck();
    //Accessor Methods
    char getF(int i) { return deck[index[i]].getFace(); }
    char getS(int i) { return deck[index[i]].getSuit(); }
    //Other Functions
    void shuffle();
    void prnCard(int i) { deck[index[i]].prnCard(); }
    //Clean Up
    ~Deck() {
        delete []deck;
        delete []index;
    }
};

#endif /* DECK_H */


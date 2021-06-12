/* 
 * File:   Card.h
 * Author: Annabelle Tamano
 * Created on June 7, 2021, 4:19 PM
 * Purpose: Card Class Header
 */

#ifndef CARD_H
#define CARD_H

class Card {
private:
    char face;
    char suit;
    int pt;
public:
    //Default Constructor
    Card();
    //Constructor
    Card(char f,char s);
    //Mutator Functions
    void setPt();
    //Accessor Methods
    int getPt();
};

#endif /* CARD_H */


/* 
 * File:   GenPlyr.h
 * Author: Annabelle Tamano
 * Created on June 8, 2021, 8:19 AM
 */

#ifndef GENPLYR_H
#define GENPLYR_H
#include "Player.h"
using namespace std;

class GenPlyr:public Player {
private:
    int bet;                    //Starting bet
    float won;                    //Money won
    static char randNam[35][40];
public:
    GenPlyr();
    GenPlyr(const GenPlyr& orig);
    //Accessor Functions
    int getBet() { return bet; }
    //Mutator Functions
    void setBet(int b) { bet=b; }
    void setWon(float w) { won+=w; }
    void genPlyr(int rN);
};

#endif /* GENPLYR_H */


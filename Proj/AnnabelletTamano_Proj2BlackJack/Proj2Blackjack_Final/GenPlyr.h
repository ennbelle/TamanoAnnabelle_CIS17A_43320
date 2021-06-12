/* 
 * File:   GenPlyr.h
 * Author: Annabelle Tamano
 * Created on June 8, 2021, 8:19 AM
 */

#ifndef GENPLYR_H
#define GENPLYR_H

//User Libraries
#include "Player.h"
using namespace std;

//GenPlyr Class
class GenPlyr:public Player {
private:
    int bet;                    //Starting bet
    float won;                    //Money won
    static char randNam[35][40]; //random 
public:
    //Exception Catch
    class BadBet { };
    
    //Constructor
    GenPlyr();
    
    //Accessor Functions
    int getBet() { return bet; }
    int getBust() { return bust; }
    float getWon() { return won; }
    
    //Mutator Functions
    void setWon(float w) { won+=w; }    //set value won
    void genPlyr(int rN);   //generate random player
    void prnInfo();         //set prninfo
    void setBet(int b);     //set bet
};

#endif /* GENPLYR_H */


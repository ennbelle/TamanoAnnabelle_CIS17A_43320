/* 
 * File:   Deck.cpp
 * Author: Annabelle Tamano
 * Created on June 8, 2021, 11:07 AM
 * Purpose: Deck Class
 */
#include <ctime>
#include <cstdlib>
#include "Card.h"
using namespace std;
#include "Deck.h"

//Static Variables
char Deck::stdFace[13] {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char Deck::stdSuit[4] {'C','H','D','S'};

//******************************************************************************
//Constructor
//******************************************************************************
Deck::Deck() {
    //Declare Variable
    int ind=0;
    
    //Fill Deck
    for(int c=0;c<13;c++) {
        for(int s=0;s<4;s++) {
            deck[ind].setCard(stdFace[c],stdSuit[s]);
            ind++; }
    }
    
    //Fill Index Array
    for(int i=0;i<52;i++) {
        index[i]=i; }
}

//******************************************************************************
//shuffle Function
//******************************************************************************
void Deck::shuffle() {
    //Declare Local Variables
    srand(time(0));
    int r=0;
    int temp=0;
    for(int i=0;i<52;i++) {
        r=i+(rand()%(52-i));
        temp=static_cast<int>(index[i]);
        index[i]=static_cast<int>(index[r]);
        index[r]=temp;
    }
}


/* 
 * File:   Card.cpp
 * Author: Annabelle Tamano
 * Created on June 7, 2021, 4:19 PM
 * Purpose: Card Class
 */

#include "Card.h"

Card::Card() {
    face=0;
    suit=0;
    pt=0; }

Card::Card(char f,char s) {
    face=f;
    suit=s; 
    setPt(); }

void Card::setPt(int t) {
    pt=(face=='A')?11:
        (face=='2')?2:
        (face=='3')?3:
        (face=='4')?4:
        (face=='5')?5:
        (face=='6')?6:
        (face=='7')?7:
        (face=='8')?8:
        (face=='9')?9:
        10;
    
    if(t+pt>21&&face=='A') {
        pt=1; }
}
/* 
 * File:   Card.h
 * Author: Annabelle Tamano
 * Created on May 1, 2021, 4:41 PM
 */

#ifndef CARD_H
#define CARD_H

struct Card {
    char cardN; //Card Name - K, Q, J, T(representing 10), 9, 8, 7, 6, 5, 4, 3, 2, 1, or A
    char suit;  //Card Suit - Clubs(C), Hearts (H), Diamond(D), or Spades(S)
};

#endif /* CARD_H */


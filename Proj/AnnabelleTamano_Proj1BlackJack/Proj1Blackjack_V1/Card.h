/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.h
 * Author: annat
 *
 * Created on May 11, 2021, 1:08 AM
 */

#ifndef CARD_H
#define CARD_H

struct Card {
    char cardF; //Card Face - K, Q, J, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, or A
    char suit;  //Card Suit - Clubs(C), Hearts (H), Diamond(D), or Spades(S)
    char colr;  //Card Color - Red (R) or Black (B)
    short ptVal;
    
};


#endif /* CARD_H */


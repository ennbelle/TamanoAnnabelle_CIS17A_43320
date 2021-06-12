/* 
 * File:   Player.cpp
 * Author: Annabelle Tamano
 * Created on June 7, 2021, 4:12 PM
 * Purpose: Player Class
 */

using namespace std;
#include "Player.h"

//Static Variables
string Player::randNam[7]={"Austin Holmes","Alana Jacobs","Peter Wiley","Hark Dunes".
                           "Hamish Duke","Lilibeth Diana","Ioana Hunt"};

//Default Constructor
Player::Player() {
    name="";
    ttlPt=0; 
    hit=true; }
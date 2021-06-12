/* 
 * File:   GActvty.cpp
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 3:30 PM
 * Purpose: Graded Activity Class
 */

#include "GActvty.h"

//Default Constructor
GActvty::GActvty() {
    lttr=' ';
    scr=0.0f; }

//Constructor
GActvty::GActvty(float s) {
    scr=s;
    detGrd(); }

//Determine Grade Function
void GActvty::detGrd() {
    lttr=(scr>=90.0)?'A':
         (scr<90.0&&scr>=80.0)?'B':
         (scr<80.0&&scr>=70.0)?'C':
         (scr<70.0&&scr>=60.0)?'D':
         'F';
}


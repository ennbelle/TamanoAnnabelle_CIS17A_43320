/* 
 * File:   Essay.h
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 3:44 PM
 * Purpose: Essay "is a" Graded Actvity
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "GActvty.h"

class Essay:public GActvty {
private:
    float grmmr;
    float spllng;
    float crlen;
    float cntnt;
    float ttlE(); //total points earned
public:
    //Default Constructor
    Essay();
    //Constructor
    Essay(float g,float s,float cl,float cnt);
    //print 
    void prnt();

};

#endif /* ESSAY_H */


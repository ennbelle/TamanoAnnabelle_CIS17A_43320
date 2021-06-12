/* 
 * File:   GActvty.h
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 3:30 PM
 * Purpose: Graded Activity Class Header File
 */

#ifndef GACTVTY_H
#define GACTVTY_H

class GActvty {
protected:
    char lttr;      //hold letter score
    float scr;      //hold numeric score
    void detGrd();  //determine letter grade
public:
    //Default Constructor
    GActvty();
    //Constructor
    GActvty(float s);
    //Accessor Functions
    char gLttr() { return lttr; }
    float gScr() { return scr; }
    //Mutator Functions
    void sScr(float s) { scr=s; detGrd(); }
};

#endif /* GACTVTY_H */


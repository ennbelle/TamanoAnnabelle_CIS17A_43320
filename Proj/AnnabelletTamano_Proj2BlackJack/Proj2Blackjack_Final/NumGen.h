/* 
 * File:   NumGen.h
 * Author: Annabelle Tamano
 * Created on June 11, 2021, 10:01 PM
 * Generates Numbers
 */

#ifndef NUMGEN_H
#define NUMGEN_H

//System Libraries
#include <ctime>
#include <cstdlib>
using  namespace std;

//******************************************************************************
// Class Template for Number Generator
//******************************************************************************
template <class T>
class NumGen {
private:
    
public:
    T genNum(T vMax,T vMin);
};

//******************************************************************************
// Class that generates random number for program use
//******************************************************************************
template <class T>
T NumGen<T>::genNum(T vMax,T vMin) {
    srand(time(0));
    
    return rand()%(vMax-vMin +1)-vMin;
}

#endif /* NUMGEN_H */


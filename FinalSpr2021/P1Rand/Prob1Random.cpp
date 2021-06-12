/* 
 * File:   Prob1Random.cpp
 * Author: Annabelle Tamano
 * Created on June 8, 2021, 2:41 AM
 * Purpose: Problem 1 Random Sequence .CPP
 */

#include <ctime>
#include <cstdlib>
#include "Prob1Random.h"

//Constructor
Prob1Random::Prob1Random(const char n,const char* seq) {
    nset=n;
    set=new char[nset];
    freq=new int[nset];
    numRand=0;
    for(int i=0;i<nset;i++) {
        set[i]=seq[i]; }
}

char Prob1Random::randFromSet() {
    int i=0;
    i=rand()%(nset);
    freq[i]+=1;
    numRand++;
    return set[i];
}

//Access frequency histogram
int* Prob1Random::getFreq() const {
    return freq;
}

//Access set used
char* Prob1Random::getSet() const {
    return set;
}

int Prob1Random::getNumRand() const {
    return numRand;
}

Prob1Random::~Prob1Random() {
    delete []set;
    delete []freq;
}


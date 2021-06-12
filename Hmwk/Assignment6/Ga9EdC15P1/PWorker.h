/* 
 * File:   PWorker.h
 * Author: Annabelle Tamano
 * Created on May 26, 2021, 11:33 AM
 * Purpose: Production Worker Class Header File
 */

#ifndef PWORKER_H
#define PWORKER_H
#include "Emp.h"
using namespace std;

class PWorker:public Emp {
protected:
    int shft;       //Shift (1=Day,2=Night)
    float pRate;    //Pay Rate
public:
    //Default Constructor
    PWorker():Emp() {
        shft=0; pRate=0.0f; }
    //Programmer-Defined Constructor
    PWorker(char* n,int en,char* hd,int s,float p):Emp(n,en,hd) {
        shft=s; pRate=p; }
    //Accessor Methods
    int gShft() const { return shft; }
    float gPRate() const { return pRate; }
    //Mutator Methods
    void sShft(int s) { shft=s; }
    void sPRate(float p) { pRate=p; }
};

#endif /* PWORKER_H */


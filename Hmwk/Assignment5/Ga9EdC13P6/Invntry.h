/* 
 * File:   Invntry.h
 * Author: Annabelle Tamano
 * Created on May 21, 2021, 2:51 PM
 */

#ifndef INVNTRY_H
#define INVNTRY_H

class Invntry {
private:
    int inum; //item number
    int qtty; //item quantity
    float cost; //per-unit cost
    float ttlCost; //total cost
public:
    Invntry();
    Invntry(int i,int q,int c);
    //Mutator Function
    void setIN(int i) { inum=i; }
    void setQ(int q) { 
        qtty=q;
        setTC(); }
    void setC(float c) {
        cost=c;
        setTC(); }
    void setTC() { ttlCost=qtty*cost; }
    //Accessor Functions
    int getIN() { return inum; }
    int getQ() { return qtty; }
    float getC() { return cost; }
    float getTC() { return ttlCost; }

};

#endif /* INVNTRY_H */


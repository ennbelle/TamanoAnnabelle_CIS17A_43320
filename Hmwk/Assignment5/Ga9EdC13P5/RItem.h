/* 
 * File:   RItem.h
 * Author: Annabelle Tamano
 * Created on May 21, 2021, 2:00 PM
 */

#ifndef RITEM_H
#define RITEM_H
#include <cstring>

class RItem {
private:
    char* descrp;
    int unts;
    float price;

public:
    RItem();
    RItem(char* d, int u, float p);
    //Mutator Methods
    void setD(char* d) { strcpy(descrp,d); }
    void setU(int u) { unts = u; }
    void setP(float p) { price = p; }
    //Accessor Methods
    char* getD() { return descrp; }
    int getU() { return unts; }
    float getP() { return price; }
    //Delete
    ~RItem() { delete []descrp; }
};

#endif /* RITEM_H */


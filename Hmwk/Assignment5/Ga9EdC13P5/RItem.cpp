/* 
 * File:   RItem.cpp
 * Author: Annabelle Tamano
 * Created on May 21, 2021, 2:00 PM
 */

//System library
using namespace std;

//User Library
#include "RItem.h"

//Default Constructor
RItem::RItem() {
    descrp=new char[80];
    unts=0;
    price=0.0f; }

//Programmer-Defined Constructor
RItem::RItem(char* d,int u,float p) {
    descrp=new char[strlen(d)+1];
    strcpy(descrp,d);
    unts=u;
    price=p; }



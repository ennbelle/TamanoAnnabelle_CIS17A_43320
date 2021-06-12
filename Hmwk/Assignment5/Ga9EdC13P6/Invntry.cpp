/* 
 * File:   Invntry.cpp
 * Author: annat
 * 
 * Created on May 23, 2021, 2:51 PM
 */

#include "Invntry.h"

//Default Constructor
Invntry::Invntry() {
    inum=0;
    qtty=0;
    cost=0.0f;
    ttlCost=0.0f; }

//
Invntry::Invntry(int i,int q,int c) { 
    inum=i;
    qtty=q;
    cost=c;
    setTC(); }


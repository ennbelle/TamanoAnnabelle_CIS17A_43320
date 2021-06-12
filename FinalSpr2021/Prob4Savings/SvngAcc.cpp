/* 
 * File:   SvngAcc.cpp
 * Author: Annabelle Tamano
 * Created on June 11, 2021, 3:38 AM
 * Purpose: Savings Accounts .CPP File
 */

#include <iostream>
#include <cmath>
using namespace std;

#include "SvngAcc.h"

//Constructor
SvngAcc::SvngAcc(float b) {
    if(b>0) { Balance=b; }
    else { Balance=0; }
    FreqWithDraw=0;
    FreqDeposit=0;
}

void SvngAcc::Transaction(float m) {
    if(m>0) {
        Deposit(m);
    }else {
        Withdraw(m);
    }
}

float SvngAcc::Total(float s, int t) {
    float ttl=0;
    for(int i=1;i<=t;i++) {
        ttl=Balance*pow(1.0+s,i); }
    
    return ttl;
}

float SvngAcc::TotalRecursive(float s, int t) {
    float ttl=0;
    return ttl;
}

float SvngAcc::Withdraw(float m) {
    if(-m<Balance&&m<0) {
        Balance+=m;
        FreqWithDraw++;
    } else {
        cout<<"Withdraw not Allowed"<<endl; }
    
    return Balance;
}

float SvngAcc::Deposit(float m) {
    Balance+=m;
    FreqDeposit++;
    
    return Balance;
}

void SvngAcc::toString() {
    cout<<"Balance=$"<<Balance<<endl
            <<"WithDraws="<<FreqWithDraw<<endl
            <<"Deposits="<<FreqDeposit<<endl;
}

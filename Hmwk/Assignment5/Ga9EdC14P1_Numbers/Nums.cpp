/* 
 * File:   Nums.cpp
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 5:58 PM
 * Purpose: Stores Nums information
 */
#include <iostream>
using namespace std;

#include "Nums.h"

//Static variables
string Nums::ones[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
string Nums::teens[10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string Nums::tens[10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
string Nums::hndrd="hundred";
string Nums::thsnd="thousand";

//Default constructor
Nums::Nums() {
    num=0;
}

//Programmer defined constructor
Nums::Nums(int n) {
    num=n; }

//print function
void Nums::print() {
    int tn=num;
    int i=0;
    
    if(tn==0) {
        cout<<ones[tn]; }
    
    while(tn>0) {
        if (tn<10) {
            cout<<ones[tn];
            tn/=10;
        } else if (tn<20) {
            cout<<teens[tn-10];
            tn/=20;
        } else if (tn<100) {
            cout<<tens[tn/10];
            tn%=10;
        } else if (tn<1000) {
            cout<<ones[tn/100]<<" "<<hndrd;
            tn%=100;
            
        } else if(tn<10000) {
            cout<<ones[tn/1000]<<" "<<thsnd;
            tn%=1000;
        }else { tn=0; }
        
        if(tn!=0) cout<<" ";
    }
    
}


/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 29, 2021, 6:33 PM
 * Purpose:     Midterm Problem 7
 */

#include <iostream>
#include <cmath>
using namespace std;

//User Libraries
struct Prime {
    unsigned short prime;
    unsigned char power;
};
struct Primes {
    unsigned char nPrimes;
    Prime *prime;
};

//Function Prototypes
Primes *factor(int); //Input an integer, return all prime factors
void prntPrm(const Primes *); //Output all prime factors

//Execution Begins Here
int main(int argc, char** argv) {
    int num=0;
    cout<<"This program factors all the primes within a number[2-10000]. "<<endl;
    cout<<"Enter any number between 2 and 10000: ";
    cin>>num;
    //Validate number and Find Primes
    if(num<2||num>10000) cout<<"Cannot calculate primes! Your number is out of range. Goodbye."<<endl<<endl;
    else {
        Primes *fct=factor(num);
        
        cout<<num;
        prntPrm(fct);
        
        //Clean Up
        delete []fct->prime;
        delete fct;
    }
    
    //Exit Program
    return 0;
}

Primes *factor(int n) {
    //Declare Variables
    Primes *fctr=new Primes[100];
    Prime *fctr=new Prime[100];
    fctr->nPrimes=0;
    int pind=0; //prime index
    
    //Factor 2s if present
    if(n%2==0) { 
        fctr->prime[pind]->prime=2;
        fctr->prime[pind]->power=1;
        n/=2;
        while (n%2==0) {
            fctr->prime[pind]->power=static_cast<unsigned char>(fctr->prime[pind]->power)+1;
            n/=2;
        }
        pind++;
    }
    
    //Find primes from values 3 PLUS
    for(int i=3;i<=sqrt(n);i=i+2) {
        if(n%i==0) {
            fctr->prime[pind]->prime=i;
            fctr->prime[pind]->power=1;           
        }
        while(n%i==0) {
            fctr->prime[pind]->power=static_cast<unsigned char>(fctr->prime[pind]->power)+1;
            n/=i;
        }
        pind++;
    }
    
    if(n>2) {
        fctr->prime[pind]->prime=n;
        fctr->prime[pind]->power=1;
    }
    
    fctr->nPrimes=pind+1;
    
    //Exit Function
    return fctr;
}

void prntPrm(const Primes *fct) {
    cout<<" = ";
    for(unsigned char i=0;i<fct->nPrimes;i++) {
        cout<<fct->prime[i]->prime<<"^"<<static_cast<int>(fct->prime[i]->power);
        if(i<(static_cast<unsigned short>(fct->nPrimes) - 1)) { cout<<" * ";}
    }
}
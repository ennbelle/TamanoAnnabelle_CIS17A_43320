/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 1, 2021, 8:12 PM
 * Purpose: Corporate Sales Data Output
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries
#include "Div.h"

//Global Constants

//Function Prototypes
Div *getDat();
void wrtDat(const Div *);
void wrtBin(Div *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    Div* co=getDat();
    
    //Write into Binary File
    wrtDat(co);
    wrtBin(co);
    
    //Clean Up & Exit Program
    delete []co;
    return 0;
}

Div *getDat() {
    //Declare and Initialize
    Div *co=new Div[4];
    
    for(int i=0;i<4;i++) {
        //Name Division
        switch(i) {
            case 0: co[i].divName="East"; break;
            case 1: co[i].divName="West"; break;
            case 2: co[i].divName="North"; break;
            default: co[i].divName="South";
        }
        //Quarter
        for(int q=0;q<4;q++) {
            co[i].qrtr[q]=(q+1); }
        //Quarterly Sales
        cout<<co[i].divName<<" Division\n";
        for(int s=0;s<4;s++) {
            cout<<"Quarter #"<<co[i].qrtr[s]<<" Sales: $";
            cin>>co[i].qrtrSl[s];
            //Turn to Positive if Negative Value is Entered
            if(co[i].qrtrSl[s]<0) { co[i].qrtrSl[s]*=-1; }
        }
    }
    
    return co;
}

void wrtDat(const Div* co) {
    fstream out;
    out.open("coDat.txt",ios::out);
    for(int i=0;i<4;i++) {
        out<<"Division: "<<co[i].divName<<endl;
        for(int j=0;j<4;j++) {
            out<<"Quarter #"<<co[i].qrtr[j]<<" Sales: $"<<co[i].qrtrSl[j]<<endl;
        }
        out<<endl;
    }
    
    out.close();
}

void wrtBin(Div* co) {
    fstream out;
    out.open("coDat.bin",ios::out|ios::binary);
    for(int i=0;i<4;i++) {
        out.write(reinterpret_cast<char *>(&co[i].divName),sizeof(string));
        out.write(reinterpret_cast<char *>(co[i].qrtr),sizeof(int));
        out.write(reinterpret_cast<char *>(co[i].qrtrSl),sizeof(int));
    }
    
    out.close();
}
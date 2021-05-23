/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 2, 2021, 7:12 PM
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
void wrtDat(const Div *,int,int*,int,int);
int ttlyrCo(const Div *);   //Calculate total yearly corporate sales
int *ttlqtCo(const Div *);
int sHi(const int*);
int sLo(const int*);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables Variables
    int ttlyr;
    Div* co=getDat();
    int hi;
    int lo;
    //Get Yearly Corporate Sale
    ttlyr=ttlyrCo(co);
    //Get Quarterly Corporate Sales
    int *qtCo=ttlqtCo(co);
    //Get Highest and Lowest Quarters
    hi=sHi(qtCo);
    lo=sLo(qtCo);
    //Write into Text File
    wrtDat(co,ttlyr,qtCo,hi,lo);
    
    //Clean Up & Exit Program
    delete []co;
    delete []qtCo;
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
        //Get yearly total for each division
        co[i].yrSlTtl=0;
        for(int t=0;t<4;t++) {
            co[i].yrSlTtl+=co[i].qrtrSl[t]; }
        //Calculate Average
        co[i].avg=co[i].yrSlTtl/4;
    }
    
    return co;
}

void wrtDat(const Div* co,int yrCo,int *qtCo,int hiQ,int loQ) {
    fstream out;
    out.open("coDat.txt",ios::out);
    
    out<<"Corporate Sales Data\n";
    out<<"Total Yearly Corporate Sales: $"<<yrCo<<endl<<endl;
    out<<"Total Corporate Sales for Each Quarter:"<<endl;
    for(int i=0;i<4;i++) {
        out<<"    Quarter #"<<(i+1)<<": $"<<*(qtCo+i)<<endl;
    }
    out<<endl;
    out<<"Highest Quarter for Corporation: Quarter #"<<(hiQ+1)<<" - $"<<qtCo[hiQ]<<endl;
    out<<"Lowest Quarter for Corporation: Quarter #"<<(loQ+1)<<" - $"<<qtCo[loQ]<<endl<<endl;
    for(int i=0;i<4;i++) {
        out<<"Division: "<<co[i].divName<<endl;
        for(int j=0;j<4;j++) {
            out<<"    Quarter #"<<co[i].qrtr[j]<<" Sales: $"<<co[i].qrtrSl[j]<<endl;
        }
        out<<"    Division Yearly Sales: $"<<co[i].yrSlTtl<<endl;
        out<<"    Average Quarterly Sales of Division: $"<<co[i].avg<<endl<<endl;
    }
    
    out.close();
}

int ttlyrCo(const Div* co) {
    int ttl=0;
    for(int i=0;i<4;i++) {
        ttl+=co[i].yrSlTtl; }
    return ttl;
}

int *ttlqtCo(const Div* co) {
    int *qtCo=new int[4];
    
    for(int i=0;i<4;i++) {
        qtCo[i]=0;
    }
    
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            qtCo[j]+=co[i].qrtrSl[j];
        }
    }
    return qtCo;
}

int sHi(const int* coQt) {
   int hiQ=0;
   int hiAmt=coQt[0];
   
   for(int i=0;i<4;i++) {
       if(coQt[i]>hiAmt) {
           hiAmt=coQt[i];
           hiQ=i; }
   }
   
   return hiQ;
}

int sLo(const int* coQt) {
    int loQ=0;
    int loAmt=coQt[0];
    
    for(int i=0;i<4;i++) {
        if(coQt[i]<loAmt) {
           loAmt=coQt[i];
           loQ=i; }
    }

    return loQ;
}
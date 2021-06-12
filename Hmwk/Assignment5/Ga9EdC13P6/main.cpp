/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 21, 2021, 2:48 PM
 * Purpose: Driver for Invntry Class
 */

//System Library
#include <iostream>
#include <iomanip>
using namespace std;

//User Library
#include "Invntry.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    int size;
    int tempI=0;
    float tempF=0.0f;
    
    //Map Input to Output
    cout<<"How many items are in the Inventory? ";
    cin>>size;
    Invntry p1[size] = { Invntry(),Invntry(), Invntry() };
    cout<<"\nEntering Inventory Information...\n\n";
    for(int i=0;i<size;i++) {
        cout<<"Item #"<<(i+1)<<endl;
        cout<<"Enter item number: ";
        cin>>tempI;
        tempI=(tempI<0)?(tempI*-1):tempI;
        p1[i].setIN(tempI);
        cout<<"Enter quantity: ";
        cin>>tempI;
        tempI=(tempI<0)?(tempI*-1):tempI;
        p1[i].setQ(tempI);
        cout<<"Enter cost: $";
        cin>>tempF;
        tempF=(tempF<0.0)?(tempF*-1.0):tempF;
        p1[i].setC(tempF);
    }
    
    //Output
    cout<<"\nInventory Information Table\n\n";
    //Output
    cout<<left<<setw(10)<<" "<<setw(15)<<"Item Number"<<setw(10)<<"Quantity"<<setw(15)<<"Unit Price"<<setw(10)<<"Total Price"<<endl;
    for(int i=0;i<size;i++) {
        cout<<setprecision(0)<<fixed<<noshowpoint;
        cout<<"Item #"<<(i+1)<<"   "<<setw(15)<<p1[i].getIN()<<setw(10)<<p1[i].getQ();
        cout<<setprecision(2)<<fixed<<showpoint
                <<"$"<<setw(14)<<p1[i].getC()<<"$"<<setw(14)<<p1[i].getTC()<<endl;
    }
    //Clean Up & Exit Program
    return 0;
}


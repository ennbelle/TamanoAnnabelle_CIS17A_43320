/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 21, 2021, 1:57 PM
 * Purpose: Stores Information About Retail Items
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "RItem.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    const int SIZE=3;
    RItem store[SIZE] = {RItem("Jacket",12,59.95), 
                        RItem("Designer Jeans",40,34.95),
                        RItem("Shirt",20,24.95)};
    
    //Output
    cout<<left<<setw(10)<<" "<<setw(20)<<"Description"<<setw(20)<<"Units On Hand"<<setw(10)<<"Price"<<endl;
    for(int i=0;i<SIZE;i++) {
        cout<<"Item #"<<(i+1)<<"   "<<setw(20)<<store[i].getD()<<setw(20)<<store[i].getU()
                <<"$"<<setw(9)<<store[i].getP()<<endl;
    }
    //Clean Up & Exit Program
    return 0;
}


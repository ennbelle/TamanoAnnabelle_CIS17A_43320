/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 19, 2021, 7:16 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Patient.h"
#include "Prcdr.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed
    
    //Declare and Initialize Variables
    Patient p1("Elle","Ferrare","Tamano","199 Heist Ave","San Marcos","CA",92069,9931133,1193340,"Hamish Duke");
    Prcdr p2[3] = { Prcdr("Physical Exam","5/20/2021","Dr. Irvine",250.0),
                  Prcdr("X-ray","5/20/2021","Dr. Jamison",500.0),
                  Prcdr("Blood test","5/20/2021","Dr. Smith",200.0)};
    
    //Process Information - Map Input to Output
    
    //Output
    cout<<"Patient Information\n";
    p1.outp();
    cout<<endl<<endl;
    
    for(int i=0;i<3;i++) {
        cout<<"Procedure #"<<(i+1)<<":\n";
        p2[i].outp(); 
        cout<<endl<<endl;}
    
    //Clean Up & Exit Function
    return 0;
}


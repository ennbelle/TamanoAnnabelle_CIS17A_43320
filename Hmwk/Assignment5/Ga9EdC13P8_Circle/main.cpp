/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 23, 2021, 11:05 PM
 * Purpose: Circle Class Driver Program
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Circle.h"
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    Circle c1;
    float r=0.0f;
    
    //Map Input to Output
    cout<<"Enter length of radius: ";
    cin>>r;
    r=(r<0)?1:r;
    c1.setRad(r);
    
    //Output
    cout<<"\nRadius: "<<c1.getRad();
    cout<<"\nArea of Circle: "<<c1.getArea();
    cout<<"\nDiameter of Circle: "<<c1.getD();
    cout<<"\nCircumference of Circle: "<<c1.getCirc()<<endl;
    
    //Clean Up and Exit
    return 0;
}


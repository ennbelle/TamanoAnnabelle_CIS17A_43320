/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 29, 2021, 7:19 PM
 * Purpose: Min/Max Templates Driver
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
template <class T>
T min(T &v1, T &v2) {
    if(v1>v2) { return v2; }
    else { return v1; }
}

template <class T>
T max(T &v1,T &v2) {
    if(v1>v2) { return v1; }
    else { return v2; }
}

//Global Constant

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize Variables
    char c1,
         c2;
    float f1,
        f2;
    int i1,
        i2;
    
    //Process
    cout<<"Enter two char values (seperate by a space): ";
    cin>>c1>>c2;
    cout<<"Enter two float values (seperate by a space): ";
    cin>>f1>>f2;
    cout<<"Enter two int values (seperate by a space): ";
    cin>>i1>>i2;
    
    //Output
    cout<<endl<<"Comparing Data Type char:\n"
            <<"The greater value between "<<c1<<" and "<<c2<<" is "<<max(c1,c2)<<endl
            <<"The smaller value between "<<c1<<" and "<<c2<<" is "<<min(c1,c2)<<endl;
    cout<<endl<<"Comparing Data Type float:\n"
            <<"The greater value between "<<f1<<" and "<<f2<<" is "<<max(f1,f2)<<endl
            <<"The smaller value between "<<f1<<" and "<<f2<<" is "<<min(f1,f2)<<endl;
    cout<<endl<<"Comparing Data Type int:\n"
            <<"The greater value between "<<i1<<" and "<<i2<<" is "<<max(i1,i2)<<endl
            <<"The smaller value between "<<i1<<" and "<<i2<<" is "<<min(i1,i2)<<endl;
    
    //Clean Up & Exit Program
    return 0;
}


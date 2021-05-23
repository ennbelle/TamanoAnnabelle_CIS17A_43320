/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 6, 2021, 9:32 PM
 * Purpose: Progrm keeps track of a speaker's bureau
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
struct Spkr {
    string name;
    string foneNum;
    string topic;
    float fee;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getDat(Spkr[],short);
void prntDat(const Spkr[],short);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    short size;
    
    //Map input
    cout<<"How many speakers are there? (At LEAST 10) ";
    cin>>size;
    
    while(size<10) {
        cout<<"Enter valid number of speakers: ";
        cin>>size; }
    Spkr bureau[size];
   
    getDat(bureau,size);
    
    //Output Data
    prntDat(bureau,size);
    //Exit
    return 0;
}

//getDat function
void getDat(Spkr b[],short size) {
    for(short i=0;i<size;i++) {
        cin.ignore();
        cout<<"Name: ";
        getline(cin,b[i].name);
        cout<<"Phone #: ";
        getline(cin,b[i].foneNum);
        cout<<"Topic: ";
        getline(cin,b[i].topic);
        cout<<"Fee Required: $";
        cin>>b[i].fee;
        b[i].fee=(b[i].fee<0.0)?0.0: b[i].fee;
        cout<<endl;
    }
}

//prntDat function
void prntDat(const Spkr b[], short size) {
    for(short i=0;i<size;i++) {
        cout<<left<<setw(14)<<"Name:"<<b[i].name<<endl;
        cout<<setw(14)<<"Phone #:"<<b[i].foneNum<<endl;
        cout<<setw(14)<<"Topic:"<<b[i].topic<<endl;
        cout<<setprecision(2)<<fixed<<showpoint;
        cout<<setw(14)<<"Fee Required: $"<<b[i].fee<<endl;
        cout<<endl;
    }
}
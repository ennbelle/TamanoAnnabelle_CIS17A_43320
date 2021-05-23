/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 4, 2021, 4:50 PM
 * Purpose: Drink Machine Simulator
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

//User Libraries
struct Drink {
    string name;
    short cost;
    short num; };

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void runM(Drink[], const int);
void prntM(const Drink[], const int);
    
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=5;
    Drink sodaM[SIZE];
    
    //Initialize Soda Machine
    sodaM[0]={"Cola",75,20};
    sodaM[1]={"Root Beer",75,20};
    sodaM[2]={"Lemon-Lime",75,20};
    sodaM[3]={"Grape Soda",75,20};
    sodaM[4]={"Cream Soda",75,20};
    
    //Run Soda Machine
    runM(sodaM,SIZE);
    
    //Exit Stage Right
    return 0;
}

//runM Function: runs machine
void runM(Drink sodaM[], const int SIZE) {
    //Declare function variables
    short total=0;
    bool none;
    short indSoda;
    string sodaOp;
    short change;
    short usrPay;
    
    prntM(sodaM,SIZE);
    getline(cin,sodaOp);
    
    while (sodaOp!="Quit") {
        for(short i=0;i<SIZE;i++) {
            if(sodaOp!=sodaM[i].name) none=true;
            else {
                none=false;
                indSoda=i; }
        }

        if(none) {
            cin>>usrPay;
            change=usrPay-sodaM[indSoda].cost;
            if(change<0) cout<<"Sorry, that is not enough money for this drink"<<endl;
            else {
                sodaM[indSoda].num--;
                total+=sodaM[indSoda].cost;
                cout<<change<<endl; }
        }
        else cout<<"That is not an option"<<endl;
        prntM(sodaM,SIZE);
        cin.ignore();
        getline(cin,sodaOp);
    }
    cout<<total<<endl;
}

//prntM Function: Print Menu
void prntM(const Drink sodaM[], const int SIZE) {
    for(unsigned char i=0;i<SIZE;i++) {
        cout<<left<<setw(11)<<sodaM[i].name<<setw(4)<<sodaM[i].cost<<sodaM[i].num<<endl;
    }
    cout<<"Quit"<<endl;
}


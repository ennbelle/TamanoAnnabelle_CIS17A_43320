/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on June 6, 2021, 11:13 PM
 * Purpose: Blackjack Project V1
 */

//System Libraries
#include <iostream> //I/O Library
#include <fstream>  //Filestream Library
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void prntR();   //Prints Rules of Game
void playG();   //Print Game
void seeSB();   //See Scoreboard

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    char opt;
    
     //Run Main Menu
    do {
        //Prompt Menu Choices
        cout<<"Blackjack - Main Menu\n";
        cout<<"1. See Blackjack Rules\n"
                <<"2. Play Blackjack (Single Player)\n"
                <<"3. See Scoreboard\n"
                <<"Input option 1, 2, or 3 (Press any other key to quit)... ";
        cin>>opt;
        cout<<endl<<endl;
        
        switch(opt) {
            case '1': prntR(); break;
            case '2': playG(); break;
            case '3': seeSB(); break;
            default: cout<<"Thank you. Goodbye.\n\n"; }
        
    } while(opt=='1'||opt=='2'||opt=='3');
    
    //Clean Up & Exit Program
    return 0;
}

//******************************************************************************
//                   prntR Function - Print Blackjack Rules
//******************************************************************************
void prntR() {
    //Declare Variables
    fstream outpF;

    //Initialize Variables
    outpF.open("rules.txt",ios::in);
    string *outpS=new string[27];

    //Map input to output
    for(short i=0;i<27;i++) {
        getline(outpF,outpS[i],'\n'); }
    //Output
    
    for(short i=0;i<27;i++) {
        cout<<outpS[i]<<endl; }

    //Clean Up
    cout<<endl;
    outpF.close();
    delete [] outpS;
}

//******************************************************************************
//                   playG Function - Play Blackjack
//******************************************************************************
void playG() {
    cout<<"Entering Game Space..."<<endl<<endl;
}

//******************************************************************************
//                   seeSB Function - Displays Scoreboard
//******************************************************************************
void seeSB() {
    cout<<"Entering Scoreboard...\n\n";
}
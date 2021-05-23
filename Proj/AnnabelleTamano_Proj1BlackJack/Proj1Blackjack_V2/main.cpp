/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 1, 2021, 12:59 AM
 * Purpose: This Project simulates the a single player game of Blackjack. (Version 2)
 *          Features Implemented:
 *          - Menu system with options to see rules of game or play game
 *          - prntR Function: Read instructions from separate text file and print out.
 *          - playG Function: Shuffles indexes of card deck
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants

//Function Prototypes
void prntR();     //Print Instructions of Blackjack
void playG(int &);  //Play Blackjack
int *shuffle();

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed
    
    //Declare Variables
    char opt;     //Holds user input of option they pick from main menu
    int mWon;     //Total money won from all games played, in Dollars
    short gPlyd;  //Holds games played
    
    //Initialize Variables
    mWon=0;
    gPlyd=0;
    
    //Map Input to Output
    do {
        //Prompt Menu Choices
        cout<<"Blackjack (Single Player) - Main Menu\n";
        if(gPlyd>0) cout<<"GAMES PLAYED: "<<gPlyd<<"    TOTAL WON: $"<<mWon<<endl;
        else cout<<"***It is HIGHLY recommended to view rules before playing!***"<<endl;
        cout<<"1. See Blackjack (Single Player) Rules\n"
                <<"2. Play Blackjack (Single Player)\n"
                <<"Input option 1 or 2. Press any other key to exit... ";
        cin>>opt;
        cout<<endl<<endl;
        
        switch(opt) {
            case '1': prntR(); break;
            case '2': playG(mWon); gPlyd++; break;
            default: cout<<"Thank you. Goodbye.\n\n"; }
        
    } while(opt=='1'||opt=='2');
    
    //Clean Up & Exit Program
    return 0;
}

//******************************************************************************
//                   prntIns Function - Print Blackjack Rules
//******************************************************************************
void prntR() {
    //Declare Variables
    fstream outpF;

    //Initialize Variables
    outpF.open("rules.txt",ios::in);
    string *outpS=new string[21];

    //Map input to output
    for(short i=0;i<21;i++) {
        getline(outpF,outpS[i],'\n'); }
    //Output
    
    for(short i=0;i<21;i++) {
        cout<<outpS[i]<<endl; }

    //Clean Up
    cout<<endl;
    outpF.close();
    delete [] outpS;
}

//******************************************************************************
//                   playG Function - Play Blackjack
// input: int& mWon (total money won; adds to value if game won & subtracts from 
//        value if game is lost)
// output: N/A
//******************************************************************************
void playG(int& mWon) {
    //Enter Code Here
    cout<<"Entering Game Area...\nPrinting shuffled deck indexes.\n";
    int *deckI=shuffle();
    
    //Validate that deck indexes are shuffled
    for(int i=0;i<52;i++) {
        cout<<deckI[i]<<" "; 
        if (i%9==0&&i!=0) cout<<endl;}
    
    delete []deckI;
    cout<<endl<<endl;
}

//******************************************************************************
//           shuffle Function - shuffle indexes of deck
// input: N/A
// output: int *deckInd (shuffled indexes of card deck)
//******************************************************************************
int *shuffle() {
    //Set random number seed
    srand(time(0));
    
    //Declare and initialize variables
    int r=0;
    int temp=0;
    int *deckInd=new int[52];
    
    for(int i=0;i<52;i++) {
        deckInd[i]=i; }
    
    //Shuffle
    for(int i=0;i<52;i++) {
        int r=i+(rand()%(52-i));
        temp=static_cast<int>(deckInd[i]);
        deckInd[i]=static_cast<int>(deckInd[r]);
        deckInd[r]=temp; }
    
    return deckInd;
}


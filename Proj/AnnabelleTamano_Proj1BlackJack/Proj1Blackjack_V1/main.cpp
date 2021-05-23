/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 1, 2021, 12:59 AM
 * Purpose: This Project simulates the a single player game of Blackjack. (Version 1)
 *          Features Implemented:
 *          - Menu system with options to see rules of game or play game
 *          - Print instructions utilizing cout statements
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants

//Function Prototypes
void prntIns();     //Print Instructions of Blackjack
void playG(int &);  //Play Blackjack

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
        cout<<"1. See Blackjack (Single Player) Rules\n"
                <<"2. Play Blackjack (Single Player)\n"
                <<"Input option 1 or 2. Press any other key to exit... ";
        cin>>opt;
        cout<<endl<<endl;
        
        switch(opt) {
            case '1': prntIns(); break;
            case '2': playG(mWon); gPlyd++; break;
            default: cout<<"Thank you. Goodbye.\n\n"; }
        
    } while(opt=='1'||opt=='2');
    
    //Clean Up & Exit Program
    return 0;
}

//******************************************************************************
//                   prntIns Function - Print Instructions
//******************************************************************************
void prntIns() {
    //Print out the instructions
    cout<<"Blackjack (Single Player) Rules\n"
            <<"- The overall premise is to beat the dealer's hand without going over 21.\n"
            <<"- Certain cards are worth different values. Face cards (K,Q,J) are 10.\n"
            <<"  Aces are 1 OR 11 (Whichever adds to a better hand).\n"
            <<"- Both the player and the dealer start with two cards, however one of the\n"
            <<"  dealer's cards is hidden until the end.\n"
            <<"- At each play you have one of two options. First, you can \'Hit\'\n"
            <<"  which is just asking for another card. OR you can \'Stand\' which\n"
            <<"  signifies holding your total and ending your turn.\n"
            <<"- If the value of your cards go over 21 you bust, and the dealer wins\n"
            <<"  regardless of their hand.\n"
            <<"- If you are dealt 21 from the start, you got a blackjack!\n"
            <<"- The dealer will hit until his/her cards total 17 or higher.\n"
            <<"- NOTE: In order to simplify the game, this version does not deal with\n"
            <<"  splits or doubles.";
    
    cout<<endl<<endl;
}

//******************************************************************************
//                   playG Function - Play Game
//******************************************************************************
void playG(int& mWon) {
    //Enter Code Here
    cout<<"Entering Game Area...";
    
    cout<<endl<<endl;
}

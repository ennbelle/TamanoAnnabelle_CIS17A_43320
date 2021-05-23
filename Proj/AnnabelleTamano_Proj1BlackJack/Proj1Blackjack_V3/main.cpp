/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 5, 2021, 12:33 PM
 * Purpose: This Project simulates a single player game of Blackjack. (Version 3)
 *          Features Implemented:
 *          - Menu system with options to see rules of game or play game
 *          - prntR Function: Read instructions from separate text file and print out.
 *          - playG Function: Shuffles indexes of card deck,
 *            creates array of struct Card
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants

//Function Prototypes
void prntR();     //Print Instructions of Blackjack
void playG(int &);  //Play Blackjack
int *shuffle();    //Shuffles indexes of Deck
Card *inDeck();     //Initialize cards in Deck
void getPt(char,short&);  //Find Point Value of Cards displayed
void scrbrd();

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
                <<"3. See Scoreboard\n"
                <<"Input option 1, 2, or 3 (Press any other key to quit)... ";
        cin>>opt;
        cout<<endl<<endl;
        
        switch(opt) {
            case '1': prntR(); break;
            case '2': playG(mWon); gPlyd++; break;
            case '3': scrbrd(); break;
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
// input: int& mWon (total money won; adds to value if game won & subtracts from 
//        value if game is lost)
// output: N/A
//******************************************************************************
void playG(int& mWon) {
    //Declare and Initialize Variables for Blackjack (Single Player)
    cout<<"Entering Game Area...\nPrinting Deck.\n";
    Card *deck=inDeck();    //Deck of Cards
    int *deckI=shuffle();   //Shuffled Deck Indexes
    Card *usr=new Card[15]; //User Cards
    Card *dlr=new Card[15]; //Dealer Cards
    short usrPt=0;
    short dlrPt=0;
    short usrCd=2;          //Number of User Cards (start off with 2)
    short dlrCd=2;          //Number of Dealer Cards (start off with 2)
    short gInd=4;           //Game Index of Deck (starts at index 4)
    char usrM;              //Indicates user's move (Hit or Stand)
    int bet=0;              //amount of bet
    bool run=true;          //Determines whether the game continues to run
    
    //Deal Cards before Game Start
    usr[0].cardN=deck[deckI[0]].cardN;
    usr[0].suit=deck[deckI[0]].suit;
    dlr[0].cardN=deck[deckI[1]].cardN;
    dlr[0].suit=deck[deckI[1]].suit;
    usr[1].cardN=deck[deckI[2]].cardN;
    usr[1].suit=deck[deckI[2]].suit;
    dlr[1].cardN=deck[deckI[3]].cardN;
    dlr[1].suit=deck[deckI[3]].suit;
    getPt(usr[0].cardN,usrPt);
    getPt(usr[1].cardN,usrPt);
    getPt(dlr[0].cardN,dlrPt);
    getPt(dlr[1].cardN,dlrPt);

    //Start Game
    cout<<"Enter your bet($20-$2000) to start game: $";
    cin>>bet;
    bet=(bet<20)?20:(bet>2000)?2000:bet; //validate bet amount
    
    do {
        //Print Cards (Hide one of the Dealer's Cards)
        cout<<"You: ";
        for(int i=0;i<usrCd;i++) {
            cout<<"[ "<<usr[i].cardN<<" "<<usr[i].suit<<" ]   "; }
        cout<<"Total: "<<usrPt<<endl;
        cout<<"Dealer: [ "<<dlr[0].cardN<<" "<<dlr[0].suit<<" ]   [ Hidden ] Total: N/A\n";
        
        //Check point value after every play
        if(usrPt>21) {
            cout<<"You Lose!"<<endl; 
            mWon-=bet;
            run=false;}
        else if(usrPt==21) {
            cout<<"Blackjack! You win!"<<endl;
            mWon+=(bet*1.5); 
            run=false; }
        else {
            //Ask user for next move (hit or stand)
            cout<<"Hit(\'H\') or Stand(\'S\')? ";
            cin>>usrM;
            if(toupper(usrM)=='H') {
                usr[usrCd].cardN=deck[deckI[gInd]].cardN;
                usr[usrCd].suit=deck[deckI[gInd]].suit;
                getPt(usr[usrCd].cardN,usrPt);
                usrCd++;
                gInd++;
            }
            else {
                cout<<"Now Comparing to Dealer's Hand..."<<endl;
                while(dlrPt<17) {
                    //Print Cards
                    cout<<"You: ";
                    for(int i=0;i<usrCd;i++) {
                        cout<<"[ "<<usr[i].cardN<<" "<<usr[i].suit<<" ]   "; }
                    cout<<"Total: "<<usrPt<<endl;
                    cout<<"Dealer: ";
                    for(int i=0;i<dlrCd;i++) {
                        cout<<"[ "<<dlr[i].cardN<<" "<<dlr[i].suit<<" ]   "; }
                    cout<<"Total: "<<dlrPt<<endl;
                    dlr[dlrCd].cardN=deck[deckI[gInd]].cardN;
                    dlr[dlrCd].suit=deck[deckI[gInd]].suit;
                    getPt(dlr[dlrCd].cardN,dlrPt);
                    dlrCd++;
                    gInd++; }
                //Print Both Hands
                cout<<"You: ";
                for(int i=0;i<usrCd;i++) {
                    cout<<"[ "<<usr[i].cardN<<" "<<usr[i].suit<<" ]   "; }
                cout<<"Total: "<<usrPt<<endl;
                cout<<"Dealer: ";
                for(int i=0;i<dlrCd;i++) {
                    cout<<"[ "<<dlr[i].cardN<<" "<<dlr[i].suit<<" ]   "; }
                cout<<"Total: "<<dlrPt<<endl;
                //Compare Both Hands
                if(usrPt<dlrPt&&dlrPt<=21) {
                    cout<<"You lose!"<<endl;
                    mWon-=bet; }
                else if (usrPt==dlrPt&&dlrPt<=21) {
                    cout<<"Tie! You neither win nor lose!"<<endl;}
                else if(usrPt>dlrPt&&dlrPt<=21) {
                    cout<<"You win!"<<endl;
                    mWon+=(bet*1.5); }
                else { 
                    cout<<"The dealer bust! You neither win nor lose!"<<endl; 
                    mWon+=bet; }
                run=false;
            }
        }
    } while(run==true);

    //Clean Up Function - Deallocate Memory Used
    delete []deckI;
    delete []deck;
    delete []usr;
    delete []dlr;
    cout<<endl<<endl;
}

//******************************************************************************
//               shuffle Function - shuffle indexes of deck
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
    
    //Clean Up & Exit shuffle Function
    return deckInd;
}

//******************************************************************************
//              inDeck Function - Initialize Cards in Deck
// input: N/A
// output: Card *deck (structure array of deck)
//******************************************************************************
Card *inDeck() {
    //Declare and Initialize Variables
    char cn[13] {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char st[4] {'C','H','D','S'};
    int deckI=0;
    Card *deck=new Card[52];
    
    for(int c=0;c<13;c++) {
        for(int s=0;s<4;s++) {
            deck[deckI].cardN=cn[c];
            deck[deckI].suit=st[s];
            deckI++; }
    }
    
    
    //Clean Up & Exit inDeck Function
    return deck;
}

//******************************************************************************
//                   getPt Function - gets total points
//******************************************************************************
void getPt(char cN,short& ttl) {
    switch(cN) {
        case 'A': ttl+=11; if(ttl>21) ttl-=10; break;
        case '2': ttl+=2; break;
        case '3': ttl+=3; break;
        case '4': ttl+=4; break;
        case '5': ttl+=5; break;
        case '6': ttl+=6; break;
        case '7': ttl+=7; break;
        case '8': ttl+=8; break;
        case '9': ttl+=9; break;
        case 'T':
        case 'J':
        case 'Q':
        case 'K': ttl+=10; break; }
}

//******************************************************************************
//                   scrbrd Function - Displays Scoreboard
//******************************************************************************
void scrbrd() {
    cout<<"Entering Scoreboard...\n\n";
}
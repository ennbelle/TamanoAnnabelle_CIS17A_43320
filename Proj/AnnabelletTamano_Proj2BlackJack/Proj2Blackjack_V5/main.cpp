/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on June 6, 2021, 11:13 PM
 * Purpose: Blackjack Project V4
 */

//System Libraries
#include <iostream> //I/O Library
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <valarray>  //Filestream Library
using namespace std;

//User Libraries
#include "Card.h"
#include "GenPlyr.h"
#include "Dealer.h"
#include "Deck.h"

//Global Constants

//Function Prototypes
void prntR();   //Prints Rules of Game
void playG();   //Play Game - Single Player
void playG(int);   //Play Game - Single Player
void seeSB();   //See Scoreboard

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(time(0));
    
    //Declare and Initialize Variables
    char opt;
    int nPlyrs;
    
     //Run Main Menu
    do {
        //Prompt Menu Choices
        cout<<"Blackjack - Main Menu\n";
        cout<<"1. See Blackjack Rules\n"
                <<"2. Play Single Player Blackjack\n"
                <<"3. Play Multi Player Blackjack\n"
                <<"4. See Scoreboard\n"
                <<"Input option 1-4 (Press any other key to quit)... ";
        cin>>opt;
        cout<<endl<<endl;
        
        switch(opt) {
            case '1': prntR(); break;
            case '2': playG(); break;
            case '3': { nPlyrs= rand()%(4-2 + 1) + 2; 
                        playG(nPlyrs); 
                        break; }
            case '4': seeSB(); break;
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
    cout<<"Entering Blackjack Game Space..."<<endl;
    
    //Declare and Initialize Variables
    Deck dck;
    Dealer dlr;
    GenPlyr usr;
    char *tempN=new char[40]; //Temporary Placeholder for Name
    int tempB=0;        //Temporary Placeholder for Bet $
    int dInd=0;           //Deck Ind
    char usrM;
    bool run=true;
    
    //Collect Initial Data
    cout<<"Enter Name: ";
    cin>>tempN;
    usr.setName(tempN);
    cout<<"Place Bet ($2-$50): $";
    cin>>tempB;
    try {
        usr.setBet(tempB);
        cout << endl;

        //Shuffle and Deal Initial Cards
        dck.shuffle();
        usr.addCard(dck.getF(dInd), dck.getS(dInd));
        dInd++;
        dlr.addCard(dck.getF(dInd), dck.getS(dInd));
        dInd++;
        usr.addCard(dck.getF(dInd), dck.getS(dInd));
        dInd++;
        dlr.addCard(dck.getF(dInd), dck.getS(dInd));
        dInd++;

        do {
            //Print Hand
            usr.prnPlyr();
            cout << endl;
            dlr.prnPart();
            cout << endl << endl;

            //Check Points
            if (usr.getHS() == false && usr.getTP() > 21) {
                cout << "You Lose!\n";
                usr.setWon(usr.getBet()*-1);
                run = false;
            } else if (usr.getTP() == 21) {
                cout << "Blackjack! You win!\n";
                usr.setWon(usr.getBet()*1.5);
                usr.setHS(false);
                run = false;
            } else {
                //Ask for Next Move
                cout << "Hit(\'H\') or Stand(\'S\')? ";
                cin>>usrM;
                if (toupper(usrM) == 'H') {
                    usr.addCard(dck.getF(dInd), dck.getS(dInd));
                    dInd++;
                } else {
                    //Dealer keeps adding card til they hit 17+ Points
                    while (dlr.getTP() < 17) {
                        //Print Hand
                        usr.prnPlyr();
                        cout << endl;
                        dlr.prnPlyr();
                        cout << endl << endl;
                        //Add Card
                        dlr.addCard(dck.getF(dInd), dck.getS(dInd));
                        dInd++;
                    }
                    //Print Hand
                    usr.prnPlyr();
                    cout << endl;
                    dlr.prnPlyr();
                    cout << endl;
                    //Compare for Winner
                    if (usr.getTP() < dlr.getTP() && dlr.getTP() <= 21) {
                        cout << "You Lose!\n";
                        usr.setWon(usr.getBet()*-1);
                    } else if (usr.getTP() == dlr.getTP() && dlr.getTP() <= 21) {
                        cout << "Tie! You neither win nor lose!" << endl;
                    } else if (usr.getTP() > dlr.getTP() && dlr.getTP() <= 21) {
                        cout << "You win!" << endl;
                        usr.setWon(usr.getBet()*1.5);
                    } else {
                        cout << "The dealer bust! You neither win nor lose!" << endl;
                    }

                    //end run
                    run = false;
                }
            }
        } while (run == true);
    } catch (GenPlyr::BadBet) {
        cout<<"\nYour bet was out of range! Unfortunately, you are not allowed into the game.\n\n";
    }
    //Clean Up
    cout<<endl<<endl;
    delete []tempN;
}

//******************************************************************************
//               playG Function - Play Blackjack Multi-player
//******************************************************************************
void playG(int amt) {
    //Set Random Number Seed
    srand(time(0));
    
    //Declare and Initialize Variables
    Deck dck;
    Dealer dlr;
    GenPlyr *plyrs=new GenPlyr[amt];
    char *tempN=new char[40]; //Temporary Placeholder for Name
    int tempB=0;        //Temporary Placeholder for Bet $
    int dInd=0;           //Deck Ind
    int n;
    char usrM;
    bool run=true;
    
    //Set Up Initial Data
    cout<<"Entering Multi-Player Blackjack Lobby...\n";
    for(int i=0;i<amt;i++) {
        if(i<(amt-1)) {
            n=rand()%(35 + 1);
            plyrs[i].genPlyr(n); }
    }
    cout<<"Enter Name: ";
    cin>>tempN;
    plyrs[amt-1].setName(tempN);
    cout<<"Place Bet ($2-$50): $";
    cin>>tempB;
    try {
        plyrs[amt - 1].setBet(tempB);
        cout << endl;

        //Print All Player's Initial Info
        cout << endl << "Players in Game\n";
        for (int j = 0; j < amt; j++) {
            plyrs[j].prnInfo();
            cout << endl;
        }

        cout << "\nStarting Game...\n";

        //Shuffle Deck and Initialize Cards
        dck.shuffle();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < amt; j++) {
                plyrs[j].addCard(dck.getF(dInd), dck.getS(dInd));
                dInd++;
            }
            dlr.addCard(dck.getF(dInd), dck.getS(dInd));
            dInd++;
        }

        //Run Game
        do {
            //Print Hand
            for (int i = 0; i < amt; i++) {
                if (i == amt - 1) {
                    cout << "(you) ";
                }
                plyrs[i].prnPlyr();
                cout << endl;
            }
            dlr.prnPart();
            cout << endl << endl;
            run = false;
        } while (run == true);
    } catch (GenPlyr::BadBet) {
        cout<<"\nYour bet was out of range! Unfortunately, you are not allowed into the game.\n\n";
    }
    
    //Clean Up
    delete []tempN;
    delete []plyrs;
}

//******************************************************************************
//                   seeSB Function - Displays Scoreboard
//****************************************************************************
void seeSB() {
    cout<<"Entering Scoreboard...\n\n";
}
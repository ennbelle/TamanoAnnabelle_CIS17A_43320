/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on June 6, 2021, 11:13 PM
 * Purpose: Blackjack Project V4
 */

//System Libraries
#include <iostream> //I/O Library
#include <fstream>  //Filestream Library
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
                <<"2. Play Single Player Blackjack\n"
                <<"3. Play Multi Player Blackjack\n"
                <<"4. See Scoreboard\n"
                <<"Input option 1-4 (Press any other key to quit)... ";
        cin>>opt;
        cout<<endl<<endl;
        
        switch(opt) {
            case '1': prntR(); break;
            case '2': playG(); break;
            case '3': playG(); break;
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
    usr.setBet(tempB);
    cout<<endl;
    
    //Shuffle and Deal Initial Cards
    dck.shuffle();
    usr.addCard(dck.getF(dInd),dck.getS(dInd));
    dInd++;
    dlr.addCard(dck.getF(dInd),dck.getS(dInd));
    dInd++;
    usr.addCard(dck.getF(dInd),dck.getS(dInd));
    dInd++;
    dlr.addCard(dck.getF(dInd),dck.getS(dInd));
    dInd++;
    
    do {
        //Print Hand
        usr.prnPlyr();
        cout<<endl;
        dlr.prnPart();
        cout<<endl<<endl;
        
        //Check Points
        if(usr.getHS()==false && usr.getTP()>21) {
            cout<<"You Lose!\n";
            usr.setWon(usr.getBet()*-1);
            run=false;
        }else if(usr.getTP()==21) {
            cout<<"Blackjack! You win!\n";
            usr.setWon(usr.getBet()*1.5);
            usr.setHS(false);
            run=false;
        }else {
            //Ask for Next Move
            cout<<"Hit(\'H\') or Stand(\'S\')? ";
            cin>>usrM;
            if(toupper(usrM)=='H') {
                usr.addCard(dck.getF(dInd),dck.getS(dInd));
                dInd++;
            }else {
                //Dealer keeps adding card til they hit 17+ Points
                while(dlr.getTP()<17) {
                    //Print Hand
                    usr.prnPlyr();
                    cout<<endl;
                    dlr.prnPlyr();
                    cout<<endl<<endl;
                    //Add Card
                    dlr.addCard(dck.getF(dInd),dck.getS(dInd));
                    dInd++;
                }
                //Print Hand
                usr.prnPlyr();
                cout<<endl;
                dlr.prnPlyr();
                cout<<endl;
                //Compare for Winner
                if(usr.getTP()<dlr.getTP()&&dlr.getTP()<=21) {
                    cout<<"You Lose!\n";
                    usr.setWon(usr.getBet()*-1);
                }else if(usr.getTP()==dlr.getTP()&&dlr.getTP()<=21) {
                    cout<<"Tie! You neither win nor lose!"<<endl;
                }else if(usr.getTP()>dlr.getTP()&&dlr.getTP()<=21) {
                    cout<<"You win!"<<endl;
                    usr.setWon(usr.getBet()*1.5);
                }else {
                    cout<<"The dealer bust! You neither win nor lose!"<<endl;
                }
                
                //end run
                run=false;
            }
        }
    } while(run==true);
    
    //Clean Up
    cout<<endl<<endl;
    delete []tempN;
}

//******************************************************************************
//                   seeSB Function - Displays Scoreboard
//******************************************************************************
void seeSB() {
    cout<<"Entering Scoreboard...\n\n";
}
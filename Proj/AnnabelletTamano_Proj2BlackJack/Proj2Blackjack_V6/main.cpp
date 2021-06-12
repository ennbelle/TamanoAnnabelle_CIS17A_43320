/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on June 6, 2021, 11:13 PM
 * Purpose: Blackjack Project V6
 */

//System Libraries
#include <iostream> //I/O Library
#include <ctime>    //CTime
#include <cstdlib>  //C-Standard Library
#include <fstream>  //Filestream Library
using namespace std;

//User Libraries
#include "Card.h"
#include "GenPlyr.h"
#include "Dealer.h"
#include "Deck.h"

//Global Constants
//N/A

//Function Prototypes
void prntR();   //Prints Rules of Game
void playG();   //Play Game - Single Player
void playG(int);   //Play Game - Single Player

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
                <<"Input option 1-3 (Press any other key to quit)... ";
        cin>>opt;
        cout<<endl<<endl;
        
        switch(opt) {
            case '1': prntR(); break;
            case '2': playG(); break;
            case '3': { nPlyrs= rand()%(4-2 + 1) + 2; 
                        playG(nPlyrs); 
                        break; }
            default: cout<<"Thank you. Goodbye.\n\n"; }
        
    } while(opt=='1'||opt=='2'||opt=='3');
    
    //Clean Up & Exit Program
    return 0;
}

//******************************************************************************
//                   prntR Function - Print Blackjack Rules
// Input: N/A
// Output: N/A
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
// Input: N/A
// Output: N/A
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
            } else if (usr.getTP() == 21&&dInd<=4) {
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
// Input: amt (number of players)
//  Output: None
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
    bool allS=true; //All Stand
    bool allB=true; //All Bust
    
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
            allS=true;
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
            
            //Check Values
            for(int i=0;i<amt;i++) {
                if(plyrs[i].getHS()==true) {
                    if (plyrs[i].getTP() > 21) {
                        plyrs[i].setBust(true);
                        plyrs[i].setHS(false);
                        plyrs[i].setWon(plyrs[i].getBet()*-1);
                    } else if (plyrs[i].getTP() == 21 && dInd <=amt*2+2) {
                        cout << "Blackjack!" << plyrs[i].getName() << "wins $";
                        plyrs[i].setWon(plyrs[i].getBet()*1.5);
                        cout << plyrs[i].getWon()<<endl<<endl;
                        plyrs[i].setHS(false);
                        run = false;
                    } else {
                        if (i == amt - 1) {
                            cout << "Hit(\'H\') or Stand(\'S\')? ";
                            cin>>usrM;
                            if (toupper(usrM) == 'H') {
                                plyrs[i].addCard(dck.getF(dInd), dck.getS(dInd));
                                dInd++;
                            } else {
                                plyrs[i].setHS(false);
                            }
                        } else {
                            plyrs[i].randHS();
                            if (plyrs[i].getHS() == true) {
                                plyrs[i].addCard(dck.getF(dInd), dck.getS(dInd));
                                dInd++;
                            }
                        }
                    }
                }
            }
            
            //Check to see if all players or all bust
            for(int i=0;i<amt;i++) {
                if(plyrs[i].getHS()==true) {
                    allS=false; }
                if(plyrs[i].getBust()==false) {
                    allB=false; }
            }
        
            if(allS==true) { run=false; }
            
        } while (run == true);
        
        //Dealer deals own cards 
        if(allB==true) {
            cout<<"There are no winners!\n";
        } else {
            //Dealer deals card until it is above 17 points
            while (dlr.getTP() < 17) {
                //Print Hand
                for (int i = 0; i < amt; i++) {
                    if (i == amt - 1) {
                        cout << "(you) ";
                    }
                    plyrs[i].prnPlyr();
                    cout << endl;
                }
                dlr.prnPlyr();
                cout << endl << endl;

                dlr.addCard(dck.getF(dInd), dck.getS(dInd));
                dInd++;
            }

            //Print Hand
            for (int i = 0; i < amt; i++) {
                if (i == amt - 1) {
                    cout << "(you) ";
                }
                plyrs[i].prnPlyr();
                cout << endl;
            }
            dlr.prnPlyr();
            cout << endl << endl;

            //Compare for Winner
            for(int i=0;i<amt;i++) {
                if (plyrs[i].getTP() < dlr.getTP() && dlr.getTP() <= 21) {
                    cout<<plyrs[i].getName()<<"! You lose :(\n";
                    plyrs[i].setWon(plyrs[i].getBet()*-1);
                } else if (plyrs[i].getTP() == dlr.getTP() && dlr.getTP() <= 21) {
                    cout<<plyrs[i].getName()<<", you tie! You neither win nor lose!\n" << endl;
                } else if (plyrs[i].getTP() > dlr.getTP() && dlr.getTP() <= 21) {
                    cout<<plyrs[i].getName()<<"! You win :)\n" << endl;
                    plyrs[i].setWon(plyrs[i].getBet()*1.5);
                }
            }
            if(dlr.getTP()>21) {
                cout<<"The dealer bust! No one wins :)\n";
            }
            cout<<endl<<endl;
        }  
        
    } catch (GenPlyr::BadBet) {
        cout<<"\nYour bet was out of range! Unfortunately, you are not allowed into the game.\n\n";
    }
    
    //Clean Up
    delete []tempN;
    delete []plyrs;
}
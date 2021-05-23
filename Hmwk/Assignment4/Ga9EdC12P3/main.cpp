/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 2, 2021, 10:18 PM
 * Purpose: This Program gets a joke and its punchline from two separate files,
 *          and then prints it on screen.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string jk; //joke
    string pnl[100]; //punchline
    int n=0;
    
    //Open Files
    fstream jkFl,pnlFl;
    jkFl.open("joke.txt",ios::in);
    pnlFl.open("pnchln.txt",ios::in);
    
    //Read Data from Files
    if(jkFl.is_open()) { getline(jkFl,jk); }
    
    if(pnlFl.is_open()) {
        while(getline(pnlFl,pnl[n])) {
            n++; }
    }
    
    //Print 
    cout<<jk<<endl;
    cout<<pnl[n-1]<<endl;
    
    //Clean Up & Exit
    jkFl.close();
    pnlFl.close();
    return 0;
}


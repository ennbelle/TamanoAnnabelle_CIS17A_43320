/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on June 11, 2021, 11:56 AM
 * Purpose: 
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Prob2Sort.h"

int main(int argc, char** argv) {
    //Given Driver 
    cout << "The start of Problem 2, the sorting problem" << endl;
    Prob2Sort<char> rc;
    bool ascending = true;
    ifstream infile;
    infile.open("Problem2.txt", ios::in);
    char *ch2 = new char[10 * 16];
    char *ch2p = ch2;
    while (infile.get(*ch2)) {
        cout << *ch2;
        ch2++;
    }
    infile.close();
    cout << endl;
    cout << "Sorting on which column" << endl;
    int column;
    cin>>column;
    char *zc = rc.sortArray(ch2p, 10, 16, column, ascending);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 16; j++) {
            cout << zc[i * 16 + j];
        }
    }
    
    //Different File
    cout<<"\n\nThe start of the sorting problem with integers"<<endl;
    Prob2Sort<int> ic;
    ascending=false;
    infile.open("Prob2Int.txt", ios::in);
    int count=0;
    int *i2=new int[10*16];
    int *i2p = i2;
    while(infile>>*i2) {
        cout<<*i2<<" ";
        i2++;
        count++;
        if(count%16==0) { cout<<endl; }
    }
    infile.close();
    cout << endl;
    cout << "Sorting on which column" << endl;
    cin>>column;
    int *ac=ic.sortArray(i2p,10,16,column, ascending);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 16; j++) {
            cout << ac[i * 16 + j]<<" ";
        }
        cout<<endl;
    }
    
    //Clean Up
    delete []ch2;
    delete []i2;
    return 0;
}


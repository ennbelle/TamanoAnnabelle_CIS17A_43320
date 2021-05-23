/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 21, 2021, 1:10 AM
 * Purpose: Sentence Filter - This program reads sentences from one file and
 *          and changes all the letters to lowercase unless first letter of each
 *          sentence. The revised content is stored in the second file.
 */

//NOTE:
//Change to ask user for file names?

//System Libraries
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
char **readOg(fstream &, short&);  //Read original
void rvsOg(char**,short);   //Revise Original
void wrtRvsd(fstream &,char**,short); //Write Revised Sentence

//Execution Begins
int main(int argc, char** argv) {
    //Declare variables
    fstream orgnl,rvsd;
    short n;
    
    //Open Files for use
    orgnl.open("dat.txt",ios::in);  //open data text file
    rvsd.open("rdat.txt",ios::out);    //open revised data text file
    
    //Read and Filter Sentences
    char **finp=readOg(orgnl,n);    //finp = file input
    rvsOg(finp,n);
    wrtRvsd(rvsd,finp,n);
    
    //Clean Up -- Exit the Function
    orgnl.close();
    rvsd.close();
    for(int i=0;i<80;i++) {
        delete []finp[i]; }
    delete []finp;
    return 0;
}

//readOg Function
//getline every part of txt file
// save to dynamically created array
char **readOg(fstream& in, short& n) {
    n=0;
    char** og=new char*[80];    
    for(int i=0;i<80;i++) {
        og[i]=new char[80]; }
    
    while(in>>og[n]) {
        n++; }
    
    n+=1;
    
    return og;
}

//rvsOg Function
//argument - array created
//traverse array to find . and toupper each letter which proceeds it
//tolower each other letter
void rvsOg(char** finp,short n) {
    finp[0][0]=toupper(finp[0][0]);
    for(int j=1;j<strlen(finp[0]);j++) {
        finp[0][j]=tolower(finp[0][j]); }
    
    for(int i=1;i<n;i++) {
        for(int j=0;j<strlen(finp[i]);j++) {
            if(((finp[i-1][strlen(finp[i-1])-1]=='.')||
                    (finp[i-1][strlen(finp[i-1])-1]=='?')||
                    (finp[i-1][strlen(finp[i-1])-1]=='!'))&&(j==0)) { finp[i][j]=toupper(finp[i][j]); }
            else { finp[i][j]=tolower(finp[i][j]); }
        }
    }
}


//wrtRvsd Function
//traverse array
//write each element into file
void wrtRvsd(fstream& out,char** finp, short n) {
    for(short i=0;i<n;i++) {
        out<<finp[i];
        if(i<(n-1)) { out<<" "; }
    }
    cout<<"Check \'rdat.txt\' file for filtered output."<<endl;
}
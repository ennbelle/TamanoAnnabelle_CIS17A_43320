/* 
 * File: main.cpp
 * Author: Annabelle Tamano
 * Created on March 14,2021 at 3:30 PM
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

//Search for one occurrence
int  srch1(const char sntnce[],const char pattern[],int match) {
    unsigned char pPos=0; //Position of pattern
    unsigned char sPos=0; //Start position of match
    unsigned char crrct=0; //Counts correct matches
    for(unsigned char i=0;i<strlen(sntnce);i++) {
        if(sntnce[i]==pattern[pPos]) {
            if(pPos==0) {sPos=i;}
            crrct++;
            pPos++;
            if(crrct==strlen(pattern)) {
                match=sPos;
                return match; }
        }
        else {
            pPos=0;
            crrct=0; }
    }
    return -1;
}

//Search for all occurrences
void srchAll(const char sntnce[],const char pattern[],int match[]) {
    unsigned char pPos=0; //Position of pattern
    unsigned char sPos=0; //Start position of match
    unsigned char crrct=0; //Counts correct matches
    unsigned char mPos=0; //Position of match array
    for(unsigned char i=0;i<strlen(sntnce);i++) {
        if(sntnce[i]==pattern[pPos]) {
            if(pPos==0) {sPos=i;}
            crrct++;
            pPos++;
            if(crrct==strlen(pattern)) {
                match[mPos]=sPos;
                mPos++; }
        }
        else {
            pPos=0;
            crrct=0; }
    }
    match[mPos]=-1;
}

//Print char
void print(const char arr[]) {
    cout<<arr<<endl;
}

//Print int array
void print(const int arr[]) {
    unsigned char i=0;
    while(arr[i]>=0) {
        cout<<arr[i]<<endl;
        i++; }
    if(arr[0]==-1) {cout<<"None"<<endl;}
}



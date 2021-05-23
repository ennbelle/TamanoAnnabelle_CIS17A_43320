/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 6, 2021, 8:36 PM
 * Purpose: Utilizes structs to store and print movie titles, directors, release year, and run time
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//User Libraries
struct MovDat {
    string title;       //Movie Title
    string drtr;        //Director
    int rlsYr;     //Release Date
    int runTime; }; //movie run time
    
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getDat(MovDat[],int);
void prntDat(const MovDat[],int);
    
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int size;
    
    //Map Inputs to Outputs
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)."<<endl;
    cin>>size;
    MovDat movies[size];
    getDat(movies,size);
    
    //Output
    prntDat(movies,size);
    
    //Exit -- Clean UP
    return 0;
}

//getDat Function - Gets data from user
void getDat(MovDat movs[],int size) {
    for(int i=0;i<size;i++) {
        cin.ignore();
        getline(cin,movs[i].title);
        getline(cin,movs[i].drtr);
        cin>>movs[i].rlsYr;
        cin>>movs[i].runTime; }
}

//prntDat Function
void prntDat(const MovDat movs[], int size) {
    for(int i=0;i<size;i++) {
        cout<<endl;
        cout<<left<<setw(11)<<"Title:"<<movs[i].title<<endl;
        cout<<left<<setw(11)<<"Director:"<<movs[i].drtr<<endl;
        cout<<left<<setw(11)<<"Year:"<<movs[i].rlsYr<<endl;
        cout<<left<<setw(11)<<"Length:"<<movs[i].runTime<<endl; }
}

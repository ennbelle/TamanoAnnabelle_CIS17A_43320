/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 1, 2021, 9:42 AM
 * Purpose: This program utilizes a structure to store division name, all four
 *          quarter sales and average quarterly sales
 * The program should use four variables of this structure. Each variable should 
 * represent on of the following corporate divisions: East, West, North, and South. 
 * The user should be asked for the four quarters' sales figures for each division.
 * Each division's total and average sales should be calculated and stored in the
 * appropriate member of each structure variable. These figures should then be 
 * displayed on the screen.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct Division {
    string name;
    float qtrSls[4];  //Holds sales for each quarter
    float ttlSls;   //Holds total annual sales
    float avgSls; };//Holds average quarterly sales
    
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

    
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Division company[4];
    //Initialize Variables
    
    //Process or map Inputs to Outputs and Display Output
    cout<<setprecision(2)<<fixed<<showpoint; //format to 2 decimals
    for(unsigned char d=0;d<4;d++) {
        company[d].name=(d==0)?"North":
            (d==1)?"West":
            (d==2)?"East":
            "South";
        cout<<company[d].name<<endl;
        //Get quarterly sales and add to total sales
        for(unsigned char q=0;q<4;q++) {
            cout<<"Enter ";
            (d==0)?cout<<"first":(d==1)?cout<<"second":(d==2)?cout<<"third":cout<<"fourth";
            cout<<"-quarter sales:"<<endl;
            cin>>company[d].qtrSls[q];
            company[d].ttlSls+=company[d].qtrSls[q];
        }
        //Print total annual sales
        cout<<"Total Annual sales:$"<<company[d].ttlSls<<endl;
        //Calculate and print average quarterly sales
        company[d].avgSls=company[d].ttlSls/4;
        cout<<"Average Quarterly Sales:$"<<company[d].avgSls;
        if(d!=3) cout<<endl;
    }

    //Exit stage right!
    return 0;
}

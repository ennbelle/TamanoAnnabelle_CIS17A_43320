/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 5, 2021, 12:32 PM
 * Purpose: This program takes in the user's monthly budget and compares it to the
 *          budget provided. It then sends a report on whether for each section the
 *          user's budget is over, under or even.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct MoBdgt {
    float hsg;      //Housing budget
    float utlts;     //Utilities
    float hshldEx;  //Household Expenses budget
    float trnsp;    //Transportation budget
    float food;     //Food budget
    float mdcl;     //Medical budget
    float insrnc;   //Insurance budget
    float ent;      //Entertainment budget
    float clthng;   //Clothing budget
    float misc;     //Miscellaneous budget
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
MoBdgt getDat();   //Get user's monthly budget
void bdgtRep(MoBdgt);    //Prints budget report

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    MoBdgt month;
    
    //Initialize Variables
    //Process or map Inputs to Outputs
    month=getDat();
    
    //Display Outputs
    bdgtRep(month);
    
    //Exit stage right!
    return 0;
}

//getDat Function: gets monthly budget from user
MoBdgt getDat() {
    MoBdgt mo;
    
    cout<<"Enter housing cost for the month:$"<<endl;
    cin>>mo.hsg;
    cout<<"Enter utilities cost for the month:$"<<endl;
    cin>>mo.utlts;
    cout<<"Enter household expenses cost for the month:$"<<endl;
    cin>>mo.hshldEx;
    cout<<"Enter transportation cost for the month:$"<<endl;
    cin>>mo.trnsp;
    cout<<"Enter food cost for the month:$"<<endl;
    cin>>mo.food;
    cout<<"Enter medical cost for the month:$"<<endl;
    cin>>mo.mdcl;
    cout<<"Enter insurance cost for the month:$"<<endl;
    cin>>mo.insrnc;
    cout<<"Enter entertainment cost for the month:$"<<endl;
    cin>>mo.ent;
    cout<<"Enter clothing cost for the month:$"<<endl;
    cin>>mo.clthng;
    cout<<"Enter miscellaneous cost for the month:$"<<endl;
    cin>>mo.misc;
    
    return mo;
}
//Compare to 500,150,65,50,250,30,100,150,75,50
void bdgtRep(MoBdgt month) {
    float expTtl=1420.0f;
    float userTtl=0.0f;
    float cmp=0.0f;
    
    cout<<"Housing ";
    if(month.hsg>500) cout<<"Over";
    else if(month.hsg<500) cout<<"Under";
    else cout<<"Even";
    userTtl+=month.hsg;
    
    cout<<"\nUtilities ";
    if(month.utlts>150) cout<<"Over";
    else if(month.utlts<150) cout<<"Under";
    else cout<<"Even";
    userTtl+=month.utlts;
    
    cout<<"\nHousehold Expenses ";
    if(month.hshldEx>65) cout<<"Over";
    else if(month.hshldEx<65)cout<<"Under";
    else cout<<"Even";
    userTtl+=month.hshldEx;
    
    cout<<"\nTransportation ";
    if(month.trnsp>50) cout<<"Over";
    else if(month.trnsp) cout<<"Under";
    else cout<<"Even";
    userTtl+=month.trnsp;
    
    cout<<"\nFood ";
    if(month.food>250) cout<<"Over";
    else if(month.food<250) cout<<"Under";
    else cout<<"Even";
    userTtl+=month.food;
    
    cout<<"\nMedical ";
    if(month.mdcl>30) cout<<"Over";
    else if(month.mdcl<30) cout<<"Under";
    else cout<<"Even";
    userTtl+=month.mdcl;
    
    cout<<"\nInsurance ";
    if(month.insrnc>100) cout<<"Over";
    else if(month.insrnc<100) cout<<"Under";
    else cout<<"Even";
    userTtl+=month.insrnc;
    
    cout<<"\nEntertainment ";
    if(month.ent>150)cout<<"Over";
    else if(month.ent<150)cout<<"Under";
    else cout<<"Even";
    userTtl+=month.ent;
    
    cout<<"\nClothing ";
    if(month.clthng>75) cout<<"Over";
    else if(month.clthng<75) cout<<"Under";
    else cout<<"Even";
    userTtl+=month.clthng;
    
    cout<<"\nMiscellaneous ";
    if(month.misc>50) cout<<"Over";
    else if(month.misc<50)cout<<"Under";
    else cout<<"Even";
    userTtl+=month.misc;
    
    cmp=expTtl-userTtl;
    cout<<setprecision(2)<<fixed<<showpoint;
    if(cmp==0) cout<<endl<<"You broke even";
    else {
        cout<<endl<<"You were $";
        if(cmp>0) cout<<cmp<<" under budget";
        else cout<<cmp*-1<<" over budget";
    }
}
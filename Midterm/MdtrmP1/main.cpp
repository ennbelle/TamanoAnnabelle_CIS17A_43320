/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 24, 2021, 12:32 AM
 */

#include <iostream>
#include <string>
using namespace std;

//User Libraries
struct Cstmr {
    string name;
    string addrss;
    int accNum;    //Account Number
    int blnc;    //Start balance at the beginning of month
    int ttlCh;  //Total of all checks written by customer
    int ttlDep; //Total of all deposits credited to customer this month
};
//Global Constants

//Function Prototypes

//Function begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int tempCh=0;
    int tempDep=0;
    int newBlnc=0;
    int ttC=0;
    int ttD=0;
    
    //Instantiate Variables
    Cstmr *c1= new Cstmr;
    
    //Map Input to Output
    //Get Customer Information
    cout<<"Name: ";
    getline(cin,c1->name);
    cout<<"Address: ";
    getline(cin,c1->addrss);
    cout<<"Account Number: ";
    cin>>c1->accNum;
    cout<<"Starting Balance: $";
    cin>>c1->blnc;
    cout<<"Enter all checks this month (NOTE: Enter negative number to stop check input):"<<endl;
    cout<<"$";
    cin>>tempCh;
    while(tempCh>=0) {
        ttC+=tempCh; 
        cout<<"$";
        cin>>tempCh; }
    c1->ttlCh=ttC;
    cout<<"Enter all deposits this month (NOTE: Enter negative number to stop check input):"<<endl;
    cout<<"$";
    cin>>tempDep;
    while(tempDep>=0) {
        ttD+=tempDep; 
        cout<<"$";
        cin>>tempDep;}
    c1->ttlDep=ttD;
    //Output Account Information  
    cout<<endl<<"Account Details: "<<endl;
    cout<<"Name: "<<c1->name<<endl;
    cout<<"Address: "<<c1->addrss<<endl;
    cout<<"Account No.: "<<c1->accNum<<endl;
    cout<<"Starting Balance: $"<<c1->blnc<<endl;
    cout<<"Total of Checks Made: -$"<<c1->ttlCh<<endl;
    cout<<"Total of Deposits Made: $"<<c1->ttlDep<<endl<<endl;
    

    //Calculate New Balance
    newBlnc=static_cast<int>(c1->blnc);
    newBlnc+=(ttD-ttC);
    if(newBlnc<0) { 
        cout<<"WARNING: A $20 fee has been taken from your account for overdrawing from balance!"<<endl;
        newBlnc-=20; }
    cout<<"New Balance: $"<<newBlnc<<endl;
    
    
    //Clean Up & Exit Function
    delete c1;
    return 0;
}


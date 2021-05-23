/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 27, 2021, 1:01 AM
 * 
 * NOTES
 * -Change to Dynamically Structured Arrays
 * -Figure out how to write in English
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
struct Emply {
    string name; //Employee Name
    int hrsW;   //hours worked
    float rtPy;   //rate pay
};
    
//Global Constants

//Function Prototypes
float gtMPy(int,float);  //Get Employee's Pay
string getMPyE(float); //Get Employee's Pay in English

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string coName; //Company Name
    string coAdd;   //Company Address
    string sig;     //Holds Signature
    int empNum;     //Number of Employees
    
    //Find Company Information
    cout<<"Company Name: ";
    getline(cin,coName);
    cout<<"Company Address: ";
    getline(cin,coAdd);
    cout<<"Enter Number of Employees: ";
    cin>>empNum;
    cin.ignore();
    
    //Instantiate Employee List
    Emply co[empNum];
    float mPay[empNum]; //Get each employee's gross pay
    string mPayE[empNum]; //Get employee's gross pay in English
    
    //Get Employee Information
    cout<<endl<<"Enter Employee Information: "<<endl;
    for(short i=0;i<empNum;i++) {
        cout<<"#"<<i+1<<" Name: ";
        getline(cin,co[i].name);
        cout<<"   Hours Worked: ";
        cin>>co[i].hrsW;
        cout<<"   Rate of Pay: $";
        cin>>co[i].rtPy;
        mPay[i]=gtMPy(co[i].hrsW,co[i].rtPy);
        mPayE[i]=getMPyE(mPay[i]);
        cin.ignore();  }
        
    //Write Checks
    cout<<endl<<"Check Book: "<<endl;
    for(short i=0;i<empNum; i++) {
        cout<<setprecision(0)<<fixed<<noshowpoint;
        cout<<"Check #"<<i+1<<endl;
        cout<<coName<<endl;
        cout<<coAdd<<endl;
        cout<<left<<setw(6)<<"Name: "<<setw(20)<<co[i].name;
        cout<<setprecision(2)<<fixed<<showpoint;
        cout<<setw(9)<<"Amount: $"<<setw(15)<<mPay[i]<<endl;
        cout<<setw(8)<<"Amount: "<<mPayE[i]<<endl;
        cout<<"Signature Line: ";
        getline(cin,sig);
        cout<<endl;
    }
    
    //Clean Up & Exit Function
    return 0;
}

float gtMPy(int hrsW,float rtPy) {
    //Declare and Initialize Variables Needed
    float gPy=0.0f; //gross pay
    int ot=0;     //time over 40 hours
    
    //Calculate Gross Pay
    if(hrsW<=40) { gPy=hrsW*static_cast<float>(rtPy); }
    else {
        gPy=40.0*rtPy;
        ot=hrsW-40;
        if(ot<=10) { gPy+=ot*(rtPy*2.0); }
        else {
            gPy+=10*(rtPy*2.0);
            ot-=10;
            gPy+=ot*(rtPy*3.0); }
    }
    //Exit Function -- Return Value
    return gPy; }

string getMPyE(float n) {
    int tn=static_cast<int>(n);
    string pay;
    int add=0;
    //Store
    string ones[] {"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string teens[] {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen","Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[] {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
   while(tn>0) {
        if (tn<10) {
            pay+=ones[tn];
            tn/=10;
        } else if (tn<20) {
            pay+=teens[tn-10];
            tn/=20;
        } else if (tn<100) {
            pay+=tens[tn/10];
            tn%=10;
        } else if (tn<1000) {
            pay+=ones[tn/100] + " Hundred";
            tn%=100;
            
        } else if(tn<10000) {
            pay+=ones[tn/1000] + " Thousand";
            tn%=1000;
        } else if(tn<100000) {
            if((tn/1000)>20) {
                pay+=tens[tn/10000];
                tn%=10000;}
            else {
                pay+=teens[(tn/1000)-10]+" Thousand";
                tn%=1000;}
        } else if (tn<1000000) {
            pay+=ones[tn/100000] + "Hundred";
            tn%=100000;
        } else {
            pay="Error";
            tn=0;
        }
        
        if(tn!=0) { pay+=" ";}
    }
    pay+=" Dollars";
    return pay;
}
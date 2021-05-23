/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on April 27, 2021, 1:21 PM
 */
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

// Function Prototypes
bool vldt(short); //validate function
void encrypt(); //encrypt function
void decrypt(); //decrypt function

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char opt; //Menu Option
    
    //Menu System
    do {
        cout<<"What would you like to do?\n1.Encrypt Data\n2.Decrypt Data\n(Input 1 or 2. OR Press any other key quit.) ";
        cin>>opt;
        cout<<endl;
        
        switch(opt) {
            case '1': { encrypt(); break; }
            case '2': { decrypt(); break; }
            default: cout<<"Goodbye.\n";
        }
    } while(opt=='1'||opt=='2');
    
    //Exit Function
    return 0;
}

void encrypt() {
    //Declare Variables
    bool isVld; //checks if value is valid
    short dt=0; //inputed data
    short nP=1; //number place
    short tdt=0; //temporary data
    short pVal=0; //place value
    short edt=0; //encrypted data
    
    //Map Input and Process
    cout<<"Encryption Rules: \n1. The data entered must not start with 0."
            <<"\n2.The data entered must have 4 digits. No more. No less."
            <<"\n3. All digits within the data entered must be in the range from 0 to 7.\n\n";
    cout<<"Enter four-digit data to encrypt: ";
    cin>>dt;
    
    //Validate Data
    isVld=vldt(dt);
    if (isVld) {
        tdt=dt;
        
        for(short i=1;i<=4;i++) {
            pVal=tdt%10; //get original value 
            pVal=(pVal+5)%8; //modify place value
            //swap number place
            switch(i) {
                case 1: { nP=100; break; }
                case 2: { nP=1000; break; }
                case 3: { nP=1; break; }
                default: nP=10; }
            edt+=(pVal*nP); //add to encrypted data
            
            //update number place
            tdt/=10; }
        
        //Validate Again
        
        //Print Data
        cout<<"Original Data: "<<dt<<endl;
        cout<<"Encrypted Data: "<<edt<<endl<<endl;
    }
    
    else {
        //Placeholder
        cout<<"Cannot Encrypt Data. Sending back to Main Menu...\n\n"; }
}

void decrypt() {
    //Declare Variables
    bool isVld;
    short dt=0; //inputed data
    short ddt=0; //decrypted data
    short nP=1; //number place
    short tdt=0; //temporary data
    short pVal=0; //place value
    
    //Map Input and Process
    cout<<"Decryption Rules: \n1. The data entered must not start with 0."
            <<"\n2.The data entered must have 4 digits. No more. No less."
            <<"\n3. All digits within the data entered must be in the range from 0 to 7.\n\n";
    cout<<"Enter four-digit data to decrypt: ";
    cin>>dt;
    
    //Validate
    isVld=vldt(dt);
    if (isVld) {
        cout<<"Decrypting...\n";
        tdt=dt;
        
        for(short i=1;i<=4;i++) {
            pVal=tdt%10; //get original value 
            //modify place value
            if(pVal<=4) pVal+=3;
            else pVal-=5;
            //modify number place
            switch(i) {
                case 1: { nP=100; break; }
                case 2: { nP=1000; break; }
                case 3: { nP=1; break; }
                default: nP=10; }
            ddt+=(pVal*nP); //add to encrypted data
            
            //update number place
            tdt/=10; }
        
        //Validate Again
        
        //Print Data
        cout<<"Original Data: "<<dt<<endl;
        cout<<"Decrypted Data: "<<ddt<<endl<<endl;}
    else {
        cout<<"Cannot Decrypt Data. Sending back to Main Menu...\n\n";
    }
}

bool vldt(short inp) {
    //Declare and Initialize variables
    short tempP=0; //Stores temporary place value
    
    //Processing Data -- Validate 4 digits are entered and all are from 0-7
    for(short i=1; i<=4; i++) { 
        tempP=inp%10;
        if(tempP>7) { cout<<"There is a digit over 7! "; return false; }
        inp/=10;
        if(inp==0&&i<4) { cout<<"Not enough digits entered! "; return false; }
    }
    
    if (inp>0) { cout<<"Too many digits entered! "; return false; }
    
    return true;
}
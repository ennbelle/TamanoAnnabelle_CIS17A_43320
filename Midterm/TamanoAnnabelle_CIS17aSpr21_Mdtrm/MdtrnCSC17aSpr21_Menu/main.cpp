/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//User Libraries
#include "Cstmr.h"
#include "Emply.h"
#include "Prime.h"
#include "Primes.h"
//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();
//Function Prototypes for Problem 2
float gtMPy(int,float);  //Get Employee's Pay
string getMPyE(float); //Get Employee's Pay in English
//Function Prototypes for Problem 4
bool vldt(short); //validate function
void encrypt(); //encrypt function
void decrypt(); //decrypt function
//Function Prototypes for Problem 7
Primes factor(int); //Input an integer, return all prime factors
void prntPrm(const Primes); //Output all prime factors
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}

//******************************************************************************
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl<<endl;
}

//******************************************************************************
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
void prblm1(){
    cout<<"Problem 1: Check Account Balance."<<endl;
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
    cin.ignore();
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
    

    //Calculate New Balance and Print
    newBlnc=static_cast<int>(c1->blnc);
    newBlnc+=(ttD-ttC);
    if(newBlnc<0) { 
        cout<<"WARNING: A $20 fee has been taken from your account for overdrawing from balance!"<<endl;
        newBlnc-=20; }
    cout<<"New Balance: $"<<newBlnc<<endl;
    
    
    //Clean Up & Exit Function
    delete c1;
}

//******************************************************************************
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
void prblm2(){
    cout<<"Problem 2: Write Employee Checks."<<endl;
    cout<<"Be prepared to fill out information and sign checks..."<<endl;
      
    //Declare Variables
    string coName; //Company Name
    string coAdd;   //Company Address
    string sig;     //Holds Signature
    int empNum;     //Number of Employees
    
    //Find Company Information
    cin.ignore();
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
    
    
}

//******************************************************************************
//                         Problem 2 - get Pay function
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
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

//******************************************************************************
//                         Problem 2 - get Pay (in English) function
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
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

//******************************************************************************
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
void prblm3(){
    cout<<"Problem 3: Outputting Mean, Median, and Modes."<<endl;
    cout<<"This problem can be found in the \'Mdtrm_P3\' project folder!"<<endl<<endl;
}

//******************************************************************************
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
void prblm4(){
    cout<<"Problem 4: Encrypt/Decrypt Telephone Data"<<endl;
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
    
}

//******************************************************************************
//                         Problem 4 - Validate Function
//Input:  -> Parameters in Argument List, Description/Range/Units
//          short inp = input from encrypt or decrypt function
//Output: -> Return, Description/Range/Units
//          bool isVld = true/false on whether input is valid
//******************************************************************************
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

//******************************************************************************
//                         Problem 4 - Encrypt Function
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
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

//******************************************************************************
//                         Problem 4 - Decrypt Function
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
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

//******************************************************************************
//                         Problem 5
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
void prblm5(){
    cout<<"Problem 5: Finding largest n Where n!=factorial can be calculated BEFORE overflow."<<endl;
    cout<<"A.) Using a byte variable, largest n = 5."<<endl;
    cout<<"B.) Unsigned short, largest n = 7,"<<endl
            <<"    Short, largest n = 7"<<endl
            <<"    Unsigned int, largest n = 12"<<endl
            <<"    Int, largest n = 12"<<endl
            <<"    Long, largest n = 20"<<endl
            <<"    Float, largest n = 2147483647"<<endl
            <<"    Double, largest n = 2147483647"<<endl<<endl;
}

//******************************************************************************
//                         Problem 6
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
void prblm6(){
    cout<<"Problem 6: Converting Bases"<<endl;
    cout<<"A.) Convert the following from decimal to binary, octal, and hex."<<endl
            <<"    i. Decimal = 2.875"<<endl
            <<"       Binary = 0010.1110"<<endl
            <<"       Octal = 2.7"<<endl
            <<"       Hexadecimal = 2.E"<<endl
            <<"       NASA Format = 5C000002"<<endl
            <<"    ii.Decimal = 0.1796875"<<endl
            <<"       Binary = 0.00101110"<<endl
            <<"       Octal = 0.134"<<endl
            <<"       Hexadecimal = 0.2E"<<endl
            <<"       NASA Format = 5C0000FE"<<endl;
    cout<<"B.) Converting the following negative values from decimal to binary, octal, and hex."<<endl
            <<"    i. Decimal = -2.875"<<endl
            <<"       Binary = 1101.0010"<<endl
            <<"       Octal = 15.1"<<endl
            <<"       Hexadecimal = D.2"<<endl
            <<"       NASA Format = A4000002"<<endl
            <<"    ii.Decimal = -0.1796875"<<endl
            <<"       Binary = 1111.11010010"<<endl
            <<"       Octal = 7.644"<<endl
            <<"       Hexadecimal = F.D2"<<endl
            <<"       NASA Format = A40000FE"<<endl;
    cout<<"C.) Convert the float representations of the following into the decimal number."<<endl
            <<"    i. NASA Format = 59999901"<<endl
            <<"       Decimal = 1.4"<<endl
            <<"    ii.NASA Format = 59999902"<<endl
            <<"       Decimal = 2.8"<<endl
            <<"    iii. NASA Format = A66667FE"<<endl
            <<"       Decimal = -0.175"<<endl<<endl;
}

//******************************************************************************
//                         Problem 7
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
void prblm7(){
    cout<<"problem 7"<<endl;
    int num=0;
    cout<<"This program factors all the primes within a number[2-10000]. "<<endl;
    cout<<"Enter any number between 2 and 10000: ";
    cin>>num;
    //Validate number and Find Primes
    if(num<2||num>10000) cout<<"Cannot calculate primes! Your number is out of range. Goodbye."<<endl<<endl;
    else {
        Primes fct=factor(num);
        
        cout<<num;
        prntPrm(fct);
        cout<<endl<<endl;
    }
}

//******************************************************************************
//                         Problem 7 - Factor Function
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
Primes factor(int n) {
    //Declare Variables
    int ind=0; //factor index
    Primes fctr;
    fctr.nPrimes=0;
    
    //check if n can be factored by 2
    if(n%2==0) {
        fctr.prime[ind].prime=2;
        fctr.prime[ind].power=1;
        n/=2;
        while (n%2==0) {
            fctr.prime[ind].power+=1;
            n/=2;
        }
        ind++;
    }
    
    //Find primes from values 3 onward
    for(int i=3;i<=sqrt(n);i=i+2) {
        if(n%i==0) {
            fctr.prime[ind].prime=i;
            fctr.prime[ind].power=1;
            n/=i;
        }
        while(n%i==0) {
            fctr.prime[ind].power+=1;
            n/=i;
        }
        ind++;
    }
    
    //check if prime is greater than 2
    if(n>2) {
        fctr.prime[ind].prime=n;
        fctr.prime[ind].power=1;
        ind++;
    }
    
    
    fctr.nPrimes=ind;
    
    //Exit Function
    return fctr;
}

//******************************************************************************
//                         Problem 7 - Print Primes Function
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//******************************************************************************
void prntPrm(const Primes fct) {
    cout<<" = ";
    for(unsigned char i=0;i<fct.nPrimes;i++) {
        if(fct.prime[i].prime>0) {
            cout<<fct.prime[i].prime<<"^"<<static_cast<int>(fct.prime[i].power);
            if(i<(fct.nPrimes - 1)) { cout<<" * ";}
        }
    }
}

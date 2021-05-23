/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 15,2021 at 1:26PM
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

//inRange Function: check whether the character of digits is in range of unsigned short data type
//True=within range, False=not within range
bool  inRange(const char dgts[],unsigned short& unShort) {
    unsigned short mulFact=1;
    unsigned short temp=0;
    for(char i=strlen(dgts)-1;i>=0;i--) {
        temp=dgts[i]-48;
        if(temp>9){return false;} //return false if digit is not a number
        unShort+=(temp*mulFact);
        if(unShort/mulFact!=temp) return false; //End function by returning false if mulFact
        mulFact*=10; }
    return true;
}

//Reverse Function: 
bool reverse(unsigned short unShort,signed short& snShort) {
    short rmndr;
    unsigned short place=10000;
    snShort=0;
    while(unShort!=0) {
        rmndr=unShort%10;
        snShort+=(rmndr*place);
        if(snShort*1<0) return false;
        unShort/=10;
        place/=10; }
    return true;
}

//Subtract 999
short subtrct(signed short snShort,int dig) {
    if(snShort<dig) return snShort;
    return snShort - dig; }
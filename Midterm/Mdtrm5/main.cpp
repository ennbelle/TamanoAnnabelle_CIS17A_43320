/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 *
 * Created on April 29, 2021, 1:20 AM
 */

#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    
    // char
    int n=2;
    char fact=1;
    fact*=n;
    while(fact>0) {
        n++;
        fact*=n; }
    cout<<"char max n: "<<n<<endl;
    //Highest before overflow =5
    
    //unsigned short
    n=2;
    unsigned short factUS=1;
    factUS*=n;
    while(factUS!=0) {
        n++;
        factUS*=n; }
    cout<<"unsigned short max n: "<<n<<endl;
    
    //short
    n=2;
    short factS=1;
    factS*=n;
    while (factS>0) {
        n++;
        factS*=n; }
    cout<<"short max n: "<<n<<endl;
    
    //int
    n=2;
    int factI=1;
    factI*=n;
    while (factI>0) {
        n++;
        factI*=n; }
    cout<<"int max n: "<<n<<endl;
    
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Annebelle Tamano
 * Created on June 11, 2021, 2:41 AM
 * Purpose: Driver Program for Random Sequence Class
 */

#include <iostream>
using namespace std;

//User Libraries
#include "Prob1Random.h"

int main(int argc, char** argv) {
    //Declare and Initialize Variables
    char n = 5;
    char rndseq[] = {18, 33, 56, 79, 124};
    int ntimes = 100000;
    Prob1Random a(n, rndseq);

    //Loop 100000 Times
    for (int i = 1; i <= ntimes; i++) {
        a.randFromSet();
    }
    
    //Print Results
    int *x = a.getFreq();
    char *y = a.getSet();
    for (int i = 0; i < n; i++) {
        cout <<y[i]<< " occurred " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getNumRand() << endl;
    return 0;
}


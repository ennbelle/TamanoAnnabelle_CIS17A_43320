/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on June 7, 2021, 2:22 PM
 * Purpose: This program stores all Final Problems
 */

//System Libraries
#include <iostream> //I/O Library
#include <fstream>  //Filestream Library
#include <iomanip>  //Format Library
using namespace std;

//User Libraries
#include "Prob1Random.h" //Problem 1 Random Class
#include "Emply.h"       //Employee Class
#include "Prob2Sort.h"   //Problem 2 - Sorting Class
#include "Prob3TableInherited.h"  //Problem 3 - Inherited Table Class
#include "SvngAcc.h"              //Savings Account CLass

//Global Constant

//Function Prototypes
void p1(); //Problem 1
void p2(); //Problem 2
void p3(); //Problem 3
void p4(); //Problem 4
void p5(); //Problem 5
void p6(); //Problem 6

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed
    
    //Declare and Initialize Variables
    char opt;
    do {
        //Print Main Menu
        cout<<"Main Menu\n"
                <<"#1 Problem 1 - Random Sequence\n"
                <<"#2 Problem 2 - All Kinds of Sorting\n"
                <<"#3 Problem 3 - Spreadsheet Stuff\n"
                <<"#4 Problem 4 - Savings Account Class\n"
                <<"#5 Problem 5 - Employee Class\n"
                <<"#6 Problem 6 - Conversations\n\n"
                <<"Select options 1-6 to view problem (Press any other key to exit)...";
        cin>>opt;
        
        switch(opt) {
            case '1': p1(); break;
            case '2': p2(); break;
            case '3': p3(); break;
            case '4': p4(); break;
            case '5': p5(); break;
            case '6': p6(); break;
            default: cout<<"Goodbye!\n"; }
        
    }while(opt>='1'&&opt<='6');
    
    //Clean Up & Exit Program
    return 0;
}

//******************************************************************************
//      Problem #1 - Random Sequence
//******************************************************************************
void p1() {
    cout<<"Problem 1\n";
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
    cout << "The total number of random numbers is " << a.getNumRand() << endl<<endl;
}

//******************************************************************************
//      Problem #2 - All kinds of sorting
//******************************************************************************
void p2() {
    cout<<"\n\nProblem 2\n";
    //Given Driver 
    cout << "The start of Problem 2, the sorting problem" << endl;
    Prob2Sort<char> rc;
    bool ascending = true;
    ifstream infile;
    infile.open("Problem2.txt", ios::in);
    char *ch2 = new char[10 * 16];
    char *ch2p = ch2;
    while (infile.get(*ch2)) {
        cout << *ch2;
        ch2++;
    }
    infile.close();
    cout << endl;
    cout << "Sorting on which column" << endl;
    int column;
    cin>>column;
    char *zc = rc.sortArray(ch2p, 10, 16, column, ascending);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 16; j++) {
            cout << zc[i * 16 + j];
        }
    }
    
    //Testing on Different File and Different Data Type
    cout<<"\n\nThe start of the sorting problem with integers"<<endl;
    Prob2Sort<int> ic;
    ascending=false;
    infile.open("Prob2Int.txt", ios::in);
    int count=0;
    int *i2=new int[10*16];
    int *i2p = i2;
    while(infile>>*i2) {
        cout<<setw(4)<<*i2;
        i2++;
        count++;
        if(count%16==0) { cout<<endl; }
    }
    infile.close();
    cout << endl;
    cout << "Sorting on which column" << endl;
    cin>>column;
    int *ac=ic.sortArray(i2p,10,16,column, ascending);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 16; j++) {
            cout<<setw(4)<<ac[i * 16 + j];
        }
        cout<<endl;
    }
    cout<<endl;
    
    //Clean Up
    delete []ch2;
    delete []i2;
}

//******************************************************************************
//      Problem #3 - Spreadsheets
//******************************************************************************
void p3() {
    cout<<"Problem 3\n";
    int rows = 5;
    int cols = 6;
    Prob3TableInherited<int> tab("Problem3.txt", rows, cols);
    const int *naugT = tab.getTable();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << naugT[i * cols + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    const int *augT = tab.getAugTable();
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            cout << augT[i * (cols + 1) + j] << " ";
        }
        cout << endl;
    }
    
    cout<<endl<<endl;
}

//******************************************************************************
//      Problem #4 
//******************************************************************************
void p4() {
    cout<<"Problem 4\n";
    SvngAcc mine(-300);

    for (int i=1; i<=10; i++) {
        mine.Transaction((float) (rand() % 500)*(rand() % 3 - 1));
    }
    mine.toString();
    cout << "Balance after 7 years given 10% interest = "
            << mine.Total((float) (0.10), 7) << endl;
    cout << "Balance after 7 years given 10% interest = "
            << mine.TotalRecursive((float) (0.10), 7)
            << " Recursive Calculation " << endl<<endl;
}
//******************************************************************************
//      Problem #5 - Employee Class
//******************************************************************************
void p5() {
    cout<<"Problem 5\n";
    Emply Mark("Mark", "Boss", 215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
            Mark.setHoursWorked(25));
    Mark.toString();

    Emply Mary("Mary", "VP", 50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(60));
    Mary.toString();
    cout<<endl;
     }

//******************************************************************************
//      Problem #6 - Conversions
//******************************************************************************
void p6() {
    cout<<"Problem 6\n";
    cout<<"1) Convert to binary, octal and hex\n"
        <<"   a)  3.75 Base 10 = 3.C Base 16\n"
        <<"                    = 11.1100 Base 2\n"
        <<"                    = 3.6 Base 8\n"
        <<"   b)  0.7 Base 10  = 0.B3 Base 16\n"
        <<"                    = 0.10110011 Base 2\n"
        <<"                    = 0.54631 Base 8\n"
        <<"   c)  89.9 Base 10 = 59.E6 Base 16\n"
        <<"                    = 1011001.11100110 Base 2\n"
        <<"                    = 131.71463 Base 8\n";
    cout<<"2) Convert to NASA Hex float with first 24 bits representing the\n"
        <<"signed fraction and the last 8 bits representing the\n"
        <<"signed exponent. Scaled as 0.FRACTION x 2^EXPONENT\n"
        <<"   a)  3.75 Base 10 = 79999902\n"
        <<"   b)  0.7 Base 10  = 59999900\n"
        <<"   c)  89.9 Base 10 = 59E66607\n";
    cout<<"3) convert a) to scaled integer binary 1 unsigned byte maximum bits,\n"
        <<"   3.75 Base 10 -> 11.11 Base 2 -> \n"
        <<"   convert b) to scaled integer binary 2 unsigned byte maximum bits,\n"
        <<"   0.7 Base 10 -> 0.10110011 Base 2 -> \n"
        <<"   convert c) to scaled integer binary 3 unsigned byte maximum bits,\n"
        <<"   89.9 Base 10 -> 1011001.11100110 Base 2 -> \n"; 
    cout<<"4) multiply 3) by 1 byte value 7 then shift back to integer and output the result\n"
        <<"   a)  3.75 Base 10 -> 11.11 Base 2 -> \n"
        <<"   b)  0.7 Base 10 -> 11.11 Base 2 -> \n"
        <<"   c)  89.9 Base 10 -> 11.11 Base 2 -> \n";
    cout<<"5) Then convert using IEEE 754 format\n"
        <<"   a)  3.75 Base 10 = 40700000\n"
        <<"   b)  0.7 Base 10  = 3F333333\n"
        <<"   c)  89.9 Base 10 = 42B3CCCD";
    cout<<endl<<endl;
}
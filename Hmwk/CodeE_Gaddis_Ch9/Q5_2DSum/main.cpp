/* 
 * File:   main.cpp
 * Author: Annabelle
 * Created on March 25, 2021, 1:01 PM
 * Purpose: Calculate the Grand Sum of the entire 2-D array
 */

//System Libraries
#include <iostream> // I/O Library
#include <iomanip>  //Format  Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays

// Function Prototypes
int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

int main(int argc, char** argv) {
    //Declare variables
    int rows,
        cols,
        sm,
        **ary;
    
    //Allocate the 2D Array
    ary=getData(rows,cols);
    prntDat(ary,rows,cols);
    
    //Find sum
    sm=sum(ary,rows,cols);
    cout<<sm;
    
    //Exit Program -- Clean Up
    destroy(ary,rows,cols);
    return 0;
}

//getData Function: Fill 2D Array
int **getData(int& row,int& col) {
    //Get row and col
    cin>>row>>col;
    //Allocate row pointers
    int **array=new int*[row];
    //Allocate each row with the same size columns
    for(unsigned char r=0;r<row;r++) {
        array[r]=new int[col]; }
    //Fill array
    for(unsigned char r=0;r<row;r++) {
        for(unsigned char c=0;c<col;c++) {
            cin>>*(*(array+r)+c); }
    }
    //Exit Function
    return array;
}

//prntDat function
void prntDat(const int* const *arr,int row,int col) {
    for(unsigned char r=0;r<row;r++) {
        for(unsigned char c=0;c<col;c++) {
            cout<<arr[r][c];
            if(c<(col-1)) cout<<" "; }
        cout<<endl;
    }
}

//sum Function
int sum(const int * const *arr, int row,int col) {
    //Declare local variable needed
    int sum=0; //Holds sum
    //Traverse 2D array and calculate sum;
    for(unsigned char r=0;r<row;r++) {
        for(unsigned char c=0;c<col;c++) {
            sum+=arr[r][c]; }
    }
    //Return sum
    return sum;
}

//destroy Function: deallocates memory
void destroy(int **ary,int row,int col) {
    //Deallocate each row
    for(unsigned char r=0;r<row;r++) {
        delete [] ary[r]; }
    //Deallocate the row pointers
    delete [] ary;
}
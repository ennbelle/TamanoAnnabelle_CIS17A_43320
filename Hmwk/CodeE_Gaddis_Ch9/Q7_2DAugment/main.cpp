/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 28, 2021, 2:07 PM
 * Purpose: Create an array 1 row and 1 col largest than copy
 */

//System Libraries
#include <iostream> // I/O Library
using namespace std;

// User Libraries

// Global Constants
// Math, Science, Universal, Conversions, High Dimensioned Arrays

// Function Prototypes
int **getData(int &,int &);//Get the Matrix Data
void prntDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    int **array,
            rows,
            cols;
    //Get Data to fill 2D array
    array=getData(rows,cols);
    //Augment Array
    int **augAry=augment(array,rows,cols);
    //Print both arrays
    prntDat(array,rows,cols);
    cout<<endl;
    prntDat(augAry,rows+1,cols+1);
    //Exit Program
    delete [] array;
    delete [] augAry;
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
        if(r<(row-1)) cout<<endl;
    }
}

//augment Function
int **augment(const int * const *arr,int row,int col) {
    //Allocate row pointers
    int **augAry=new int*[row+1];
    //Allocate each row with same sized columns
    for(unsigned char r=0;r<=row;r++) {
        augAry[r]=new int[col+1]; }
    //Fill array
    for(unsigned char c=0;c<=col;c++) {
        augAry[0][c]=0; }
    for(unsigned char r=1;r<=row;r++) {
        augAry[r][0]=0;
        for(unsigned char c=1;c<=col;c++){
            augAry[r][c]=arr[r-1][c-1]; }
    }
    return augAry;
}
//destroy Function: deallocates memory
void destroy(int **ary,int row,int col) {
    //Deallocate each row
    for(unsigned char r=0;r<row;r++) {
        delete [] ary[r]; }
    //Deallocate the row pointers
    delete [] ary;
}
/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 14,2021 at 1:11 PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

//Read Function
void read(int arr[][COLMAX],int& row,int& col) {
    cout<<"Input a table and output the Augment row,col and total sums."<<endl;
    cout<<"First input the number of rows and cols. <20 for each"<<endl;
    cin>>row>>col;
    cout<<"Now input the table."<<endl;    
    for(unsigned char r=0;r<row;r++) {
        for(unsigned char c=0;c<col;c++) {
            cin>>arr[r][c]; }
    }
}

//Sum Function
void sum(const int arr[][COLMAX],int row,int col,int augArr[][COLMAX]) {
    for(unsigned char r=0;r<row;r++) {
        for(unsigned char c=0;c<col;c++) {
            augArr[r][c]=arr[r][c];
            augArr[r][col]+=arr[r][c];
            augArr[row][c]+=arr[r][c];}
        augArr[row][col]+=augArr[r][col];
    }
}

//Print Function
void print(const int arr[][COLMAX],int row,int col,int w) {
    for(unsigned char r=0;r<row;r++) {
        for(unsigned char c=0;c<col;c++) {
            cout<<setw(w)<<arr[r][c]; }
        cout<<endl; }
}
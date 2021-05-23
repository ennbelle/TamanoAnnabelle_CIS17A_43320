/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 13,2021 at 7:12 PM
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

//Read Function
int read(char arr[][COLMAX],int& rowIn) {
    int maxCol=0;
    unsigned char i=0;
    unsigned char row=0;
//    for(unsigned char i=0;i<rowIn;i++) {
//        cin>>arr[i];
//        if(strlen(arr[i])>maxCol) {
//            maxCol=strlen(arr[i]); }
//    }
//    
    while(cin>>arr[i]) {
        i++;
        row++;
        if(strlen(arr[i])>maxCol) maxCol=strlen(arr[i]);
    }
    
    if(rowIn!=row)rowIn==row;
        
    return maxCol;
}

//Sort Function - Sorts through using selection sort algorithm
void sort(char arr[][COLMAX],int row, int col) {
    const int size=COLMAX;
    char temp[size];
    unsigned char minPos;
    char minVal[size];
    for(unsigned char i=0;i<row;i++) {
        minPos=i;
        strcpy(minVal,arr[i]);
        for(unsigned char j=i+1;j<row;j++) {
        if(strcmp(arr[i],arr[j])>0) {
            minPos=j;
            strcpy(minVal,arr[j]);
            strcpy(temp,arr[i]);
            strcpy(arr[i],arr[j]);
            strcpy(arr[j],temp); }
        }
    }
}

//Print Function
void print(const char arr[][COLMAX],int row,int col) {
    for(unsigned char i=0;i<row;i++) {
        cout<<arr[i]<<endl;
    }
}
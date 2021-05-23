/* 
 * File: main.cpp
 * Author:Annabelle Tamano
 * Created on March 16, 2021 at 2:33PM
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
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
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}

//Read Function
int read(char arr[][COLMAX],int& row) {
    int maxCol=0;
    for(unsigned char i=0;i<row;i++) {
        cin>>arr[i];
        if(strlen(arr[i])>maxCol) {
            maxCol=strlen(arr[i]); }
    }

    return maxCol;
}

//Sort Function - Sorts through using selection sort algorithm
void sort(char arr[][COLMAX],int row,int col,const char replace[],const char with[]) {
    char temp[COLMAX]; //temporary array
    int m; //minimum index
    for(unsigned char i=0;i<row-1;i++) {
        m=i;
        for(unsigned char j=i+1;j<row;j++) {
            if (strcmp(arr[i],arr[j],replace,with)>0) m=j;
        } 
        //swap minimum row
        if(m!=i){
            strcpy(temp,arr[i]);
            strcpy(arr[i],arr[m]);
            strcpy(arr[m],temp); }
        

    }
}

//Print Function
void print(const char arr[][COLMAX],int row,int col) {
    for(unsigned char i=0;i<row;i++) {
        cout<<arr[i]<<endl;
    }
}

//STRCMP FUNCTION
int strcmp(char a[],char b[],const char replace[],const char with[]) {
    char aCopy[COLMAX];
    char bCopy[COLMAX];
    
    //Copy arrays a and b into different arrays
    for(unsigned char i=0;aCopy[i]=='\0';i++) {
        aCopy[i]=a[i]; }
    for(unsigned char i=0;i<bCopy[i]=='\0';i++) {
        bCopy[i]=b[i]; }
    
    //go through first array and replace
    for(unsigned char i=0;i<strlen(aCopy);i++) {
        for(unsigned char j=0;j<strlen(replace)&&aCopy[i]==replace[j];j++) {
            if(aCopy[i]==replace[j]) aCopy[i]=with[j]; }
    }
    
    //go through second array and replace
    for(unsigned char i=0;i<strlen(bCopy);i++) {
        for(unsigned char j=0;j<strlen(replace)&&bCopy[i]==replace[j];j++) {
            if(bCopy[i]==replace[j]) bCopy[i]=with[j]; }
    }
    
    //return
    return strcmp(aCopy,bCopy);
}

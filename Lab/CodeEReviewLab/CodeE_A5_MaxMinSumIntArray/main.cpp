/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 13,2021 at 8:14 PM
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

//Read Function
void read(int arr[],int sz) {
    for(unsigned char i=0;i<sz;i++) {
        cin>>arr[i]; }
}

//Stat Function: Finds the sum, the min, and the max of the function
int  stat(const int arr[],int sz,int& max,int& min) {
    int sum=0;
    max=arr[0];
    min=arr[0];
    for(unsigned char i=0;i<sz;i++) {
        sum+=arr[i];
        if(max<arr[i]) {max=arr[i];}
        if(min>arr[i]) {min=arr[i];}
    }
    return sum;
}

//Print Function - Prints Out all the content
void print(const int arr[],int sz,int sum,int max,int min) {
    for(unsigned char i=0;i<sz;i++) {
        cout<<"a["<<static_cast<int>(i)<<"] = "<<arr[i]<<endl;
    }
    cout<<"Min  = "<<min<<endl
    <<"Max  = "<<max<<endl
    <<"Sum  = "<<sum<<endl;
}
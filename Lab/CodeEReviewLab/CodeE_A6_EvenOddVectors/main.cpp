/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on March 14,2021 at 12:05PM
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

//Read Function: Read in both vectors
void read(vector<int>& even, vector<int>& odd) {
    unsigned short amt;
    int temp;
    cout<<"Input the number of integers to input."<<endl;
    cin>>amt;
    cout<<"Input each number."<<endl;
    for(unsigned char i=0;i<amt;i++) {
        cin>>temp;
        if(temp%2) odd.push_back(temp); 
        else even.push_back(temp); }
}

//Copy Function: Copies Vectors into Array
void copy(vector<int> even, vector<int> odd,int arr[][COLMAX]) {
    for(unsigned char i=0;i<even.size();i++) {
        arr[i][0]=even[i]; }
    
    for(unsigned char i=0;i<odd.size();i++) {
        arr[i][1]=odd[i]; }
}

//Print Vector Function
void prntVec(vector<int> even, vector<int> odd,int w) {
    unsigned char mxRow;
    if(even.size()>odd.size()) mxRow=even.size();
    else mxRow=odd.size();
    cout<<setw(w)<<"Vector"<<setw(w)<<"Even"<<setw(w)<<"Odd"<<endl;
    for(unsigned char i=0;i<mxRow;i++) {
        cout<<setw(w)<<" ";
        //Print evens
        if(i<even.size()) cout<<setw(w)<<even[i];
        else cout<<setw(w)<<" ";
        //Print odds
        if(i<odd.size()) cout<<setw(w)<<odd[i];
        else cout<<setw(w)<<" ";
        cout<<endl;
    }
}

//Print Array Function
void prntAry(const int arr[][COLMAX],int evensz,int oddsz,int w){
    unsigned char mxRow;
    if(evensz>oddsz) mxRow=evensz;
    else mxRow=oddsz;
    
    cout<<setw(w)<<"Vector"<<setw(w)<<"Even"<<setw(w)<<"Odd"<<endl;
    for(unsigned char i=0;i<mxRow;i++) {
        cout<<setw(w)<<" ";
        //Print evens
        if(i<evensz) cout<<setw(w)<<arr[i][0];
        else cout<<setw(w)<<" ";
        //Print odds
        if(i<oddsz) cout<<setw(w)<<arr[i][1];
        else cout<<setw(w)<<" ";
        cout<<endl;
    }
}

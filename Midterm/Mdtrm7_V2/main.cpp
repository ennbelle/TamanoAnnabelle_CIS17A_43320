#include <iostream>
#include <cmath>
using namespace std;
  
// A function to print all prime 
// factors of a given number n 
//void primeFactors(int n) 
//{ 
//    // Print the number of 2s that divide n 
//    while (n % 2 == 0) 
//    { 
//        cout << 2 << " "; 
//        n = n/2; 
//    } 
//  
//    // n must be odd at this point. So we can skip 
//    // one element (Note i = i +2) 
//    for (int i = 3; i <= sqrt(n); i = i + 2) 
//    { 
//        // While i divides n, print i and divide n 
//        while (n % i == 0) 
//        { 
//            cout << i << " "; 
//            n = n/i; 
//        } 
//    } 
//  
//    // This condition is to handle the case when n 
//    // is a prime number greater than 2 
//    if (n > 2) 
//        cout << n << " "; 
//} 

int **factor(int n, int& sz) {
    //Allocate memory
    int **fctr=new int*[100];
    for(int i=0;i<100;i++) {
        int *fctr=new int[2];
    }
    int pind=0; //prime index
    
    //Factor 2s if present
    if(n%2==0) { 
        fctr[pind][0]=2;
        fctr[pind][1]=1;
        n/=2;
        while (n%2==0) {
            fctr[pind][1]=fctr[pind][1]+1;
            n/=2;
        }
        pind++;
    }
    
    //Find primes from values 3 PLUS
    for(int i=3;i<=sqrt(n);i=i+2) {
        if(n%i==0) {
            fctr[pind][0]=i;
            fctr[pind][1]=1;           
        }
        while(n%i==0) {
            fctr[pind][1]=fctr[pind][1]+1;
            n/=i;
        }
        pind++;
    }
    
    if(n>2) {
        fctr[pind][0]=n;
        fctr[pind][1]=1;
    }
    
    sz=pind+1;
    
    //Exit Function
    return fctr;
}

void prntF(int **fct,int n, int sz) {
    cout<<n<<" = ";
    
    for(int i=0;i<sz;i++) {
        cout<<fct[i][0]<<"^"<<fct[i][1];
        if(i<(sz-1)) { cout<<" * "; }
    }
}
/* Driver code */
int main() 
{ 
    int n=0; //number
    int sz=0;
    cout<<"Enter number from 2-10000 to factor: ";
    cin>>n;
    
    int **fct=factor(n,sz);
    prntF(fct,n,sz);
    
    //Clean Up
    for(int i=0;i<100;i++) {
        delete []fct[i];
    }
    delete []fct;
    //Exit
    return 0; 
} 

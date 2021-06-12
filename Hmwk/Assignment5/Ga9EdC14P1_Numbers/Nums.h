/* 
 * File:   Nums.cpp
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 5:58 PM
 * Purpose: stores nums information
 */

#ifndef NUMS_H
#define NUMS_H
using namespace std;

class Nums {
private:
    int num;
    static string ones[10];
    static string teens[10];
    static string tens[10];
    static string hndrd;
    static string thsnd;
    
    
public:
    Nums();
    Nums(int n);
    void setN(int n) { num=n; }
    int getN() { return num; }
    void print();

};

#endif /* NUMS_H */


/* 
 * File:   Prob3Table.h
 * Author: Annabelle Tamano
 * Created on June 11, 2021, 1:52 PM
 * Purpose: Problem 3 Table Class Template
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H
#include <fstream>
using namespace std;
template<class T>
class Prob3Table {
protected:
    int rows; //Number of rows in the table
    int cols; //Number of cols in the table
    T *rowSum; //RowSum array
    T *colSum; //ColSum array
    T *table; //Table array
    T grandTotal; //Grand total
    void calcTable(void); //Calculate all the sums
public:
    Prob3Table(char [], int, int); //Constructor then Destructor

    ~Prob3Table() {
        delete [] table;
        delete [] rowSum;
        delete [] colSum;
    };
    
    const T *getTable(void) {
        return table;
    };

    const T *getRowSum(void) {
        return rowSum;
    };

    const T *getColSum(void) {
        return colSum;
    };

    T getGrandTotal(void) {
        return grandTotal;
    };
};

//Constructor
template <class T>
Prob3Table<T>::Prob3Table(char t[],int r,int c) {
    fstream infile;
    infile.open(t,ios::in);
    table=new T[r*c];
    rowSum=new T[r];
    colSum=new T[c];
    rows=r;
    cols=c;
    grandTotal=0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            infile>>table[i*cols+j];
        }
    }
    
    calcTable();
}

//calcTable Function
template <class T>
void Prob3Table<T>::calcTable() {
    //Initialize variables.
    for(int i = 0; i < rows; i++){
        rowSum[i] = 0;
    }
    for(int i = 0; i < cols; i++){
        colSum[i] = 0;
    }
    
    //Calculate grandTotal and row Sum
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            grandTotal+=table[(i*cols)+j];
            rowSum[i]+=table[(i*cols)+j]; }
    }
    
    //Calculate colSum
    for(int j=0;j<cols;j++) {
        for(int i=0;i<rows;i++) {
            colSum[j]+=table[(i*cols)+j]; }
    }
}

#endif /* PROB3TABLE_H */


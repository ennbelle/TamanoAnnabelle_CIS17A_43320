/* 
 * File:   Prob2Sort.h
 * Author: Annabelle Tamano
 * Created on June 11, 2021, 12:04 PM
 * Purpose: Problem 2 Sort
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H

template<class T>
class Prob2Sort {
private:
    int *index; //Index that is utilized in the sort
public:

    Prob2Sort() {
        index = nullptr;
    }; //Constructor

    ~Prob2Sort() {
        delete []index;
    }; //Deconstructor
    T * sortArray(const T*, int, bool); //Sorts a single column array
    T * sortArray(const T*, int, int, int, bool); //Sorts a 2 dimensional array represented as a 1 dim array
};

template <class T>
T* Prob2Sort<T>::sortArray(const T* arr, int sz, bool asc) {
    //Declare Variables
    T* sortArr=new T[sz];
    for(int i=0;i<sz;i++) {
        sortArr[i]=arr[i]; }
    T temp;
    
    //Sort
    if(asc==true) {
        for(int i=0;i<sz;i++) {
            for(int j=0;j<sz-i-1;i++) {
                if(sortArr[j]>sortArr[j+1]) {
                    temp=sortArr[j];
                    sortArr[j]=sortArr[j+1];
                    sortArr[j+1]=temp; }
            }
        }
    } else {
        for(int i=0;i<sz;i++) {
            for(int j=0;j<sz-i-1;j++) {
                if(sortArr[j]<sortArr[j+1]) {
                    temp=sortArr[j];
                    sortArr[j]=sortArr[j+1];
                    sortArr[j+1]=temp; }
            }
        }
    }
    
    return sortArr;
}

template <class T>
T* Prob2Sort<T>::sortArray(const T* arr, int row,int col,int colSort, bool asc) {
    //Declare Variables
    T* sortArr=new T[row*col];
    for(int i=0;i<(row*col);i++) {
        sortArr[i]=arr[i]; }
    T temp;
    //Sort
    if(asc==true) {
        for(int i=0;i<row;i++) {
            for(int j=0;j<row-i-1;j++) {
                if(sortArr[j*col+colSort]>sortArr[(j+1)*col+colSort]) {
                    temp=sortArr[j*col+colSort];
                    sortArr[j*col+colSort]=sortArr[(j+1)*col+colSort];
                    sortArr[(j+1)*col+colSort]=temp; }
            }
        }
    } else {
        for(int i=0;i<row;i++) {
            for(int j=0;j<row-i-1;j++) {
                if(sortArr[j*col+colSort]<sortArr[(j+1)*col+colSort]) {
                    temp=sortArr[j*col+colSort];
                    sortArr[j*col+colSort]=sortArr[(j+1)*col+colSort];
                    sortArr[(j+1)*col+colSort]=temp; }
            }
        }
    }
    
    return sortArr;
}
#endif /* PROB2SORT_H */


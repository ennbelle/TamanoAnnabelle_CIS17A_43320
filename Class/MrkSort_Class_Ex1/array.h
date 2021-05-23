/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on May 6th, 2021, 2:20 PM
 * Purpose:  Array Class Specification
 */


#ifndef ARRAY_H
#define ARRAY_H

class Array{
    private:
        unsigned short size;//Size of the array
        int *data;          //Dynamic pointer to the data in the array
        void filAray(int);  //Utility function for the Constructor
        
    public:
        Array(int n) {
            filAray(n); }     //The constructor -> initializes the Array
        ~Array() {
            delete []data; }         //Destructor clean up for memory
        void prntAry(int perLine);     //Output the array
        void markSrt();     //Sort the array
};

#endif /* ARRAY_H */

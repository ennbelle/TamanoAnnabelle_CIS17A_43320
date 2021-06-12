/* 
 * File:   Prob1Random.h
 * Author: Annabelle Tamano
 * Created on June 8, 2021, 2:41 AM
 * Purpose: Problem 1 Random Sequence .H File
 */

#ifndef PROB1RANDOM_H
#define PROB1RANDOM_H

class Prob1Random {
private:
    char *set; //The set of numbers to draw random numbers from
    char nset; //The number of variables in the sequence
    int *freq; //Frequency of all the random numbers returned
    int numRand; //The total number of times the random number function is called
public:
    Prob1Random(const char n, const char *seq); //Constructor
    ~Prob1Random(); //Destructor
    char randFromSet(); //Returns a random number from the set
    int *getFreq() const; //Returns the frequency histogram
    char *getSet() const; //Returns the set used
    int getNumRand() const; //Gets the number of times randFromSet has
                                //been called
};

#endif /* PROB1RANDOM_H */


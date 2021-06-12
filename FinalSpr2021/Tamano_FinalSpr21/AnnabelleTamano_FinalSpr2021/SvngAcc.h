/*
 * File:   SvngAcc.h
 * Author: Annabelle Tamano
 * Created on June 11, 2021, 3:38 AM
 * Purpose: Savings Accounts .CPP File
 */


#ifndef SVNGACC_H
#define SVNGACC_H

class SvngAcc {
public:
    SvngAcc(float); //Constructor
    void Transaction(float); //Procedure
    float Total(float = 0, int = 0); //Savings Procedure
    float TotalRecursive(float = 0, int = 0);
    void toString(); //Output Properties
private:
    float Withdraw(float); //Utility Procedure
    float Deposit(float); //Utility Procedure
    float Balance; //Property
    int FreqWithDraw; //Property
    int FreqDeposit; //Property
};

#endif /* SVNGACC_H */


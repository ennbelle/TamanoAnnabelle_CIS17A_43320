/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cstmr.h
 * Author: annat
 *
 * Created on April 27, 2021, 11:49 AM
 */

#ifndef CSTMR_H
#define CSTMR_H

using namespace std;

//User Libraries
struct Cstmr {
    string name;
    string addrss;
    int accNum;    //Account Number
    int blnc;    //Start balance at the beginning of month
    int ttlCh;  //Total of all checks written by customer
    int ttlDep; //Total of all deposits credited to customer this month
};



#endif /* CSTMR_H */


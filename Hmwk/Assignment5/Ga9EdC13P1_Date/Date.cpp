/* 
 * File:   Date.cpp
 * Author: Annabelle Tamano
 * Created on May 12, 2021, 9:31 PM
 */

#include <iostream>
using namespace std;
#include "Date.h"

//Set Default Date
Date::Date() {
    day=0;
    mo=0;
    yr=0; }

//Print Format 1 MM/DD/YYYY
void Date::prntF1() {
    cout<<mo<<"/"<<day<<"/"<<yr; }

//Print Format 2 Month DD, YYYY
void Date::prntF2() {
    moEng();
    cout<<" "<<day<<", "<<yr; }

//Print Format 3 DD Month YYYY
void Date::prntF3() {
    cout<<day<<" ";
    moEng();
    cout<<" "<<yr; }

//Print Month in English
void Date::moEng() {
        switch(mo) {
        case 1: cout<<"January"; break;
        case 2: cout<<"February"; break;
        case 3: cout<<"March"; break;
        case 4: cout<<"April"; break;
        case 5: cout<<"May"; break;
        case 6: cout<<"June"; break;
        case 7:  cout<<"July"; break;
        case 8: cout<<"August"; break;
        case 9: cout<<"September"; break;
        case 10: cout<<"October"; break;
        case 11: cout<<"November"; break;
        default: cout<<"December"; }
}
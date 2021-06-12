/* 
 * File:   NumDays.cpp
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 9:17 PM
 * Purpose: member functions for NumDays Class that stores the number of days an employee works
 */

#include "NumDays.h"

//Default Constructor
NumDays::NumDays() {
    hrs=0;
    days=0.0f; }

//Programmer-Defined Constructor
NumDays::NumDays(int h) {
    hrs=h;
    setDays(); }

//Overloaded + function
NumDays NumDays::operator+(const NumDays &right) {
    NumDays temp;
    temp.hrs=hrs+right.hrs;
    temp.setDays();
    return temp; }

//Overloaded - function
NumDays NumDays::operator-(const NumDays &right) {
    NumDays temp;
    temp.hrs=hrs-right.hrs;
    temp.setDays();
    return temp; }

//Overloaded Prefix ++ function
NumDays NumDays::operator++() {
    ++hrs;
    setDays();
    return *this; }

//Overloaded Postfix ++ function
NumDays NumDays::operator++(int) {
    NumDays temp(hrs);
    hrs++;
    setDays();
    return temp; }

//Overloaded Prefix -- function
NumDays NumDays::operator--() {
    --hrs;
    setDays();
    return *this; }

NumDays NumDays::operator--(int) {
    NumDays temp(hrs);
    hrs--;
    setDays();
    return temp; }
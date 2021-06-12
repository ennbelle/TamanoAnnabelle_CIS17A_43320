/* 
 * File:   Time.cpp
 * Author: Annabelle Tamano
 * Created on May 28, 2021, 1:33 PM
 * Purpose: Time Class
 */

#include "Time.h"

//Default Constructor
Time::Time()  {
    hour=0; 
    min=0; 
    sec=0; }

//Constructor
Time::Time(int h,int m,int s) {
    hour=h;
    min=m;
    sec=s; }


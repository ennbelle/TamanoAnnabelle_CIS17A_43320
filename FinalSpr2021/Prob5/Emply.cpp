/* 
 * File:   Emply.cpp
 * Author: Annabelle Tamano
 * Created on June 8, 2021, 8:21 AM
 * Purpose: Employee Class .CPP File
 */

#include <iostream>
#include <cstring>
using namespace std;

#include "Emply.h"

//Constructor
Emply::Emply(char n[],char j[],float hr) {
    for(int i=0;i<strlen(n);i++) {
        MyName[i]=n[i]; }
    for(int i=0;i<strlen(j);i++) {
        JobTitle[i]=j[i]; }
    setHourlyRate(hr);
    GrossPay=0;
    NetPay=0;
}

float Emply::CalculatePay(float hr, int hw) {
    getNetPay(getGrossPay(hr,hw));
    return NetPay;
}

float Emply::getGrossPay(float hr, int hw) {
    HourlyRate=hr;
    HoursWorked=hw;
    
    if(HoursWorked<40) {
        GrossPay=HourlyRate*HoursWorked;
    }else if(HoursWorked>=40&&HoursWorked<50){
        GrossPay=HourlyRate*40;
        GrossPay+=(HourlyRate*0.5)*(HoursWorked-40);
    }
    else {
        GrossPay=HourlyRate*40;
        GrossPay+=(HourlyRate*1.5)*10;
        GrossPay+=(HourlyRate*2)*(HoursWorked-50);
    }
    
    return GrossPay;
}

float Emply::getNetPay(float g) {
    GrossPay=g;
    NetPay=GrossPay-Tax(GrossPay);
    return NetPay;
}

//toString() Function to Print Results
void Emply::toString() {
    cout<<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl;
    cout<<" Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked
            <<" Gross Pay = "<<GrossPay<<" Net Pay = "<<NetPay<<endl;
}

int Emply::setHoursWorked(int hw) {
    if(hw>0 && hw<84) {
        HoursWorked=hw;
        return HoursWorked;
    }else {
        cout<<"Unacceptable Hours Worked\n";
        return 0; }
}

float Emply::setHourlyRate(float hr) {
    if(hr>0 && hr<200) {
        HourlyRate=hr;
        return HourlyRate;
    }else {
        cout<<"Unacceptable Hourly Rate\n";
        return 0; }
}

double Emply::Tax(float g) {
    GrossPay=g;
    double tax;
    
    if(g<=500) {
        tax=static_cast<double>(GrossPay)*0.1;
    } else {
        tax=static_cast<double>(500)*0.1;
        if(g<500&&g>1000) {
            tax+=static_cast<double>(GrossPay-500)*0.2;
        } else {
            tax+=static_cast<double>(500)*0.2;
            tax+=static_cast<double>(GrossPay-1000)*0.3;
        }
    }
    
    return tax;
}

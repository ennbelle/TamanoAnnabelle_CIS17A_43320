/* 
 * File:   Emply.h
 * Author: Annabelle Tamano
 * Created on June 11, 2021, 8:21 AM
 * Purpose: Employee Class .H File
 */

#ifndef EMPLY_H
#define EMPLY_H

class Emply {
public:
    Emply(char[], char[], float); //Constructor
    float CalculatePay(float, int); //Procedure
    float getGrossPay(float, int); //Procedure
    float getNetPay(float); //Procedure
    void toString(); //Procedure
    int setHoursWorked(int); //Procedure
    float setHourlyRate(float); //Procedure
private:
    double Tax(float); //Utility Procedure
    char MyName[20]; //Property
    char JobTitle[20]; //Property
    float HourlyRate; //Property
    int HoursWorked; //Property
    float GrossPay; //Property
    float NetPay; //Property
};

#endif /* EMPLY_H */


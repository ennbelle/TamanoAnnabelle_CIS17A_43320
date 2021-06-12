/* 
 * File:   Emp.h
 * Author: Annabelle Tamano
 * Created on May 26, 2021, 11:22 AM
 * Purpose: Employee Class Header
 */

#ifndef EMP_H
#define EMP_H
#include <cstring>
using namespace std;

class Emp {
private:
    char* name;    //Name
    int empNum;     //Employee Number
    char* hDate;   //Hire Date
public:
    Emp();
    Emp(char* n,int en, char* hd);
    //Accessor Method
    char* gName() const { return name; }
    int gENum() const { return empNum; }
    char* gHDate() const { return hDate; }
    //Mutator Methods
    void sName(char* n) {
        name=new char[strlen(n)+1];
        strlcpy(name,n,strlen(n)+1); }
    void sENum(int en) { empNum=en; }
    void sHDate(char* hd) { 
        hDate=new char[strlen(hd)+1];
        strlcpy(hDate,hd,strlen(hd)+1); }
    //Clean Up 
    virtual ~Emp() {
        delete []name; delete []hDate;}
};

#endif /* EMP_H */


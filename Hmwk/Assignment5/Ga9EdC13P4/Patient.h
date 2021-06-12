/* 
 * File:   Patient.h
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 11:12 PM
 * Purpose: store patient information
 */

#ifndef PATIENT_H
#define PATIENT_H

using namespace std;

class Patient {
private:
        string fname; //First Name
        string mname; //Middle Name
        string lname;  //Last Name
        string add;    //Address
        string city;   //City
        string stte;  //State
        int zpCode;    //Zip Code
        int fnum;     //Phone Number
        int eFnum;    //Emergency Contact Phone Number
        string eName;  //Emergency Contact Name

    public:
        Patient();
        Patient(string fn,string mn,string ln, string a, string ct, string st,int zc,int f,int ef,string en);
        //Mutator functions
        void setFN(string f) { fname=f; }
        void setMN(string m) { mname=m; }
        void setLN(string l) { lname=l; }
        void setAdd(string a) { add=a; }
        void setCity(string c) { city=c; }
        void setSt(string s) { stte=s; }
        void setZC(int zc) { zpCode=zc; }
        void setFNum(int f) { fnum=f; } 
        void setEN(string e) { eName=e; }
        void setEFN(int e) { eFnum=e; }
        //Accessor functions
        string getFN() { return fname; }
        string getMN() { return mname; }
        string getLN() { return lname; }
        string getAdd() { return add; }
        string getCity() { return city; }
        string getSt() { return stte; }
        int getZC() { return zpCode; }
        int getFNum() { return fnum; }
        string getEN() { return eName; }
        int getEFN() { return eFnum; }
        //Print
        void outp();
};

#endif /* PATIENT_H */


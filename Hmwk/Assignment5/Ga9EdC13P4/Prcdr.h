/* 
 * File:   Prcdr.h
 * Author: Annabelle Tamano
 * Created on May 20, 2021, 1:22 PM
 */
using namespace std;

#ifndef PRCDR_H
#define PRCDR_H

class Prcdr {
    private:
        string pname; //procedure name
        string date; //date
        string prname; //practitioner name
        float charge;
    public:
        Prcdr();
        Prcdr(string pn,string d, string prn, float c);
        //Mutator Methods
        void setPN(string pn) { pname=pn; }
        void setD(string d) { date=d; }
        void setPRN(string prn) { prname=prn; }
        void setC(float c) { charge=c; }
        //Accessor Methods
        string getPN() { return pname; }
        string getD() { return date; }
        string getPRN() { return prname; }
        float getC() { return charge; }
        //Display
        void outp();
};

#endif /* PRCDR_H */


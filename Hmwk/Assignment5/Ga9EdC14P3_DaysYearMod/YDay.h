/* 
 * File:   YDay.h
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 7:50 PM
 * Purpose: Header File for Days in Year Class (YDay)
 */

#ifndef YDAY_H
#define YDAY_H
using namespace std;

class YDay {
private:
    int day;
    bool works;
    static int lmo[12];
    static string moname[12];
public:
    YDay();
    YDay(int d);
    YDay(string m,int d);
    void setD(int d) { day=d; }
    bool getWrks() { return works; }
    int getD() { return day; }
    void print();
    YDay operator++(int);
    YDay operator--(int);
};

#endif /* YDAY_H */


/* 
 * File:   YDay.h
 * Author: Annabelle Tamano
 * Created on May 22, 2021, 6:50 PM
 * Purpose: Header File for Days in Year Class (YDay)
 */

#ifndef YDAY_H
#define YDAY_H
using namespace std;

class YDay {
private:
    int day;
    static int lmo[12];
    static string moname[12];
public:
    YDay();
    YDay(int d);
    void setD(int d) { day=d; }
    int getD() { return day; }
    void print();
};

#endif /* YDAY_H */


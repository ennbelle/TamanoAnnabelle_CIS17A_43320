/* 
 * File:   Circle.h
 * Author: Annabelle Tamano
 * Created on May 23, 2021, 11:07 PM
 * Purpose: Circle Header File
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    float rad;
    static float pi;
public:
    Circle();
    Circle(float r);
    void setRad(float r) { rad=r; }
    float getRad() { return rad; }
    float getArea();
    float getD();
    float getCirc();
};

#endif /* CIRCLE_H */


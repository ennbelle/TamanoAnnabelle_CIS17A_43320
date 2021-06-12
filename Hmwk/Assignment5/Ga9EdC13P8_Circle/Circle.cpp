/* 
 * File:   Circle.cpp
 * Author: Annabelle Tamano
 * 
 * Created on May 23, 2021, 11:07 PM
 */

#include "Circle.h"

//Static Variables
float Circle::pi=3.1415f;

//Default Constructor
Circle::Circle() {
    rad=0.0f;
}

//Programmer-Defined Constructor
Circle::Circle(float r) {
    rad=r; }

//Get Area
float Circle::getArea() {
    float a=0;
    a=pi*rad*rad;
    return a; }

//Get Diameter
float Circle::getD() {
    return 2.0*rad; }

//Get Circumference
float Circle::getCirc() {
    return (2.0*pi*rad); }


/* 
 * File:   User.h
 * Author: Annabelle Tamano
 * Created on May 10, 2021, 3:39 PM
 * Purpose: Stores user information
 */

#ifndef USER_H
#define USER_H

struct User {
    char name[80]; //Name of User
    int mWon;   //Total Money Won
    int gPlyd;    //Games Played
};

#endif /* USER_H */

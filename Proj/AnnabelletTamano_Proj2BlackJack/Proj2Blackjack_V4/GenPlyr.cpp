/* 
 * File:   GenPlyr.cpp
 * Author: Annabelle Tamano
 * Created on June 8, 2021, 8:19 AM
 * Purpose: GenPlyr Class 
 */

#include <ctime>
#include <cstdlib>
#include "Player.h"
using namespace std;

#include "GenPlyr.h"

//Static Variables
char GenPlyr::randNam[35][40] {"Abby","Alana","Amaya","Austin","Azher",
                            "Barris","Billie","Bibby","Brayden","Brando",
                            "Cami","Caster","Cleo","Connie","Crystal",
                            "Damien","Denny","Droso","Duke","Dyson",
                            "Elle","Emia","Enricho","Enzo","Ephri",
                            "Fantasia","Finn","Fiona","Foma","Fuschia",
                            "Gavin","Gemma","George","Giana","Ginny"};

GenPlyr::GenPlyr():Player() {
    bet=0;
    won=0;
}

//generate Player at Random
 void GenPlyr::genPlyr(int rN) {;
     srand(time(0));
     setName(randNam[rN]); 
     bet=rand()%(50-2 + 1) + 2; 
 }



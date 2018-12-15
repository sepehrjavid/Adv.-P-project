//
// Created by sepehr on 12/15/18.
//

#include "classes.h"
#include <ctime>



Dice::Dice(int m):num(m) {
    arr = new int[m];
}

Dice::~Dice() {
    delete arr;
}


void Dice::roll() {
    for (int i = 0; i <num ; ++i) {
    int time=clock();
    time%=6;
    time++;
    arr[i]=time;

}}


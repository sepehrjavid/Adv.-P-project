//
// Created by sepehr on 1/7/19.
//

#include "classes.h"


Time::Time(int interval):interval(interval) {}


bool Time::check_time() {
    double diff = difftime(stop, start);
    if (diff > interval){
        return true;
    }
    return false;
}

void Time::time_start() {
    start = time(0);
}


void Time::time_stop() {
    stop = time(0);
}


void Time::reset() {
    start = time(0);
    stop  = time(0);
}
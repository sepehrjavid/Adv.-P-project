#pragma once

#include <sstream>
#include <iostream>
#include <string>



int str_to_int(std::string str){
    std::stringstream sout;
    sout << str;
    int n;
    sout >> n;
    return n;
}


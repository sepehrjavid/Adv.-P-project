#pragma once


#include <sstream>
#include <iostream>
#include <string>



static int str_to_int(std::string str){
    std::stringstream sout;
    sout << str;
    int n;
    sout >> n;
    return n;
}


static void fill_char(char target[], std::string source){
    int i;
    for (i=0;i<source.size();i++){
        target[i] = source[i];
    }
    target[i] = '\0';
}

//
// Created by sepehr on 1/2/19.
//
#pragma once

#ifndef CPP_JAVA_GAME_ENGIN_EXCEPTIONS_H
#define CPP_JAVA_GAME_ENGIN_EXCEPTIONS_H

#include <exception>
#include <iostream>

class InvalidMoveException:public std::exception{
    const std::string message = "invalidmove";
public:
    const char *what() const throw() {
        return message.c_str();
    }
};


class NoBeadInThisAreaException:public std::exception{
    const std::string message = "nobeadinselectedarea";
public:
    const char *what() const throw() {
        return message.c_str();
    }
};


class MethodHasToBeDefinedException:public std::exception{
    const std::string message = "this function should be defined by you and is virtual";
public:
    const char *what() const throw() {
        return message.c_str();
    }
};

#endif //CPP_JAVA_GAME_ENGIN_EXCEPTIONS_H



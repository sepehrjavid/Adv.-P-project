//
// Created by sepehr on 12/15/18.
//
#pragma once

#ifndef CPP_JAVA_GAME_ENGIN_CLASSES_H
#define CPP_JAVA_GAME_ENGIN_CLASSES_H

#endif //CPP_JAVA_GAME_ENGIN_CLASSES_H

#include <iostream>
#include <vector>


enum COLOR{
    RED,
    BLUE,
    GREEEN,
    BALCK,
    WHITE,
    YELLOW,
    PINK,
    SILVER,
    NONE
};

class Player;
class Mohre;




class Dice{
    int* arr;
    int num;
public:
    Dice(int m);
    Dice(){};
    void roll();
    ~Dice();
};


class Board{
    const int length, width;
    std::vector<char> board_game;
    std::vector<Mohre*> elemenets;
public:
    Board(const int len,const  int wid):length(len), width(wid) {};
};




class Game{
    std::vector<Player*> players;
    bool has_dice;
    Dice dice;
    Board board;
public:
    void add_player(std::string name, std::string ident = "", COLOR cl = NONE);
    void start();
    virtual int check_winner(){
        throw std::exception();
    };                                      //returns the index of of the winner player in the players vector
};


class Player final{                        //the player class cannot be inherited
    COLOR color;
    std::string identifier;             //the type of the bead the player might be using
    std::string name;
    int score;
public:
    std::vector<Mohre*> mohre;
    Player(COLOR cl, std::string name);
    Player(std::string ident, std::string name);
    Player(std::string name, std::string ident, COLOR cl);
};


class Mohre{
    std::string shape;
    COLOR color;
    char x, y;
public:
    virtual void move(Board &board, char destination){
        throw std::exception();
    };
};



class Time{

};


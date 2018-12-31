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
    SILVER
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
    int length, width;
    std::vector<Mohre> elemenets;
public:
    Board(int len, int wid){};
};




class Game{
    std::vector<Player> players;
    bool has_dice;
    Dice dice;
    Board board;
public:
    Game(int blen, int bwid, bool has_dice, int dice_number = 0) = 0;
    Player& get_turn();
    void add_player();
    void start();
    int check_winner() = 0;        //returns the index of of the winner player in the players vector
};


class Player{
    COLOR color;
    std::string identifier;             //the type of the bead the player might be using
    std::vector<Mohre> mohre;
    std::string name;
    int score;
    Player(COLOR cl, std::string name);
    Player(std::string ident, std::string name);
};


class Mohre{
    std::string shape;
    COLOR color;
    Mohre(COLOR cl);
    Mohre(std::string shape);
    Mohre(COLOR cl, std::string shape);
    void move(Board &board) = 0;
};


class Time{

};
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
    YELLOW
};

class Player;
class Mohre;




class Dice{
    int* arr;
    int num;
public:
    Dice(int m);
    void roll();
    ~Dice();
};


class Board{
    int length, width;
    std::vector<Mohre> elemenets;
public:
    Board(int len, int wid);
};




class Game{
    std::vector<Player> players;
    bool has_dice;
    Dice dice;
    Board board;
public:
    Game(int blen, int bwid, bool has_dice, int dice_number = 0);
    Player& get_turn();
    void add_player();
};


class Player{
    COLOR color;
    std::vector<Mohre> mohre;
    std::string name;
    int score;
};


class Mohre{

};


class Time{

};
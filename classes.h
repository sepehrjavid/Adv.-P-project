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
class Dice;
class Board;
class Mohre;

class Game{
    std::vector<Player> players;
    bool has_dice;
    Dice* dice;
    Board board;
public:
    Player& get_turn();
};


class Player{
    COLOR color;
    std::vector<Mohre> mohre;
};

template <int m>
class Dice{

};


class Board{
    int length, width;
    std::vector<Mohre> elemenets;
public:
    Board(int len, int wid);
};


class Mohre{

};
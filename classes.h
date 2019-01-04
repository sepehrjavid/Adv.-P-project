//
// Created by sepehr on 12/15/18.
//
#pragma once

#ifndef CPP_JAVA_GAME_ENGIN_CLASSES_H
#define CPP_JAVA_GAME_ENGIN_CLASSES_H

//#include "helperfunctions.h"
#include <iostream>
#include <vector>
#include "Exceptions.h"

enum COLOR{
    RED,
    BLUE,
    GREEEN,
    BALCK,
    WHITE,
    YELLOW,
    PINK,
    SILVER,
    NONe
};


enum BRAIN_TYPE{
    HUMAN, CPU
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




class Board {
    const int length, width;
    char **game_board;
    std::vector<Mohre *> elemenets;
public:
    Board(int len = 0, int wid = 0) : length(len), width(wid) {
//        game_board = new char *[len][wid];
            game_board = new char*[wid];
    };
    //void initialize_the_beads();
};


class Game{
    std::vector<Player*> players;
    bool has_dice;
    Dice dice;
    Board board;
    bool score_dependant;
public:
    void add_player(std::string name, std::string ident = "", COLOR cl = NONe);
    void start();
    virtual Player* get_turn(Player* current_turn){
        MethodHasToBeDefinedException b;
        throw b;
    };
    virtual int check_winner(){
        MethodHasToBeDefinedException b;
        throw b;
    };                                      //returns the index of of the winner player in the players vector
                                            //if there are no winners yet, it returns -1
    virtual bool check_draw(){
        MethodHasToBeDefinedException b;
        throw b;
    }
};



class Player{                        //the player class cannot be inherited
    COLOR color;
    std::string identifier;             //the type of the bead the player might be using
    std::string name;
    int score;
    std::vector<Mohre*> mohre;
    BRAIN_TYPE brain;
public:
    Player(COLOR cl, std::string name);
    Player(std::string ident, std::string name);
    Player(std::string name, std::string ident, COLOR cl);
    int choose_mohre();
    void ask_for_move_and_move(Mohre& target);
    std::vector<Mohre*>& get_beads();
    std::string get_name();
    void make_human();
    void make_cpu();
    BRAIN_TYPE get_brain();
    virtual void think_and_move(){
        MethodHasToBeDefinedException b;
        throw b;
    };
};


class Mohre{
    std::string shape;
    COLOR color;
    int x, y;
public:
    virtual void move(int xdest, int ydest) {//throw(InvalidMoveException) {
        MethodHasToBeDefinedException b;
        throw b;
    };
    int get_x();
    int get_y();
};


class Time{

};



#endif //CPP_JAVA_GAME_ENGIN_CLASSES_H


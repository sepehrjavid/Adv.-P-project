//
// Created by sepehr on 12/15/18.
//
#pragma once

#ifndef CPP_JAVA_GAME_ENGIN_CLASSES_H
#define CPP_JAVA_GAME_ENGIN_CLASSES_H

#include <iostream>
#include <vector>
#include <ctime>
#include "Exceptions.h"

enum COLOR {
    RED,
    BLUE,
    GREEN,
    BLACK,
    WHITE,
    YELLOW,
    PINK,
    SILVER,
    NONe
};


enum OPERATION{
    COLOR_CHANGE,
    MOVE,
    REMOVE,
    ADD
};


enum BRAIN_TYPE {
    HUMAN, CPU
};


class Player;


class Time {
    int interval;    //the interval should be in seconds
    time_t start, stop;
public:
    Time() {};

    Time(int interval);

    void time_start();

    void time_stop();

    bool check_time();        //return true if the difference is more than interval and returns false if less than or equal

    void reset();
};


class Mohre;

class Dice {
    int *arr;
    int num;
public:
    Dice(int m);

    Dice() {};

    void roll();

    ~Dice();
};


class Board {
protected:
    const int length, width;
    char **game_board;
    std::vector<Mohre *> elemenets;
public:
    Board(int len = 0, int wid = 0) : length(len), width(wid) {
//        game_board = new char *[len][wid];
        game_board = new char *[wid];
    };
};


class PreviousMove;


class Game {
protected:
    std::vector<Player *> players;
    bool has_dice = false;
    Dice dice;
    Board board;
    bool time_dependant = false;
    Time time;
    std::vector<PreviousMove*> moves;
public:
    void add_player(std::string name, std::string ident = "", COLOR cl = NONe, BRAIN_TYPE brain = HUMAN);

    void start(bool has_identifier);

    virtual Player *get_turn(Player *current_turn) {
        MethodHasToBeDefinedException b;
        throw b;
    };

    virtual int check_winner(Player *current_player) {
        MethodHasToBeDefinedException b;
        throw b;
    };                                      //returns the index of of the winner player in the players vector
    //if there are no winners yet, it returns -1
    virtual bool check_done() {
        MethodHasToBeDefinedException b;
        throw b;
    }

    void Add_time_features(int interval);

    void Remove_time_features();

    void Add_dice_feature(int number_of_dices);

    void Remove_dice_feature();

    void player_init(int socket);

    void Send_Board_Update(int socket, int old_size);

    virtual void Board_initialize() {
        MethodHasToBeDefinedException b;
        throw b;
    };

    virtual bool HasLegalMove(Board *board, Dice *dice, Player *target) {
        MethodHasToBeDefinedException b;
        throw b;
    }

    virtual void cpu_think_and_move(Player *cpu_player) {
        MethodHasToBeDefinedException b;
        throw b;
    };
};



class Player final{                           //do not inherit from Player class, it will never be used
protected:
    COLOR color;
    std::string identifier;             //the type of the bead the player might be using
    std::string name;
    int score;
    std::vector<Mohre *> mohre;
    BRAIN_TYPE brain;
public:
    Player(COLOR cl, std::string name);

    Player(std::string ident, std::string name);

    Player(std::string name, std::string ident, COLOR cl);

    int choose_mohre(int UISock);

    void ask_for_move_and_move(int UISock, Mohre &target, Board &board, Dice &dice, std::vector<PreviousMove*> &moves);

    std::vector<Mohre *> &get_beads();

    std::string get_name();

    void make_human();

    void make_cpu();

    BRAIN_TYPE get_brain();

    void Add_Bead(Mohre *bead);

};


class Mohre {
protected:
    std::string shape;
    COLOR color;
    int x, y;
public:
    virtual void move(int xdest, int ydest, Board &board, Mohre &target, Dice &dice, std::vector<PreviousMove*> &moves) {
        MethodHasToBeDefinedException b;
        throw b;
    };

    int get_x();

    int get_y();

    void set_color(COLOR color);

    COLOR get_color();
};


class PreviousMove {
protected:
    Mohre *target;
    int SourceX, SourceY, DestX, DestY;
    OPERATION operation;
public:
    PreviousMove(Mohre *target, int Sourcex, int sourcey, OPERATION operation1, int dx = -1, int dy = -1);

    PreviousMove();

    Mohre* get_target(){
        return target;
    }

    int get_SourceX(){
        return SourceX;
    }

    int get_SourceY(){
        return SourceY;
    }

    int get_DestX(){
        return DestX;
    }

    int get_DestY(){
        return DestY;
    }

    OPERATION get_operation(){
        return operation;
    }
};


#endif //CPP_JAVA_GAME_ENGIN_CLASSES_H


//
// Created by sepehr on 1/1/19.
//

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include "helperfunctions.h"
#include "classes.h"


Player::Player(COLOR cl, std::string name) : color(cl), name(name), score(0), identifier("") {
    brain = CPU;
}


Player::Player(std::string ident, std::string name) : color(NONe), name(name), score(0), identifier(ident) {
    brain = CPU;
}


Player::Player(std::string name, std::string ident, COLOR cl) : color(cl), name(name), score(0), identifier(ident) {
    brain = CPU;
}



void Player::ask_for_move_and_move(int UISock, Mohre &target, Board &board, Dice &dice, std::vector<PreviousMove*> &moves) {
    char message[128];
    recv(UISock, message, 128, 0);               //string format to get ("x y")
    int x, y, flag;
    std::string stmessage(message);
    for (int i = 0; i < stmessage.size(); i++) {
        if (stmessage[i] == ' ') {
            x = str_to_int(stmessage.substr(0, i));
            y = str_to_int(stmessage.substr(i + 1, stmessage.length() - 1));
            break;
        }
    }
    try {
        target.move(x, y, board, target, dice, moves);
    }
    catch (InvalidMoveException e) {
        throw e;
    }
}


int Player::choose_mohre(int UISock) {
    char message[128];
    recv(UISock, message, 128, 0);        //string format to get ("x y")
    int y, x, flag = -1;
    std::string stmessage(message);
    for (int i = 0; i < stmessage.length(); i++) {
        if (stmessage[i] == ' ') {
            x = str_to_int(stmessage.substr(0, i));
            y = str_to_int(stmessage.substr(i + 1, stmessage.length() - 1));
            break;
        }
    }
    for (int i = 0; i < mohre.size(); i++) {
        if (mohre[i]->get_y() == y and mohre[i]->get_x() == x) {
            flag = i;
        }
    }
    if (flag == -1) {
        NoBeadInThisAreaException e;
        throw e;
    }
    return flag;
}


std::vector<Mohre *> &Player::get_beads() {
    return this->mohre;
}


std::string Player::get_name() {
    return this->name;
}

void Player::make_human() {
    brain = HUMAN;
}

void Player::make_cpu() {
    brain = CPU;
}


BRAIN_TYPE Player::get_brain() {
    return brain;
}


void Player::Add_Bead(Mohre *bead) {
    mohre.push_back(bead);
}
//
// Created by sepehr on 1/1/19.
//

#include "helperfunctions.h"
#include "classes.h"



Player::Player(COLOR cl, std::string name):color(cl), name(name), score(0), identifier("") {}



Player::Player(std::string ident, std::string name):color(NONe), name(name), score(0), identifier(ident) {}



Player::Player(std::string name, std::string ident, COLOR cl):color(cl), name(name), score(0), identifier(ident) {}


void Player::ask_for_move_and_move(Mohre &target) {
    char message[128] = "beadmov 12 14";
    //TODO socket ask for the selected place to move the bead to
    //string format to get ("beadmov x y")
    int x, y, flag;
    std::string stmessage(message);
    std::string coordinate = stmessage.substr(8, stmessage.length());
    for(int i=0;i<coordinate.size();i++){
        if (coordinate[i] == ' '){
            x = str_to_int(coordinate.substr(0, i));
            y = str_to_int(coordinate.substr(i + 1, coordinate.length() - 1));
            break;
        }
    }
    try {
        target.move(x, y);
    }
    catch (InvalidMoveException e){
        throw e;
    }
}


int Player::choose_mohre() {
    char message[128] = "beadselect 12 14";
    //TODO socket ask for the selected bead
    //string format to get ("beadselect x y")
    int y, x, flag = -1;
    std::string stmessage(message);
    std::string coordinate = stmessage.substr(11, stmessage.length());
    for(int i=0;i<coordinate.length();i++){
        if (coordinate[i] == ' '){
            x = str_to_int(coordinate.substr(0, i));
            y = str_to_int(coordinate.substr(i + 1, coordinate.length() - 1));
            break;
        }
    }
    for (int i = 0;i < mohre.size();i++){
        if (mohre[i]->get_y() == y and mohre[i]->get_x() == x){
            flag = i;
        }
    }
    if (flag == -1){
        //TODO exception throw
    }
    return flag;
}


std::vector<Mohre*>& Player::get_beads() {
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
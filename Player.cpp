//
// Created by sepehr on 1/1/19.
//

#include "classes.h"

Player::Player(COLOR cl, std::string name):color(cl), name(name), score(0), identifier("") {}



Player::Player(std::string ident, std::string name):color(NONE), name(name), score(0), identifier(ident) {}



Player::Player(std::string name, std::string ident, COLOR cl):color(cl), name(name), score(0), identifier(ident) {}
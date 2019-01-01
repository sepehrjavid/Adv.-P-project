//
// Created by sepehr on 12/15/18.
//

#include "classes.h"


void Game::add_player(std::string name, std::string ident, COLOR cl) {
    if (cl == NONE){
        players.push_back(new Player(ident, name));
    }
    if (ident == ""){
        players.push_back(new Player(cl, name));
    }
    else {
        players.push_back(new Player(name, ident, cl));
    }
}


void Game::start() {

}
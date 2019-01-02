//
// Created by sepehr on 12/15/18.
//

#include "classes.h"


void Game::add_player(std::string name, std::string ident, COLOR cl) {
    if (cl == NONe){
        players.push_back(new Player(ident, name));
    }
    if (ident == ""){
        players.push_back(new Player(cl, name));
    }
    else {
        players.push_back(new Player(name, ident, cl));
    }
}


void Game::start() {               //assuming that the board has been initialized and the players are added
    Player* current_player = players[0];
    Mohre* selected_bead;
    int ind;
//    while (true){
//        try{
//            ind = current_player->choose_mohre();
//            selected_bead = current_player->get_beads()[ind];
//        }
//        catch (NoBeadInThisAreaException e) {
//            //TODO inform the UI that there are no beads here
//        }
//        try {
//            current_player->ask_for_move_and_move(selected_bead);
//        }
//        catch (InvalidMoveException e){
//            //TODO send the UI that the move was invalid
//        }

//    }
}



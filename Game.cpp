//
// Created by sepehr on 12/15/18.
//

#include "helperfunctions.h"
#include "classes.h"
#include "Socket.h"



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
    int UI_socket = init_socket();
    int winner_index;
    char char_message[128];
    std::string message;
    Player* current_player = players[0];
    Mohre* selected_bead;
    int ind;
    while (true){
        try{
            ind = current_player->choose_mohre();
            selected_bead = current_player->get_beads()[ind];
        }
        catch (NoBeadInThisAreaException e) {
            message = std::string(e.what());
            fill_char(char_message, message);
            send(UI_socket, char_message, sizeof(char_message), 0);
            continue;
        }
        try {
            current_player->ask_for_move_and_move(*selected_bead);
        }
        catch (InvalidMoveException e){
            message = std::string(e.what());
            fill_char(char_message, message);
            send(UI_socket, char_message, sizeof(char_message), 0);
            continue;
        }
        winner_index = check_winner();
        if (winner_index != -1){
            message = "winner" + players[winner_index]->get_name();
            fill_char(char_message, message);
            send(UI_socket, char_message, sizeof(char_message), 0);
            break;
        }
        current_player = get_turn(current_player);
    }
}



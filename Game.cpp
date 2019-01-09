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



void Game::Add_time_features(int interval) {
    time = Time(interval);
    time_dependant = true;
}



void Game::Remove_time_features() {
    time_dependant = false;
}

void Game::Add_dice_feature(int number_of_dices) {
    has_dice = true;
    dice = Dice(number_of_dices);
}

void Game::Remove_dice_feature() {
    has_dice = false;
}



void Game::start() {               //assuming that the board has been initialized and the players are added
    int UI_socket = init_socket();
    int winner_index;
    char char_message[128];
    std::string message;
    Player* current_player = players[0];
    Mohre* selected_bead;
    PreviousMove last_move;
    int ind;
    while (true){
        if (has_dice == true){
            dice.roll();
        }
        if (time_dependant){
            time.reset();
            time.time_start();
        }
        if (current_player->get_brain() == HUMAN) {
            try {
                ind = current_player->choose_mohre(UI_socket);
                selected_bead = current_player->get_beads()[ind];
            }
            catch (NoBeadInThisAreaException e) {
                message = std::string(e.what());
                fill_char(char_message, message);
                send(UI_socket, char_message, sizeof(char_message), 0);
                continue;
            }
            try {
                last_move = current_player->ask_for_move_and_move(UI_socket, *selected_bead, board, dice, last_move);
            }
            catch (InvalidMoveException e) {
                message = std::string(e.what());
                fill_char(char_message, message);
                send(UI_socket, char_message, sizeof(char_message), 0);
                continue;
            }
        }
        else if(current_player->get_brain() == CPU){
            current_player->think_and_move();
        }
        if (time_dependant){
            time.time_stop();
        }
        winner_index = check_winner(current_player);
        if (winner_index != -1) {
            message = "winner " + players[winner_index]->get_name();
            fill_char(char_message, message);
            send(UI_socket, char_message, sizeof(char_message), 0);
            break;
        }
        if (check_done()){
            message = "draw";
            fill_char(char_message, message);
            send(UI_socket, char_message, sizeof(char_message), 0);
            break;
        }
        current_player = get_turn(current_player);
    }
}


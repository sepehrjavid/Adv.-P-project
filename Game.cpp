//
// Created by sepehr on 12/15/18.
//

#include "helperfunctions.h"
#include "classes.h"
#include "Socket.h"
#include <stdio.h>



void Game::add_player(std::string name, std::string ident, COLOR cl, BRAIN_TYPE brain) {
    if (cl == NONe){
        players.push_back(new Player(ident, name));
    }
    else if (ident == ""){
        players.push_back(new Player(cl, name));
    }
    else {
        players.push_back(new Player(name, ident, cl));
    }
    if (brain == HUMAN) {
        players[players.size() - 1]->make_human();
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


void Game::player_init(int socket, bool has_color, bool has_identifier) {
    char message[2048];
    recv(socket, message, 2048, 0);
    char numb[2];
    int count = 0;
    sscanf(message, "%s", numb);
    if (has_color && has_identifier){                   //"2 player1 color ident player2 color ident 1 cpu1 color ident"
        //for (int )
    }
    else if (has_color){

    }
    else if(has_identifier){

    }
}


void Game::start(bool has_color, bool has_ident) {
    int UI_socket = init_socket();
    player_init(UI_socket, has_color, has_ident);
    Board_initialize();
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
            if (has_dice == true && !current_player->HasLegalMove(&board, &dice)){
                message = "nolegalmove";
                fill_char(char_message, message);
                send(UI_socket, char_message, message.length(), 0);
                continue;
            }
            try {
                ind = current_player->choose_mohre(UI_socket);
                selected_bead = current_player->get_beads()[ind];
            }
            catch (NoBeadInThisAreaException e) {
                message = std::string(e.what());
                fill_char(char_message, message);
                send(UI_socket, char_message, message.length(), 0);
                continue;
            }
            try {
                last_move = current_player->ask_for_move_and_move(UI_socket, *selected_bead, board, dice, last_move);
            }
            catch (InvalidMoveException e) {
                message = std::string(e.what());
                fill_char(char_message, message);
                send(UI_socket, char_message, message.length(), 0);
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
            send(UI_socket, char_message, message.length(), 0);
            break;
        }
        if (check_done()){
            message = "draw";
            fill_char(char_message, message);
            send(UI_socket, char_message, message.length(), 0);
            break;
        }
        current_player = get_turn(current_player);
    }
}


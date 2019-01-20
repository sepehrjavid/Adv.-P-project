//
// Created by sepehr on 12/15/18.
//

#include "helperfunctions.h"
#include "classes.h"
#include "Socket.h"
#include <stdio.h>


COLOR str_to_color(std::string color_name) {
    switch (color_name[0]) {
        case 'r':
            return RED;
        case 'b':
            if (color_name == "black") {
                return BALCK;
            } else {
                return BLUE;
            }
        case 'g':
            return GREEEN;
        case 'w':
            return WHITE;
        case 'y':
            return YELLOW;
        case 'p':
            return PINK;
        case 's':
            return SILVER;
        default:
            break;
    }
    return BALCK;
}


void Game::add_player(std::string name, std::string ident, COLOR cl, BRAIN_TYPE brain) {
    if (cl == NONe) {
        players.push_back(new Player(ident, name));
    } else if (ident == "") {
        players.push_back(new Player(cl, name));
    } else {
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


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"

void Game::player_init(int socket) {
    char message[2048] = "2 sep None blue neg None blue 1 cpu1 Q black";
    recv(socket, message, 2048, 0);
    //"2 player1 color ident player2 color ident 1 color ident" in UI the engin function to send this string should know which field to send None
    char numb = message[0];
    int count, last = 0, player_created = 0, player_numb;
    std::string str_message = std::string(message);
    std::string name, ident;
    COLOR color;
    int times = 0;
    BRAIN_TYPE brain = HUMAN;
    while (times < 2) {
        numb = str_message[0];
        if (numb == '0' && times == 1){
            break;
        }
        player_numb = str_to_int(numb);
        str_message = str_message.substr(2, str_message.length() - 2);
        player_created = 0;
        count = 0;
        for (int i = 0; player_created < player_numb; i++) {
            if (i == str_message.length() || str_message[i] == ' ') {
                if (count == 0) {
                    name = str_message.substr(0, i);
                    last = i + 1;
                    count++;
                    std::cout << name << "\n";
                } else if (count == 1) {
                    ident = str_message.substr(last, i - last);
                    count++;
                    last = i + 1;
                    std::cout << ident << "\n";
                } else if (count == 2) {
                    color = str_to_color(str_message.substr(last, i - last));
                    std::cout << str_message.substr(last, i - last) << "\n";
                    if (i != str_message.length()) {
                        str_message = str_message.substr(i + 1, str_message.length() - i - 1);
                    }
                    i = -1;
                    count = 0;
                    if (ident == "None") {
                        ident = "";
                    }
                    add_player(name, ident, color, brain);
                    player_created++;
                }
            }
        }
        times++;
        brain = CPU;
    }
}

#pragma clang diagnostic pop


void Game::start(bool has_identifier) {
    int UI_socket = init_socket();
    player_init(UI_socket);
    Board_initialize();
    int winner_index;
    char char_message[128];
    std::string message;
    Player *current_player = players[0];
    Mohre *selected_bead;
    PreviousMove last_move;
    int ind;
    while (true) {
        if (has_dice) {
            dice.roll();
        }
        if (time_dependant) {
            time.reset();
            time.time_start();
        }
        if (current_player->get_brain() == HUMAN) {
            if (has_dice && !HasLegalMove(&board, &dice, current_player)) {
                message = "nolegalmove";
                fill_char(char_message, message);
                send(UI_socket, char_message, message.length(), 0);
                continue;
            } else {
                send_ok(UI_socket);
            }
            try {
                ind = current_player->choose_mohre(UI_socket);
                selected_bead = current_player->get_beads()[ind];
                send_ok(UI_socket);
            }
            catch (NoBeadInThisAreaException e) {
                message = std::string(e.what());
                fill_char(char_message, message);
                send(UI_socket, char_message, message.length(), 0);
                continue;
            }
            try {
                last_move = current_player->ask_for_move_and_move(UI_socket, *selected_bead, board, dice, last_move);
                send_ok(UI_socket);
            }
            catch (InvalidMoveException e) {
                message = std::string(e.what());
                fill_char(char_message, message);
                send(UI_socket, char_message, message.length(), 0);
                continue;
            }
        } else if (current_player->get_brain() == CPU) {
            cpu_think_and_move(current_player);
        }
        if (time_dependant) {
            time.time_stop();
        }
        winner_index = check_winner(current_player);
        if (winner_index != -1) {
            message = "winner " + players[winner_index]->get_name();
            fill_char(char_message, message);
            send(UI_socket, char_message, message.length(), 0);
            break;
        }
        if (check_done()) {
            message = "draw";
            fill_char(char_message, message);
            send(UI_socket, char_message, message.length(), 0);
            break;
        }
        current_player = get_turn(current_player);
        message = "nextplayer " + current_player->get_name();
        fill_char(char_message, message);
        send(UI_socket, char_message, message.length(), 0);
    }
}


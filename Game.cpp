//
// Created by sepehr on 12/15/18.
//

#include "classes.h"


Game::Game(int blen, int bwid, bool has_dice, int dice_number):has_dice(has_dice), board(Board(blen, bwid)) {
    if (has_dice){
        dice = Dice(dice_number);
    }

}


void Game::start() {
    std::string name;
    //scanf("%[0-9 a-z A-Z]", name);
    getline(std::cin, name);
    while (true){

    }
}
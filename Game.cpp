//
// Created by sepehr on 12/15/18.
//

#include "classes.h"


Game::Game(int blen, int bwid, bool has_dice, int dice_number):has_dice(has_dice) {
    if (has_dice){
        dice = *(new Dice(dice_number));
    }
    board = *(new Board(blen, bwid));

}
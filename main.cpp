#include <iostream>
#include "classes.h"
#include <unistd.h>

int main() {
    Game g = Game();
    Player pl = Player("sepe", "sep");
    g.add_player("sep", "",BLUE);
    g.start();
    return 0;
}
#include <iostream>
#include "classes.h"
#include <unistd.h>

class Game2 : public Game {
public:
    void Board_initialize() {
        std::cout << "ok" << "\n";
    }
};



int main() {
    Game2 g = Game2();
    g.add_player("sep", "", RED, HUMAN);
    g.start(true);
    return 0;
}
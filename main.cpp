#include <iostream>
#include "classes.h"
#include <unistd.h>

class Game2:public Game{
public:
    void Board_initialize(){
        std::cout<<"ok"<<"\n";
    }
};


int main() {
    Game g = Game();
    Player pl = Player("sepe", "sep");
    g.add_player("sep", "",BLUE);
    g.start(true, false);
    return 0;
}
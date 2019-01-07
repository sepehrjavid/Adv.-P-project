#include <iostream>
#include "classes.h"
#include <unistd.h>

int main() {
    Game g = Game();
    Player pl = Player("sepe", "sep");
    Time t = Time(15);
    t.time_start();
    sleep(15);
    t.time_stop();
    std::cout<<t.check_time()<<std::endl;
    return 0;
}
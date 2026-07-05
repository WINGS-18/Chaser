#include <iostream>
#include <array>
#include "player.h"
#include "enemy.h"
#include "screen.h"

int main() {
    Chaser::Enemy e({5, 6}, 3, 'E');
    Chaser::Player p({6, 5}, 1, 'U');
    Chaser::Screen s;
    //s.screenReset();
    s.insertEntity(e);
    s.insertEntity(p);
    s.printScreen();
    
    return 0;
}
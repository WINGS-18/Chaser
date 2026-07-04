#include <iostream>
#include "player.h"
#include "enemy.h"

int main() {
    Chaser::Enemy e({10, 10}, 3, 'E');
    Chaser::Player p({10, 10}, 1, 'U');
    return 0;
}
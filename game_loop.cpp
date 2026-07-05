#include <chrono>
#include <thread>
#include <conio.h>
#include "game_loop.h"
#include <iostream>
#include <array>
#include "player.h"
#include "enemy.h"
#include "screen.h"

namespace Chaser {

    GameLoop::GameLoop() {}     //constructor defination

    /*milliseconds instance takes in integer*/
    /*sleep_for is a global free function*/

    void GameLoop::sleep(int time) {
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }

    const char GameLoop::keyGiver() {
        if(_kbhit()) {
            return _getch();
        }
        return '\0';
    }

    bool GameLoop::gameEnd(char key) {
        if(key == 'e')  return true;
        return false;
    }

    int GameLoop::startGame() {
        Enemy e({0, 9}, 3, 'E');
        Player p({0, 0}, 1, 'U');
        Screen s;
        int enem = 0;
        char control;

        while(true) {
            //std::cout << "( " << p.p_getX() << ", " << p.p_getY() << " )\n";
            control = keyGiver();
            p.pMovement(control);
            if(enem == e.p_getSpeed()){
                e.eMovement(p);
                enem = 0;
            }
            s.screenReset();
            s.insertEntity(e);
            s.insertEntity(p);
            s.printScreen();
            sleep(200);
            s.clearScreen();
            if(gameEnd(control))   return 0;
            enem++;
        }
    }
}
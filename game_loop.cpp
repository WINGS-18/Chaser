#include <chrono>
#include <thread>
#include <conio.h>
#include "game_loop.h"
#include <iostream>
#include <array>
#include "player.h"
#include "enemy.h"
#include "screen.h"
#include "collision.h"

namespace Chaser {

    GameLoop::GameLoop() {}     //constructor defination

    /*milliseconds instance takes in integer*/
    /*sleep_for is a global free function*/

    void GameLoop::sleep(int time) {
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }

    const char GameLoop::c_keyGiver() {
        if(_kbhit()) {
            return _getch();
        }
        return '\0';
    }

    bool GameLoop::gameEnd(char key) {
        if(key == 'e')  return true;
        return false;
    }

    bool GameLoop::resultDisplay(const Enemy& e, const Player& p) {
        if(Collision::winCheck(p)) {
            std::cout << "YOU WIN!\n" << std::endl;
            return true;
        }

        if(Collision::playerCought(e, p)) {
            std::cout << "FAHHHH\nLOOSER!" << std::endl;
            return true;
        }

        return false;

    }

    int GameLoop::startGame() {
        Enemy e({0, 9}, 3, 'E');
        Player p({0, 0}, 0, 'U');       //decreased player speed
        Screen s;
        int enem = 0;
        char control;

        while(true) {
            //std::cout << "( " << p.p_getX() << ", " << p.p_getY() << " )\n";
            control = c_keyGiver();
            p.pMovement(control);
            //e.speedBooster(p);
            //std::cout << "speedoE: " << e.p_getSpeed() << std::endl;
            //std::cout << "enem: " << enem << std::endl;
            if(enem == e.p_getSpeed()){
                e.eMovement(p);
                enem = 0;
            }
            s.screenReset();
            s.insertEntity(e);
            s.insertEntity(p);
            s.printScreen();
            sleep(70);
            s.clearScreen();
            if(gameEnd(control))   return 0;
            if(resultDisplay(e, p))   return 0;
            enem++;
        }
    }
}
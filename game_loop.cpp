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

    void GameLoop::sleep(int time) {        //stops the program for time milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }

    const char GameLoop::c_keyGiver() {     //returns the key which is pressed
        if(_kbhit()) {
            return _getch();
        }
        return '\0';
    }

    bool GameLoop::gameEnd(char key) {      //end the game immediately
        if(key == 'e')  return true;
        return false;
    }

    bool GameLoop::resultDisplay(const Enemy& e, const Player& p) { //displays the results weather win or loose
        if(Collision::winCheck(p)) {
            std::cout << "YOU WIN!\n" << std::endl;
            return true;                                            //also returns a boolean
        }

        if(Collision::playerCought(e, p)) {
            std::cout << "FAHHHH\nLOOSER!" << std::endl;
            return true;
        }

        return false;
    }

    void GameLoop::pauseGame(char key) {
        if(key == 'p') {

            /*a while loops that keeps running the sleep
            code untill user wants to resume*/

            while(true) {
                if(c_keyGiver() != 'r') {
                    sleep(200);
                }else{
                    break;
                }
            }
        }
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
            pauseGame(control);
            sleep(70);
            s.clearScreen();
            if(gameEnd(control))   return 0;
            if(resultDisplay(e, p))   return 0;
            enem++;
        }
    }
}
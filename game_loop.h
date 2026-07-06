#pragma once

namespace Chaser {

    /*forward declaration: A promise made to the compiler
    that such classes are there ahead*/
    class Enemy;
    class Player;

    class GameLoop {
    public:
        GameLoop();     //constructor declaration
        
        void sleep(int time);       //pauses the program for given time
        const char c_keyGiver();        //returns the pressed key
        bool gameEnd(char key);     //did player intentionally end the game
        bool resultDisplay(const Enemy& e, const Player& p);        //displays the result
        int startGame();        //main game loop
    };

}
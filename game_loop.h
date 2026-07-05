#pragma once

namespace Chaser {

    class GameLoop {
    public:
        GameLoop();     //constructor declaration
        
        void sleep(int time);       //pauses the program for given time
        const char keyGiver();        //returns the pressed key
        bool gameEnd(char key);
        int startGame(); //{
            // int player_speed = 0;
            // int enemy_speed = 0;
            // while(true) {

            // }
        //}
    };

}
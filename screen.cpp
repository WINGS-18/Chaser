#include <iostream>
#include "screen.h"

namespace Chaser {

    void Screen::screenReset() {        //removes all the entities from the screen
        for(auto& row: m_frame) {
            row.fill(' ');
        }
    }

    Screen::Screen() {      //constructor defination
        screenReset();
    }

    void Screen::printScreen() {                    //prints the screen
        for(auto& row : m_frame) {          //gets a row from m_frame
            for(auto& cell: row) {          //iterates the row
                std::cout << cell;
            }
            std::cout << "\n";
        }
    }

    void Screen::clearScreen() {       //clears the terminal
        std::cout << "\033[2J\033[H";
    }
    
}
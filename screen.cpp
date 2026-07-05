#include <iostream>
#include "screen.h"

namespace Chaser {

    template <typename T>
    void Screen::insertEntity(const T& entity) {                //inserts entity into the screen
        m_frame[entity.p_getY()][entity.p_getX()] = entity.p_getAppearence();
    }

    void Screen::screenReset() {        //removes all the entities from the screen
        for(auto& row: m_frame) {
            row.fill(' ');
        }
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
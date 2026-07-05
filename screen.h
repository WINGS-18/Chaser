#pragma once

#include <iostream>
#include <array>

namespace Chaser {

    class Screen {
    private:
        std::array<std::array<char, 50>, 10> m_frame;

    public:
        Screen()                                            //default constructor
            : m_frame({{0}}) {}
        
        Screen(std::array<std::array<char, 50>, 10> f)      //parameterised constructor
            : m_frame(f) {}

        template <typename T>
        void insertEntity(const T& entity);     //inserts entity into the screen
        void printScreen();     //prints the screen
        void screenReset();     //resets the screen to blank
        void clearScreen();        //clears the terminal
    };
}
#pragma once
#include <array>

namespace Chaser {

    class Screen {
    private:
        std::array<std::array<char, 50>, 10> m_frame;

    public:
        Screen();         //default constructor

        template <typename T>
        void insertEntity(const T& entity);     //inserts entity into the (declaration)

        void printScreen();     //prints the screen
        void screenReset();     //resets the screen to blank
        void clearScreen();        //clears the terminal
    };



    /*Learnt that keeping both function declaration and function defination in the class,
    it treats them as different function hence we get error of "overloading not possible".
    So either we can declare the function inside class and write the defination outside the
    class or write the defination inside the class with any declaration*/



    /*Writing template function declaration in .h file and defination in the .cpp file won't
    work, because complier do not generate the machine code for template function as it doesn't
    know what parameter will come in it. Hence, as we know each files are complied individually
    and later the linker links these files, so for the linker is unable to find the machine code
    of the template function hence it throws the error*/



    template <typename T>
    void Screen::insertEntity(const T& entity) {    //inserts entity into the screen (defination)
        m_frame[entity.p_getY()][entity.p_getX()] = entity.p_getAppearence();
    }
}
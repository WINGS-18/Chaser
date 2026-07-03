#pragma once

namespace Chaser {
    struct Vector2C {
        int v_x;
        int v_y;

        Vector2C()
            : v_x(0), v_y(0) {}     //default constructor

        Vector2C(int x, int y)      //parameterised constructor
            : v_x(x), v_y(y) {}

        bool operator==(const Vector2C& other) {        //operator overloading
            if(v_x == other.v_x && v_y == other.v_y)    return true;
            return false;
        }
    };
}

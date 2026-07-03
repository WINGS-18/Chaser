#pragma once
#include "vector2c.h"

namespace Chaser {

    class Character {
    protected:
        Vector2C p_coord;
        int p_speed;
        char p_appearence;

    public:
        Character(Vector2C c, int s, char ap)
            : p_coord(c), p_speed(s), p_appearence(ap) {}       //member init list

        //virtual void insertEntity(char& grid) = 0;      //each entities insert them in the grid

        int p_getX() const {return p_coord.v_x;}        //returns x

        int p_getY() const {return p_coord.v_x;}        //returns y

        int p_getSpeed() const {return p_speed;}     //returns speed

        char p_getAppearence() const {return p_appearence;}     //returns appearence

        Vector2C getPosition() const {return p_coord;}      //returns current position
    };
}
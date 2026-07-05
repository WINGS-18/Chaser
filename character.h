#pragma once
#include "vector2c.h"

namespace Chaser {

    inline const Vector2C g_winCon{49, 9};     //win condition
    inline const Vector2C treshold{35, 0};     //point after which chaser gets speed boost
    inline const int g_minInvSpeed = 0;         //minimum speed a character can attain
    inline const int g_maxInvSpeed = 3;         //maximum speed a character can attain

    class Character {
    protected:
        Vector2C p_coord;
        int p_invSpeed;
        char p_appearence;

    public:
        Character(Vector2C c, int s, char ap)
            : p_coord(c), p_invSpeed(s), p_appearence(ap) {}       //member init list

        //virtual void insertEntity(char& grid) = 0;      //each entities insert them in the grid

        int p_getX() const {return p_coord.v_x;}        //returns x

        int p_getY() const {return p_coord.v_y;}        //returns y

        int p_getSpeed() const {return p_invSpeed;}     //returns speed

        char p_getAppearence() const {return p_appearence;}     //returns appearence

        Vector2C getPosition() const {return p_coord;}      //returns current position
    };
}
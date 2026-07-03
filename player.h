#pragma once

#include "character.h"

namespace Chaser {
    class Player : public Character {       //inheriting publically lets the base members to be of same access specifier
    public:
        Player(Vector2C c, int s, char ap);      //constructor declaration
 
        void pMovement(char key);            //coordinate changer
    };
}
#pragma once
#include "character.h"

namespace Chaser {

    /*forward declaration*/
    class Player;

    class Enemy : public Character {
    public:
        Enemy(Vector2C c, int s, char ap);        //enemy constructor declaration

        void eMovement(const Player& p);        //enemy movement

        //void speedBooster(const Player& p);     //increases the speed of the enemy
    };
}
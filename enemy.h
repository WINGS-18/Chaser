#pragma once
#include "character.h"

namespace Chaser {

    class Player;

    class Enemy : public Character {
    public:
        Enemy(Vector2C c, int s, char ap);        //enemy constructor declaration

        void eMovement(const Player& p);

        void speedBooster(const Player& p);
    };
}
#include <iostream>
#include "enemy.h"
#include "player.h"

namespace Chaser {
    Enemy::Enemy(Vector2C c, int s, char ap) : Character(c, s, ap) {}

    void Enemy::eMovement(const Player& u) {
        if(u.p_getX() > p_coord.v_x) {
            p_coord.v_x++;
        }else if(u.p_getX() < p_coord.v_x) {
            p_coord.v_x--;
        }else if(u.p_getY() > p_coord.v_y) {
            p_coord.v_y++;
        }else if(u.p_getY() < p_coord.v_y) {
            p_coord.v_y--;
        }
    }

    void Enemy::speedBooster(const Player& u) {

    }
    
}
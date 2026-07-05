#include <iostream>
#include "enemy.h"
#include "player.h"

namespace Chaser {

    Enemy::Enemy(Vector2C c, int s, char ap) : Character(c, s, ap) {
        std::cout << "Enemy Created" << std::endl;
    }       //Constructor defination

    void Enemy::eMovement(const Player& u) {        //moves the enemy to catch the player
        if(u.p_getX() > p_coord.v_x) {              //using shortest distance
            p_coord.v_x++;
        }else if(u.p_getX() < p_coord.v_x) {
            p_coord.v_x--;
        }else if(u.p_getY() > p_coord.v_y) {
            p_coord.v_y++;
        }else if(u.p_getY() < p_coord.v_y) {
            p_coord.v_y--;
        }
    }

    //some errors might occur
    // void Enemy::speedBooster(const Player& u) {
    //     if(p_invSpeed > g_minInvSpeed) {
    //         if(u.getPosition() > treshold) {
    //             p_invSpeed--;
    //         }
    //     }else if(p_invSpeed < g_maxInvSpeed) {
    //         p_invSpeed++;
    //     }
    // }
}

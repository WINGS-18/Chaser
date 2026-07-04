#include <iostream>
#include "player.h"

namespace Chaser {
    
    Player::Player(Vector2C c, int s, char ap) : Character(c, s, ap) {
        std::cout << "Player Created" << std::endl;
    }     //Constructor defination

    void Player::pMovement(char key) {      //moves the player
        switch(key) {
            case 'a' : 
                p_coord.v_x--;
                break;

            case 'd' :
                p_coord.v_x++;
                break;

            case 'w' :
                p_coord.v_y--;
                break;

            case 's' :
                p_coord.v_y++;
                break;

            default : break;
        }
    }
    
}
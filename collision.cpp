#include "player.h"
#include "enemy.h"
#include "collision.h"

namespace Chaser {

    /*sub-namespace of Chaser*/
    namespace Collision {

        bool playerCought(const Enemy& e, const Player& p) {        //checks weather chaser/enemy cought the player
            return p.getPosition() == e.getPosition();              //returns a boolean
        }

        bool winCheck(const Player& p) {            //checks weather player reached the destination
            return p.getPosition() == g_winCon;     //returns a boolen
        }

    }
    
}
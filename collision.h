#pragma once

namespace Chaser {

    /*forward declaration: promise made to the compiler
    that there are such classes ahead*/
    class Enemy;
    class Player;

    namespace Collision {

        bool playerCought(const Enemy& e, const Player& p);     //checks weather the player is cought by the enemy/chaser
        bool winCheck(const Player& p);     //checks weather the player reached the final destination
        
    }

}
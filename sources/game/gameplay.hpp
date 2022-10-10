#ifndef GAME_HPP
#define GAME_HPP

#include "core/core.hpp"
#include "objects/player.hpp"

class Gameplay
{
public:
    Gameplay();
    void doGame();
private:
    Player basePlayer;
    void doEvent();
    enum directionHorizontal {left = 1, right = 2};
    enum directionVertical {up = 1, down = 2};
};


#endif // !GAME_HPP
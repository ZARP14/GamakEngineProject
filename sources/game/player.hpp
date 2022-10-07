#ifndef PLAYER_HPP
#define PLAYER_HPP 

#include "game/aliveObjects.hpp"
#include <SFML/Graphics.hpp>
#include "gui/gui.hpp"

class Player :
    public AliveObjects
{
public:
    // Player(std::string str,
    //         int width,
    //         int height,
    //         int left,
    //         int right
    // );
    Player(std::string str = RESOURCES_PATH + "playerTexture.png", 
               int width = 100,
               int height = 100,
               int left = 0,
               int right = 0
);
};
#endif // !PLAYER_HPP


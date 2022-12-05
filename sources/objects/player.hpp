#ifndef PLAYER_HPP
#define PLAYER_HPP 

#include "objects/impermanentObjects.hpp"
#include <iomanip>

class Player :
    public ImpermanentObjects
{
public:

    Player(std::string str = RESOURCES_PATH + "playerTexture.png", 
               int width = 100,
               int height = 100,
               int left = 0,
               int right = 0
          );
    
};
#endif // !PLAYER_HPP


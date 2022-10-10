#ifndef PLAYER_HPP
#define PLAYER_HPP 

#include "objects/aliveObjects.hpp"
#include "gui/gui.hpp"

class Player :
    public AliveObjects
{
public:

    Player(std::string str = RESOURCES_PATH + "playerTexture.png", 
               int width = 100,
               int height = 100,
               int left = 0,
               int right = 0
          );

private:
    void movingHorizontal(bool direction);
    void movingVertical(bool direction);
};
#endif // !PLAYER_HPP


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iomanip>

#include "objects/impermanentObjects.hpp"

class Player : public ImpermanentObjects
{
public:
    Player(std::string str = TEXTURES_PATH + "playerTexture.png",
           int width = 100, int height = 100, int left = 0, int right = 0);
};
#endif // !PLAYER_HPP

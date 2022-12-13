#include "objects/player.hpp"

Player::Player(std::string str, int width, int height, int left, int right)
{

    objectRectangle.width  = width;
    objectRectangle.height = height;
    objectRectangle.left   = left;
    objectRectangle.top    = right;
    objectTexture.loadFromFile(str);
    objectSprite.setTexture(objectTexture);
    objectSprite.setPosition(500, 0);
}

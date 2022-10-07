#include "game/player.hpp"

// Player::Player(std::string str = RESOURCES_PATH + "playerTexture.png", 
//                int width = 100,
//                int height = 100,
//                int left = 0,
//                int right = 0
// )
    Player::Player(std::string str,
            int width,
            int height,
            int left,
            int right
    )
{
    objectRectangle.width = width;
    objectRectangle.height = height;
    objectRectangle.left = left;
    objectRectangle.top = right;
    objectTexture.loadFromFile(str);
    objectSprite.setTexture(objectTexture);
    Gui::global.vectorInput(objectSprite);
}
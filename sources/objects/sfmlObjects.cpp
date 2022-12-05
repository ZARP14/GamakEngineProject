#include "objects/sfmlObjects.hpp"

SFMLObjects::SFMLObjects()
{
    Gui::global.vectorInput(objectSprite);
    objectIndex = Gui::global.SpriteVector.size() - 1;
}
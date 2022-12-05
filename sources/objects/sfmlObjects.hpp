#ifndef SFMLOBJECTS_HPP
#define SFMLOBJECTS_HPP

#include <SFML/Graphics.hpp>
#include "domain/definiki.hpp"
#include "gui/gui.hpp"

class SFMLObjects
{
public:
    SFMLObjects();
    int objectIndex;
    sf::IntRect objectRectangle;
    sf::Sprite objectSprite;
	sf::Texture objectTexture;
};
#endif // !SFMLOBJECTS_HPP
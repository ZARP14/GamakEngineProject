#include "interface.hpp"

Interface::Interface(sf::Texture txr)
{
    pageTexture = txr;
    pageSprite.setTexture(pageTexture);
}

void
Interface::setButton(sf::Texture onClickTexture, sf::Texture defaultTexture, sf::Vector2f pos,
                     sf::Vector2f sizeInput)
{
    buttons.emplace_back(onClickTexture, defaultTexture, pos, sizeInput);
}
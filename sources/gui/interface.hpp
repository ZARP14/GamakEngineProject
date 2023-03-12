#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <SFML/Graphics.hpp>

#include "button.hpp"

class Interface
{
public:
    Interface();
    void setButton(sf::Texture onClickTexture, sf::Texture defaultTexture, sf::Vector2f pos,
                   sf::Vector2f sizeInput);
    void draw();

private:
    sf::Sprite pageSprite;
    sf::Texture pageTexture;
    std::vector<Button> buttons;
};

#endif
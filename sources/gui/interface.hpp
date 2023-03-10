#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "button.hpp"
#include "gui.hpp"

class Interface
{
public:
    Interface();
    void setButton();
    void drawer();

private:
    sf::Sprite pageSprite;
    sf::Texture pageTexture;
    std::vector<Button> buttons;
};

#endif
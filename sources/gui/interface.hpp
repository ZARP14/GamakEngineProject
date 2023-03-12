#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <SFML/Graphics.hpp>

#include <string>

#include "button.hpp"

class Interface
{
public:
    Interface(std::string path, float x, float y);
    void setButton(std::string onClickTexturePath, std::string defaultTexturePath, float x, float y,
                   float xSize, float ySize);
    std::vector<sf::Sprite> draw();

private:
    sf::Vector2f pagePosition;
    sf::Sprite pageSprite;
    sf::Texture pageTexture;
    std::vector<Button> buttons;
};

#endif
#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <vector>

#include "gui.hpp"

class Button
{
public:
    Button(sf::Texture onClickTexture, sf::Texture defaultTexture, sf::Vector2f pos,
           sf::Vector2f sizeInput);
    void doSomething();
    std::vector<sf::Vector2f> getButtonPosition();
    void clicked(sf::Vector2f clickCoordinates);
    enum class type
    {
        zero = 0
    };

private:
    sf::Sprite buttonSprite;
    sf::Texture onClickTexture;
    sf::Texture defaultTexture;
    sf::Vector2f buttonPosition;
    sf::Vector2f buttonSize;
    int layer;
};

#endif
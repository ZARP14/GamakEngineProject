#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class Button
{
public:
    Button(std::string onClickTexturePath, std::string defaultTexturePath, float x, float y,
           float xSize, float ySize);
    void doSomething();
    std::vector<sf::Vector2f> getButtonPosition();
    void clicked(sf::Vector2f clickCoordinates);
    enum class type
    {
        zero = 0
    };
    sf::Sprite buttonSprite;

private:
    sf::Texture onClickTexture;
    sf::Texture defaultTexture;
    sf::Vector2f buttonPosition;
    sf::Vector2f buttonSize;
    int layer;
};

#endif
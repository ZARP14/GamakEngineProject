#include "button.hpp"

Button::Button(std::string onClickTexturePath, std::string defaultTexturePath, float x, float y,
               float xSize, float ySize)
{
    onClickTexture.loadFromFile(onClickTexturePath);
    defaultTexture.loadFromFile(defaultTexturePath);
    buttonPosition.x = x;
    buttonPosition.y = y;
    buttonSize.x     = xSize;
    buttonSize.y     = ySize;
    buttonSprite.setTexture(defaultTexture);
    buttonSprite.setPosition(buttonPosition);
}

void
Button::clicked(sf::Vector2f clickCoordinates)
{
    float x     = clickCoordinates.x;
    float y     = clickCoordinates.y;
    bool xCheck = x > buttonPosition.x && x < buttonPosition.x + buttonSize.x;
    bool yCheck = y > buttonPosition.y && y < buttonPosition.y + buttonSize.y;
    if (xCheck && yCheck)
    {
        buttonSprite.setTexture(onClickTexture);
    }
}
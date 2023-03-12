#include "button.hpp"

Button::Button(sf::Texture onClickTextureInput, sf::Texture defaultTextureInput, sf::Vector2f pos,
               sf::Vector2f sizeInput)
{
    onClickTexture = onClickTextureInput;
    defaultTexture = defaultTextureInput;
    buttonPosition = pos;
    buttonSize     = sizeInput;
    buttonSprite.setTexture(defaultTexture);
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
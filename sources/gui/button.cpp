#include "button.hpp"

button::button(sf::Texture onClickTextureInput, sf::Texture defaultTextureInput, sf::Vector2f pos,
               sf::Vector2f sizeInput)
{
    onClickTexture = onClickTextureInput;
    defaultTexture = defaultTextureInput;
    buttonPosition = pos;
    size           = sizeInput;
}
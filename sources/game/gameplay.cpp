#include "game/gameplay.hpp"

Gameplay::Gameplay()
{
    stone.objectTexture.loadFromFile(TEXTURES_PATH + "PlayerTexture.png");
    stone.objectSprite.setTexture(stone.objectTexture);
    stone.objectSprite.setPosition(700, 500);
}

void
Gameplay::doEvent(std::vector<sf::Event>& b)
{
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i].type == sf::Event::KeyPressed)
        {
            if (b[i].key.code == sf::Keyboard::A)
            {
                basePlayer.moveStoper(1, int(sideType::horizontal));
                basePlayer.moveChanger(int(side::left),
                                       int(sideType::horizontal));
            }
            else if (b[i].key.code == sf::Keyboard::D)
            {
                basePlayer.moveStoper(1, int(sideType::horizontal));
                basePlayer.moveChanger(int(side::right),
                                       int(sideType::horizontal));
            }
            else if (b[i].key.code == sf::Keyboard::W)
            {
                basePlayer.moveStoper(1, int(sideType::vertical));
                basePlayer.moveChanger(int(side::top), int(sideType::vertical));
            }
            else if (b[i].key.code == sf::Keyboard::S)
            {
                basePlayer.moveStoper(1, int(sideType::vertical));
                basePlayer.moveChanger(int(side::down),
                                       int(sideType::vertical));
            }
        }
        else if (b[i].type == sf::Event::KeyReleased)
        {
            if (b[i].key.code == sf::Keyboard::A ||
                b[i].key.code == sf::Keyboard::D)
                basePlayer.moveStoper(0, int(sideType::horizontal));
            else if (b[i].key.code == sf::Keyboard::W ||
                     b[i].key.code == sf::Keyboard::S)
                basePlayer.moveStoper(0, int(sideType::vertical));
        }
    }
}

void
Gameplay::doGame(std::vector<sf::Event>& a)
{
    doEvent(a);
    basePlayer.movingHorizontal();
    basePlayer.movingVertical();
}

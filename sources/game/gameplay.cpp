#include "game/gameplay.hpp"

Gameplay::Gameplay()
{
    stone.objectTexture.loadFromFile(TEXTURES_PATH + "PlayerTexture.png");
    stone.objectSprite.setTexture(stone.objectTexture);
    stone.objectSprite.setPosition(500, 500);
    stone2.objectTexture.loadFromFile(TEXTURES_PATH + "flor.png");
    stone2.objectSprite.setTexture(stone2.objectTexture);
    stone2.objectSprite.setPosition(0, 553);
}

void
Gameplay::eventScan(std::vector<sf::Event>& b)
{
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i].type == sf::Event::KeyPressed)
        {
            a.insert(b[i].key.code);
        }
        else if (b[i].type == sf::Event::KeyReleased)
        {
            a.erase(b[i].key.code);
        }
    }
}

void
Gameplay::doEvent()
{
    if (a.count(sf::Keyboard::A))
    {
        basePlayer.moveHorizontalStoper(1, int(side::left));
        basePlayer.moveChanger(int(side::left), int(sideType::horizontal));
    }
    if (a.count(sf::Keyboard::D))
    {
        basePlayer.moveHorizontalStoper(1, int(side::right));
        basePlayer.moveChanger(int(side::right), int(sideType::horizontal));
    }
    if (a.count(sf::Keyboard::W))
    {
        basePlayer.moveVerticalStoper(1);
        basePlayer.moveChanger(int(side::top), int(sideType::vertical));
    }

    if (!a.count(sf::Keyboard::A))
    {
        basePlayer.moveHorizontalStoper(0, int(side::left));
    }
    if (!a.count(sf::Keyboard::D))
    {
        basePlayer.moveHorizontalStoper(0, int(side::right));
    }
    if (!a.count(sf::Keyboard::W))
    {
        basePlayer.moveVerticalStoper(0);
    }
}
void
Gameplay::doGame(std::vector<sf::Event>& a)
{
    eventScan(a);
    doEvent();
    basePlayer.movingHorizontal();
    basePlayer.gravity();
    basePlayer.movingVertical();
}

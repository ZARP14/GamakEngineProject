#include "game/gameplay.hpp"

Gameplay::Gameplay() : basePlayer(baseWorld.mB2dWorld)
{
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
Gameplay::doGame(std::vector<sf::Event>& a)
{
    basePlayer.objectSprite.setPosition(basePlayer.body->GetPosition().x,
                                        basePlayer.body->GetPosition().y);
}

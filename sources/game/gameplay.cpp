#include "game/gameplay.hpp"

void 
Gameplay::doEvent()
{
    Core mCore;
    for (int i = 0; i < mCore.eventVecTransmitterForGame().size(); i++)
    {
        if (mCore.eventVecTransmitterForGame()[i].type == sf::Event::KeyPressed)

        if (mCore.eventVecTransmitterForGame()[i].type == sf::Event::KeyPressed)
            {
                if (mCore.eventVecTransmitterForGame()[i].key.code == sf::Keyboard::A)
                    basePlayer.movingHorizontal(directionHorizontal::left);
                else if (mCore.eventVecTransmitterForGame()[i].key.code == sf::Keyboard::D)
                    basePlayer.movingHorizontal(directionHorizontal::right);
                else if (mCore.eventVecTransmitterForGame()[i].key.code == sf::Keyboard::W)
                    basePlayer.movingVertical(directionVertical::up);
                else if (mCore.eventVecTransmitterForGame()[i].key.code == sf::Keyboard::S)
                    basePlayer.movingVertical(directionVertical::down);
            }
            else if (mCore.eventVecTransmitterForGame()[i].type == sf::Event::KeyReleased)
            {
                if (mCore.eventVecTransmitterForGame()[i].key.code == sf::Keyboard::A || mCore.eventVecTransmitterForGame()[i].key.code == sf::Keyboard::D)

                else if (mCore.eventVecTransmitterForGame()[i].key.code == sf::Keyboard::W || mCore.eventVecTransmitterForGame()[i].key.code == sf::Keyboard::S)

            }
    }


}

void
Gameplay::doGame()
{
    doEvent
}

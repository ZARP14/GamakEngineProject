
#include "core/core.hpp"

void
Core::eventSorter(std::vector<sf::Event>& a)
{
    if (a.size() != 0)
    {
        for (int i = 0; i < a.size(); i++)
        {
            switch (a[i].type)
            {
                case sf::Event::Closed:
                    Gui::global.bebraMustDie();
                    break;

                case sf::Event::KeyPressed:
                    eventVecForGame.push_back(a[i]);
                    break;

                case sf::Event::KeyReleased:
                    eventVecForGame.push_back(a[i]);
                    break;

                default:
                    break;
            }
        }
    }
}

void
Core::run()
{
    Gameplay mainGame;
    while (true)
    {
        time.reTime();
        Gui::global.visualStarted();
        std::vector<sf::Event>& a = Gui::global.eventTrnasmitterToCore();
        eventSorter(a);
        mainGame.doGame(eventVecForGame);
        eventVecForGame.clear();
        a.clear();
    }
}

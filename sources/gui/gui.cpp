#include "gui/gui.hpp"

Gui Gui::global;

Gui::Gui() :
 mWindow(sf::VideoMode(1000, 1000), "TheBestGame")
{
    mWindow.setFramerateLimit(60);
}

void
Gui::vectorInput(sf::Sprite &a)
{
    SpriteVector.push_back(&a);
}

void
Gui::drawAnything()
{
    for(int i = 0; i < SpriteVector.size(); i++)
    {
        mWindow.draw(*SpriteVector[i]);
    }
}

std::vector<sf::Event>&
Gui::eventTrnasmitterToCore()
{
    return evObject.eventVec;
}


void
Gui::bebraMustDie()
{
    mWindow.close();
    exit(0);
}

void
Gui::visualStarted()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        evObject.pushEvent(event);
    }
    mWindow.clear();
    drawAnything();
    mWindow.display();  // которая будет отрисовывать все объекты на экране  

}
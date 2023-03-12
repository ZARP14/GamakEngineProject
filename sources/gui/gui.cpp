#include "gui/gui.hpp"

Gui Gui::global;

Gui::Gui()
    : mWindow(sf::VideoMode(500, 500), "TheBestGame"),
      mainPage(TEXTURES_PATH + "mainPage.png", 0, 0)
{
    interfacePageVector.push_back(&mainPage);
    mainPage.setButton(TEXTURES_PATH + "firstButton_1.png", TEXTURES_PATH + "firstButton_2.png", 82,
                       118, 340, 150);
    mWindow.setFramerateLimit(60);
}

void
Gui::vectorInput(sf::Sprite& a)
{
    SpriteVector.push_back(&a);
}

void
Gui::drawAnything()
{
    for (int i = 0; i < SpriteVector.size(); i++)
    {
        mWindow.draw(*SpriteVector[i]);
    }

    for (int i = 0; i < interfacePageVector.size(); i++)
    {
        for (int j = 0; j < interfacePageVector.size(); j++)
        {
            mWindow.draw(interfacePageVector[i]->draw()[j]);
        }
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
    mWindow.display();
}
#include "gui/gui.hpp"

Gui Gui::global;

Gui::Gui() :
 mWindow(sf::VideoMode(1000, 1000), "SFML works!")
{

}

void
Gui::vectorInput(sf::Sprite &a)
{
    SpriteVector.push_back(a);
}

void
Gui::drawAnything()
{
    for(int i = 0; i < SpriteVector.size(); i++)
    {
        mWindow.draw(SpriteVector[i]);
    } ;
}

void
Gui::visual_started()
{
    sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                    mWindow.close();
        }

        mWindow.clear();
        drawAnything();
        mWindow.display();  // которая будет отрисовывать все объекты на экране  

}
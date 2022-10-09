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
    }
}

Events
Gui::eventTrnasmitterToCore()
{
    return evObject;
}

// void
// Gui::eventFunction(sf::Event &e)
// {
//      if (e.type == sf::Event::Closed)
//      {
//         mWindow.close();
//      }

//             else if (e.type == sf::Event::KeyPressed)
//             {
//                 if (e.key.code == sf::Keyboard::Left)

//                 else if (e.key.code == sf::Keyboard::Right)

//                 else if (e.key.code == sf::Keyboard::Up)

//                 else if (e.key.code == sf::Keyboard::Down)

//             }
//             else if (e.type == sf::Event::KeyReleased)
//             {
//                 if (e.key.code == sf::Keyboard::Left || e.key.code == sf::Keyboard::Right)

//                 else if (e.key.code == sf::Keyboard::Up || e.key.code == sf::Keyboard::Down)

//             }
// }


void
Gui::bebraMustDie()
{
    mWindow.close();
}

void
Gui::visual_started()
{
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            evObject.newEvent(event);
        }


        mWindow.clear();
        drawAnything();
        mWindow.display();  // которая будет отрисовывать все объекты на экране  

}
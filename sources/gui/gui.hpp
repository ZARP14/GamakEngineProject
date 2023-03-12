#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <set>
#include <vector>

#include "domain/definiki.hpp"

#include "core/events.hpp"

#include "interface.hpp"

class Gui
{
public:
    static Gui global;
    void visualStarted();
    void vectorInput(sf::Sprite& a);
    Events evObject;
    std::vector<sf::Event>& eventTrnasmitterToCore();
    void bebraMustDie();
    std::vector<sf::Sprite*> SpriteVector;
    std::vector<Interface*> interfacePageVector;

private:
    Gui();
    void drawAnything();
    sf::RenderWindow mWindow;
    // Pages//
    Interface mainPage;
    // Pages//
};
#endif // !GUI_HPP

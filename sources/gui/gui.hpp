#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>

#include <vector>

#include "core/events.hpp"

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

private:
    Gui();
    void drawAnything();
    sf::RenderWindow mWindow;
};
#endif // !GUI_HPP

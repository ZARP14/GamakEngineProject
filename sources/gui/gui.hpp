#ifndef GUI_HPP
#define GUI_HPP 

#include <SFML/Graphics.hpp>
#include <vector>
#include "core/events.hpp"

class Gui
{
public:
    static Gui global;
    void visual_started();
    void vectorInput(sf::Sprite &a);
    Events evObject;
    std::vector<sf::Event> eventTrnasmitterToCore();
    void bebraMustDie();
private:
    Gui();
    void drawAnything();
    sf::RenderWindow mWindow;
    std::vector<sf::Sprite> SpriteVector;
};
#endif // !GUI_HPP


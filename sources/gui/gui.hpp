#ifndef GUI_HPP
#define GUI_HPP 

#include <SFML/Graphics.hpp>
#include <vector>

class Gui
{
public:
    static Gui global;
    void visual_started();
    void vectorInput(sf::Sprite &a);
private:

    Gui();
    void drawAnything();
    void eventFunction();
    sf::RenderWindow mWindow;
    std::vector<sf::Sprite> SpriteVector;
};
#endif // !GUI_HPP


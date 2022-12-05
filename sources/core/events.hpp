#ifndef EVENTS_HPP
#define EVENTS_HPP 

#include <SFML/Graphics.hpp>
#include <vector>

class Events 
{
public:
    void pushEvent(sf::Event &ev);
    std::vector<sf::Event> eventVec;
};

#endif // !EVENTS_HPP
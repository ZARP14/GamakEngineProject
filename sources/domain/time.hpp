#ifndef TIME_HPP
#define TIME_HPP

#include <SFML/Graphics.hpp>

class Time
{
public:
    sf::Clock mainTime;
    static float gameTime;
    void reTime();
};
#endif // !TIME_HPP
#include "time.hpp"
float Time::gameTime = 0;

void
Time::reTime()
{
    gameTime = mainTime.restart().asMilliseconds();
}
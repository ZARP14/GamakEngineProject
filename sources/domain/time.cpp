#include "time.hpp"

void
Time::reTime()
{
    gameTime = mainTime.restart().asMilliseconds();
}
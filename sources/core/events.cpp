#include "core/events.hpp"

void
Events::newEvent(sf::Event &ev)
{
    eventVec.push_back(ev);
}

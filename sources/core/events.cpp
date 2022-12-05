#include "core/events.hpp"

void
Events::pushEvent(sf::Event &ev)
{
    eventVec.push_back(ev);
}

#include "core/events.hpp"

void
Events::pushEvent(sf::Event& ev)
{
    eventVector.push_back(ev);
}

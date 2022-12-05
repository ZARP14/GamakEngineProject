#ifndef CORE_HPP
#define CORE_HPP

#include <fstream>
#include <string>
#include <vector>

#include "domain/definiki.hpp"
#include "domain/time.hpp"

#include "game/gameplay.hpp"
#include "gui/gui.hpp"

class Core
{
public:
    std::vector<sf::Event> eventVecTransmitterForGame();
    std::vector<sf::Event> eventVecTransmitterForMenu();
    void run();
    Core() = default;
    std::vector<sf::Event> eventTrnasmitterToGame();

private:
    Time time;
    void eventSorter(std::vector<sf::Event>& a);
    std::vector<sf::Event> eventVecForGame;
    std::vector<sf::Event> eventVecForMenu;
};

#endif // !CORE_HPP
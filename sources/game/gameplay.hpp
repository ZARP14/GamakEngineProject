#ifndef GAME_HPP
#define GAME_HPP

#include "domain/const.hpp"
#include "domain/time.hpp"

#include "gui/gui.hpp"

class Gameplay
{
public:
    Gameplay();
    void doGame(std::vector<sf::Event>& a);

private:
    void eventScan(std::vector<sf::Event>& b);
    void doEvent();
    std::set<sf::Keyboard::Key> a;
};

#endif // !GAME_HPP
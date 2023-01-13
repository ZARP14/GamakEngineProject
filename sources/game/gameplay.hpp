#ifndef GAME_HPP
#define GAME_HPP

#include <box2d/box2d.h>

#include "domain/const.hpp"
#include "domain/time.hpp"

#include "objects/player.hpp"
#include "objects/sfmlObjects.hpp"

class Gameplay
{
public:
    Gameplay();
    void doGame(std::vector<sf::Event>& a);

private:
    Player basePlayer;

    SFMLObjects stone;
    SFMLObjects stone2;
    void eventScan(std::vector<sf::Event>& b);
    void doEvent();
    std::set<sf::Keyboard::Key> a;
};

#endif // !GAME_HPP
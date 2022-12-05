#ifndef GAME_HPP
#define GAME_HPP

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
    void doEvent(std::vector<sf::Event>& b);
};

#endif // !GAME_HPP
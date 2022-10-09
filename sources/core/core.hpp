#ifndef CORE_HPP
#define CORE_HPP

#include <string>
#include <fstream>
#include <vector>

#include "gui/gui.hpp"
#include "game/player.hpp"
#include "domain/definiki.hpp"


class Core
{
public:
	void run();
	Core() = default;
	std::vector<sf::Event> eventTrnasmitterToGame();
private:
	void eventSorter();
	std::vector<sf::Event> eventVecForGame;
	std::vector<sf::Event> eventVecForMenu;

};

#endif // !CORE_HPP
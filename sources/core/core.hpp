#ifndef CORE_HPP
#define CORE_HPP

#include <string>
#include <fstream>
#include <vector>

#include "gui/gui.hpp"
#include "game/gameplay.hpp"
#include "domain/definiki.hpp"


class Core
{
public:
	std::vector<sf::Event> eventVecTransmitterForGame();
	std::vector<sf::Event> eventVecTransmitterForMenu();
	void run();
	Core() = default;
	std::vector<sf::Event> eventTrnasmitterToGame();
private:
	void eventSorter(std::vector<sf::Event> &a);
	std::vector<sf::Event> eventVecForGame;
	std::vector<sf::Event> eventVecForMenu;

};

#endif // !CORE_HPP
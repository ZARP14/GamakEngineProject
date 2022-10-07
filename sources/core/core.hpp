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
private:
};

#endif // !CORE_HPP
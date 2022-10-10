
#include "core/core.hpp"
std::vector<sf::Event>
Core::eventVecTransmitterForGame()
{
	return eventVecForGame;
}

std::vector<sf::Event> 
Core::eventVecTransmitterForMenu()
{	
	return eventVecForMenu;
}

void
Core::eventSorter()
{
	for (int i = 0; i < Gui::global.eventTrnasmitterToCore().size(); i++)
	{
		switch (Gui::global.eventTrnasmitterToCore()[i].type)
		{
		case sf::Event::Closed:
			Gui::global.bebraMustDie();
			break;
			
		case sf::Event::KeyPressed:
			eventVecForGame.push_back(Gui::global.eventTrnasmitterToCore()[i]);
			break;

		case sf::Event::KeyReleased:
			eventVecForGame.push_back(Gui::global.eventTrnasmitterToCore()[i]);
			break;

		default:
			break;
		}
	}
}

void
Core::run()
{
	Gameplay mainGame;
	while (true)
	{
		Gui::global.visual_started();
		eventSorter();
		mainGame.doGame();
	}
}






#include "core/core.hpp"

void
Core::eventSorter()
{
	for (int i = 0; i < Gui::global.eventTrnasmitterToCore().eventVec.size(); i++)
	{
		switch (Gui::global.eventTrnasmitterToCore().eventVec[i].type)
		{
		case sf::Event::Closed:
			Gui::global.bebraMustDie();
			break;
			
		case sf::Event::KeyPressed:
			eventVecForGame.push_back(Gui::global.eventTrnasmitterToCore().eventVec[i]);
		
		default:
			break;
		}
	}
}

void
Core::run()
{
    Player basePlayer;

	while (true)
	{
		Gui::global.visual_started();
		eventSoter();
	}
}





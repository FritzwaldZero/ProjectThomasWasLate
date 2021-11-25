#include "Engine.h"

void Engine::input()
{
	Event event;

	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// handle the player quitting 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_Window.close();
			}
			//handle the player starrting the game
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				m_IsPlaying = true;
			}
			//switch between Thomas and Bob
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}
			// switch between full and split screen 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				m_IsSplitScreen = !m_IsSplitScreen;
			}
		}
	}
}
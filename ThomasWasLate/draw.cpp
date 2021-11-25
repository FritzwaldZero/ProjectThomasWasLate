#include "Engine.h"

void Engine::draw()
{
	// rub ou thte last frame
	m_Window.clear(sf::Color::White);
	if (!m_IsSplitScreen)
	{
		//switch to new background view
		m_Window.setView(m_BGMainView);
		//draw the background
		m_Window.draw(m_BackgroundSprite);
		//switch to main view
		m_Window.setView(m_MainView);
	}
	else
	{
		// spilt screen view is active 1st draw thomas side of screen 
		// switch to background view 
		m_Window.setView(m_BGLeftView);
		//draw the background
		m_Window.draw(m_BackgroundSprite);
		//switch to main view
		m_Window.setView(m_LeftView);

		//draw bobs view
		m_Window.setView(m_BGRightView);
		//draw the background
		m_Window.draw(m_BackgroundSprite);
		//switch to main view
		m_Window.setView(m_RightView);
	}
	// draw the HUD, switch to HUD view
	m_Window.setView(m_HUDView);
	// show everything we have just drawn
	m_Window.display();
}
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
		m_Window.draw(m_VALevel, &m_TextureFiles);
		//draw thomas and bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
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

		m_Window.draw(m_VALevel, &m_TextureFiles);

		
		m_Window.draw(m_Bob.getSprite());		
		m_Window.draw(m_Thomas.getSprite());

		//draw bobs view
		m_Window.setView(m_BGRightView);
		//draw the background
		m_Window.draw(m_BackgroundSprite);
		//switch to main view
		m_Window.setView(m_RightView);

		m_Window.draw(m_VALevel, &m_TextureFiles);

		
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
	}
	// draw the HUD, switch to HUD view
	m_Window.setView(m_HUDView);
	// show everything we have just drawn
	m_Window.display();
}
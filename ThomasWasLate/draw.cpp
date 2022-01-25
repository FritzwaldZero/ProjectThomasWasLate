#include "Engine.h"

void Engine::draw()
{
	// rub ou thte last frame
	m_Window.clear(sf::Color::White);

	m_RippleShader.setUniform("uTime", m_GameTimeTotal.asSeconds());

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

		//draw particles if the PS is running
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}
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

		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}
	}
	// draw the HUD, switch to HUD view
	m_Window.setView(m_HUDView);
	m_Window.draw(m_Hud.getLevel());
	m_Window.draw(m_Hud.getTime());
	if (!m_IsPlaying)
	{
		m_Window.draw(m_Hud.getMessage());
	}

	// show everything we have just drawn
	m_Window.display();


}
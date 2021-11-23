#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>
using namespace sf;

void Engine::input()
{
	Event event;

	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// handle the player quitting 
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}
			//handle the player starrting the game
			if (Keyboard::isKeyPressed(Keyboard::Return));
			{
				m_IsPlaying = true;
			}
			//switch between Thomas and Bob
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}
			// switch between full and split screen 
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_IsSplitScreen = !m_IsSplitScreen;
			}
		}
	}
}
void Engine::update(float dtAsSeconds)
{
	if (m_IsPlaying)
	{
		//count down the time the player has left 
		m_TimeRemaining -= dtAsSeconds;
		//have thomas and bob run out of time
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}// end if playing 
}
void Engine::draw()
{
	// rub ou thte last frame
	m_Window.clear(Color::White);
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

Engine::Engine()
{
	// get the screen resolution 
	// and create an SFML window and view
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;
	m_Window.create(sf::VideoMode(resolution.x, resolution.y), "Thomas was Late", sf::Style::Fullscreen);

	// Initialise the full screen view
	m_MainView.setSize(resolution);
	m_HUDView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	// initialise the split screen 
	m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BackgroundTexture = TextureHolder::GetTexture("assets/graphics/background.png");

	m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Engine::run()
{
	//timing 
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();

		//update the total game time
		m_GameTimeTotal += dt;

		// make a decimal fraction from the dt 
		float dtAsSeconds = dt.asSeconds();

		// call each part of the game loop in turn 
		input();
		update(dtAsSeconds);
		draw();
	}
}

#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

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
	m_HUDView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));

	// initialise the split screen 
	m_LeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGLeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	//shader background
	if (!Shader::isAvailable())
	{
		m_Window.close();
	}
	else
	{
		m_RippleShader.loadFromFile("assets/shaders/vertShader.vert", "assets/shaders/ripplerShader.frag");
	}

	m_BackgroundTexture = TextureHolder::GetTexture("assets/graphics/background.png");

	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	// load in the textures for the background vertex 
	m_TextureFiles = TextureHolder::GetTexture("assets/graphics/tiles_sheet.png");

	// initialize the particle system
	m_PS.init(1000);

}

void Engine::run()
{
	//timing 
	sf::Clock clock;

	while (m_Window.isOpen())
	{
		sf::Time dt = clock.restart();

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

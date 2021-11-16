#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

class Engine
{
private:
	//texture holder 
	TextureHolder th;
	const int TILE_SIZE = 50;
	const int VERT_IN_QUAD = 4;

	// force pushing character down 
	const int GRAVITY = 300;

	sf::RenderWindow m_Window;

	sf::View m_BGMainView;
	sf::View m_BGLeftView;
	sf::View m_BGRightView;
	sf::View m_HUDView;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgorundTexture;

	bool m_IsPlaying = false;

	bool m_Character1 = true;

	bool m_IsSplitScreen = false;

	bool m_NewLevelRequired = true;

	float m_TimeRemaining = 10;
	sf::Time m_GameTimeTotal;
	
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();
	void run();
};

#endif ENGINE_H
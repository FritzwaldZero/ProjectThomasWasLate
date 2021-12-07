#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "LevelManager.h"
#include "Bob.h"
#include "Thomas.h"

using namespace sf;

class Engine
{
private:
	//texture holder 
	TextureHolder th;
	//Thomas and Bob
	Thomas m_Thomas;
	Bob m_Bob;

	// a class reference to manage all the levels 
	LevelManager m_LM;

	const int TILE_SIZE = 50;
	const int VERT_IN_QUAD = 4;

	// force pushing character down 
	const int GRAVITY = 300;

	sf::RenderWindow m_Window;
	// the main views 
	View m_MainView;
	View m_LeftView;
	View m_RightView;
	// backgorund views
	sf::View m_BGMainView;
	sf::View m_BGLeftView;
	sf::View m_BGRightView;
	sf::View m_HUDView;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	bool m_IsPlaying = false;

	bool m_Character1 = true;

	bool m_IsSplitScreen = false;

	bool m_NewLevelRequired = true;

	float m_TimeRemaining = 10;
	sf::Time m_GameTimeTotal;

	// Vertex array for the level tiles 
	VertexArray m_VALevel;

	// the 2d array with the map for the level 
	int** m_ArrayLevel = NULL;

	// texture for the level tiles 
	Texture m_TextureFiles;

	
	void input();
	void update(float dtAsSeconds);
	void draw();
	void loadLevel();

public:
	Engine();
	void run();
};

#endif ENGINE_H
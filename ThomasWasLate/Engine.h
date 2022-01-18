#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "Character.h"
#include "Bob.h"
#include "Thomas.h"
#include "Hud.h" 

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

	//class reference tp manage sound 
	SoundManager m_SM;

	//a class reference to the hud 
	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

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

	vector <Vector2f> m_FireEmitters;

	void input();
	void update(float dtAsSeconds);
	void draw();
	void loadLevel();
	void populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel);
	bool detectCollisions(PlayableCharacter& character);



public:
	Engine();
	void run();
};

#endif ENGINE_H
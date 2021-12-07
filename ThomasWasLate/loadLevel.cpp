#include "Engine.h"

void Engine::loadLevel()
{
	m_IsPlaying = false;

	//delete the previous allocated memory 
	for (int h = 0; h < m_LM.getLevelSize().y ; ++h)
	{
		delete[] m_ArrayLevel[h];
	}

	// delete the entire array 
	delete[] m_ArrayLevel;

	// load the next 2d array with the map for the level 
	//and then repopulate the vertex array 
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	// how long is the new timel limit 
	m_TimeRemaining = m_LM.getTimeLimit();

	//spawn thomas and bob
	m_Thomas.Spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.Spawn(m_LM.getStartPosition(), GRAVITY);

	m_NewLevelRequired = false;

}
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

	populateEmitters(m_FireEmitters, m_ArrayLevel);

	// how long is the new timel limit

	m_TimeRemaining = m_LM.getTimeLimit();

	//spawn thomas and bob
	m_Thomas.Spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.Spawn(m_LM.getStartPosition(), GRAVITY);

	m_NewLevelRequired = false;

}

void Engine::populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel)
{
	vSoundEmitters.empty();

	FloatRect previousEmitter;

	for (int x = 0; x < (int)m_LM.getLevelSize().x; x++)
	{
		for (int y = 0; y < (int)m_LM.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2)
			{
				if (!FloatRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE).intersects(previousEmitter))
				{
					vSoundEmitters.push_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

					previousEmitter.left = x * TILE_SIZE;
					previousEmitter.top = y * TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = TILE_SIZE * 6;
				}
			}
		}
	}

	return;
}

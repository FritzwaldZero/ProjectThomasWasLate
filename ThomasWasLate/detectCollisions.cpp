#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal = false;

	// set up basic box collision make a rect for all his parts

	FloatRect detectZone = character.getPosition();

	// make the float rect to test each block 
	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// build a zone around the character to detect collisions
	int startX = (int)(detectZone.left / TILE_SIZE) -1;
	int startY = (int)(detectZone.top / TILE_SIZE) -1;
	int endX = (int)(detectZone.left / TILE_SIZE) +2;
	int endY = (int)(detectZone.top / TILE_SIZE) +3;

	//make sure we dont test positions lower than zero or higher than the end of the array 
	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;
	if (endX >= m_LM.getLevelSize().x) endX = m_LM.getLevelSize().x;
	if (endY >= m_LM.getLevelSize().y) endY = m_LM.getLevelSize().y;

	// has the character fallen out of the map ?
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);

	if (!character.getPosition().intersects(level))
	{
		// respawn the player 
		character.Spawn(m_LM.getStartPosition(), GRAVITY);
	}

	// loop through all of the local blocks 
	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3)
			{
				if (character.getHead().intersects(block))
				{
					character.Spawn(m_LM.getStartPosition(), GRAVITY);

					if (m_ArrayLevel[y][x] == 2)
					{
						// play a sound
						m_SM.PlayFallInFire();
					}
					else
					{
						//play a gargle sound
						m_SM.PlayFallInWater();
					}
				}
			}
			// is the character colliding with regular blocks
			if (m_ArrayLevel[y][x] == 1)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}
				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}
			}

			if (m_ArrayLevel[y][x] == 4)
			{
				//character reached the goal, particles, audio
				reachedGoal = true;

			}
		}
	}

	return reachedGoal;
}
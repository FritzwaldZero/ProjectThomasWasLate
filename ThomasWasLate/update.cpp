#include "Engine.h"
#include <sstream>

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		// these calls to spawn will be moved to a new loadlevel spawn T and B
		loadLevel();
	}
	if (m_IsPlaying)
	{
		//update thomas
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		//detect collisions
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			m_NewLevelRequired = true;

			m_SM.PlayReachGoal();

		}
		else
		{
			detectCollisions(m_Bob);
		}

		// thomas and bob collision 
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

		//count down the time the player has left 
		m_TimeRemaining -= dtAsSeconds;
		//have thomas and bob run out of time
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}// end if playing 

	// set the appropriate view around the apprporiate character 
	if (m_IsSplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		// center full screen around appropriate character 
		if (m_Character1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}

	vector<Vector2f>::iterator it;

	for (it = m_FireEmitters.begin(); it != m_FireEmitters.end(); it++)
	{
		float posX = (*it).x;
		float posY = (*it).y;

		FloatRect localRect(posX - 250, posY - 250, 500, 500);

		if (m_Thomas.getPosition().intersects(localRect))
		{
			m_SM.PlayFire(Vector2f(posX, posY), m_Thomas.getCenter());
		}
	}
}
#include "Engine.h"
#include <sstream>

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		// these calls to spawn will be moved to a new loadlevel spawn T and B
		m_Thomas.Spawn(Vector2f(0, 0), GRAVITY);
		m_Bob.Spawn(Vector2f(100, 0), GRAVITY);
		m_TimeRemaining = 10;
		m_NewLevelRequired = false;
		loadLevel();
	}
	if (m_IsPlaying)
	{
		//update thomas
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);
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
}
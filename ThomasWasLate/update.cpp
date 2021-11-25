#include "Engine.h"
#include <sstream>

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
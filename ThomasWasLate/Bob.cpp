#include "Bob.h"
#include "TextureHolder.h"


Bob::Bob()
{
	// associate a texture with the sprite
	m_Sprite = sf::Sprite(TextureHolder::GetTexture("assets/graphics/bob.png"));
	m_JumpDuration = .25;
}
//a virtual function 
bool Bob::handleInput()
{
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		// start a jump if not already jumping but only if standing on a block, not falling
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
		else
		{
			m_IsJumping = false;
			m_IsFalling = true;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed - false;
	}
	return m_JustJumped;
}

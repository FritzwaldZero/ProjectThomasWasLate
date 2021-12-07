#include "Character.h"

void PlayableCharacter::Spawn(Vector2f startPosition, float gravity)
{
	// place the player at the starting point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;
	//initialise the gravity 
	m_Gravity = gravity;
	//move the srite into position 
	m_Sprite.setPosition(m_Position);

}

void PlayableCharacter::update(float elapsedTime)
{
	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;

	}
	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}

	// handle jumping
	if (m_IsJumping)
	{
		//update how long the jump has been going 
		m_TimeThisJump += elapsedTime;
		//is the jump going upwatds 
		if (m_TimeThisJump < m_JumpDuration)
		{
			// move up at twice gravity
			m_Position.y -= m_Gravity * 2 * elapsedTime;
		}
		else
		{
			m_IsJumping = false;
			m_IsFalling = true;
		}
	}
		//apply gravity 
	if (m_IsFalling)
	{
		m_Position.y += m_Gravity * elapsedTime;
	}
	// update the rect for all body parts
	FloatRect r = getPosition();

	// feet 
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;
	// head
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height * 0.3);
	m_Head.width = r.width;
	m_Head.height = 1;
	//right 
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * 0.35;
	m_Right.width = 1;
	m_Right.height = r.height * 0.3;
	//left 
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * 0.5;
	m_Left.width = 1;
	m_Left.height = r.height * 0.3;
	// mov the sprite into position 
	m_Sprite.setPosition(m_Position);
	


}
FloatRect PlayableCharacter::getPosition()
{
	return m_Sprite.getGlobalBounds();

}
Vector2f PlayableCharacter::getCenter()
{
	return Vector2f(m_Position.x + m_Sprite.getGlobalBounds().width / 2, m_Position.y + m_Sprite.getGlobalBounds().height / 2);

}
FloatRect PlayableCharacter::getFeet()
{
	return m_Feet;
}
FloatRect PlayableCharacter::getHead()
{
	return m_Head;
}
FloatRect PlayableCharacter::getLeft()
{
	return m_Left;
}
FloatRect PlayableCharacter::getRight()
{
	return m_Right;
}
Sprite PlayableCharacter::getSprite()
{
	return m_Sprite;
}

void PlayableCharacter::stopFalling(float position)
{

	m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_IsFalling = false;

}
void PlayableCharacter::stopRight(float position)
{
	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}
void PlayableCharacter::stopLeft(float position)
{

	m_Position.x = position + m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);

}
void PlayableCharacter::stopJump()
{

	//stop a jump early 
	m_IsJumping = false;
	m_IsFalling = true;

}
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
protected:

	// sprite 
	Sprite m_Sprite;
	// how long does the jump last 
	float m_JumpDuration;
	// is the charcter currently jumping or falling
	bool m_IsJumping;
	bool m_IsFalling;
	// how long has this jump lasted for ?
	float m_TimeThisJump;
	//has the player just initiated a jump 
	bool m_JustJumped = false;
	//which direction is the character currently moving in 
	bool m_RightPressed;
	bool m_LeftPressed;

private:
	// what is the gravity 
	float m_Gravity;
	// how fast is the character 
	float m_Speed = 400;
	// where is the player 
	Vector2f m_Position;
	// where are the characters various body parts 
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;
	
	// and a texture 
	Texture m_Texture;

public:

	void Spawn(sf::Vector2f startPosition, float gravity);
	// this is a pure virtual function 
	bool virtual handleInput() = 0;
	// this class is now abstract and cannot be instantiated 
	// where is the player 
	FloatRect getPosition();
	// a rectangle represetning the position 
	//of different parts of the sprite 
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();
	//send a coopy of the sprite to main 
	Sprite getSprite();
	// make the character stand firm
	void stopFalling(float position);
	void stopLeft(float position);
	void stopRight(float position);
	void stopJump();
	//where is the center of the character 
	Vector2f getCenter();
	//we will call this function once every frame
	void update(float elapsedTime);

};


#endif CHARACTER_H

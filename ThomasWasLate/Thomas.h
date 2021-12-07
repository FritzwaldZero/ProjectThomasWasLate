#ifndef THOMAS_H
#define THOMAS_H
#include "Character.h"



class Thomas : public PlayableCharacter
{
public:
	//a constructor specific to Thomas
	Thomas();
	//the overridden input handler for thomas
	bool virtual handleInput();
};
#endif THOMAS_H
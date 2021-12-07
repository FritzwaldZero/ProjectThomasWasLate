#ifndef BOB_H
#define BOB_H
#include "Character.h"



class Bob : public PlayableCharacter
{
public:
	//a constructor specific to Bob
	Bob();
	//the overridden input handler for Bob
	bool virtual handleInput();
};
#endif BOB_H

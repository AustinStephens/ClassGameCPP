//This is the first version of this game, very basic
#ifndef DOT_H
#define DOT_H

#include "DotState.h"

class Dot : public DotState
{
public:
	Dot(Player *p);
	
	void virtual change();
	
    void virtual dotSpell(Player *enemy);
      
};

#endif

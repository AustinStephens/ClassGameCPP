//This is the first version of this game, very basic
#ifndef NODOT_H
#define NODOT_H

#include "DotState.h"

class NoDot : public DotState
{
public:
	NoDot(Player *user);
		
    virtual void dotSpell(Player *enemy);
	  
	virtual void change();
	  
      
};

#endif

//This is the first version of this game, very basic
#ifndef PALADIN_H
#define PALADIN_H

#include "Player.h"
#include <math.h>

class Paladin : public Player
{ 
public:
    Paladin();

    virtual void damageSpell(Player *enemy);
     
    virtual void dotSpell(Player *enemy);
     
    virtual void hosSpell();
     
	virtual void debuffSpell();
      
};

#endif

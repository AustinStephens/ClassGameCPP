//This is the first version of this game, very basic
#ifndef WARLOCK_H
#define WARLOCK_H

#include "Player.h"
#include <math.h>

class Warlock : public Player
{ 
public:
    Warlock();

    virtual void damageSpell(Player *enemy);
     
    virtual void dotSpell(Player *enemy);
     
    virtual void hosSpell();
     
    virtual void debuffSpell(); 
};

#endif

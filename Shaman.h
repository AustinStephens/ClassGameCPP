//This is the first version of this game, very basic
#ifndef SHAMAN_H
#define SHAMAN_H

#include "Player.h"
#include <math.h>

class Shaman : public Player
{   
public:
    Shaman();

    virtual void damageSpell(Player *enemy);
     
    virtual void dotSpell(Player *enemy);
     
    virtual void hosSpell();
     
    virtual void debuffSpell();    
};

#endif

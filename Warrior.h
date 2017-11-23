//This is the first version of this game, very basic
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"

class Warrior : public Player
{
public:
    Warrior();

    void virtual damageSpell(Player *enemy);
     
    void virtual dotSpell(Player *enemy);
     
    void virtual hosSpell();
     
    void virtual debuffSpell();
};

#endif

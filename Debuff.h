//This is the first version of this game, very basic
#ifndef DEBUFF_H
#define DEBUFF_H

#include <math.h>
#include "DebuffState.h"
class Player;

class Debuff : public DebuffState
{
public:
	Debuff(Player *p);
	
	void virtual dmgSpell(Player *enemy, int dmg);
	
	void virtual change();
};

#endif

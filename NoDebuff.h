//This is the first version of this game, very basic
#ifndef NODEBUFF_H
#define NODEBUFF_H

#include "DebuffState.h"

class NoDebuff : public DebuffState
{
public:
	NoDebuff(Player *p);
	void virtual dmgSpell(Player *enemy, int dmg);
	void virtual change();
};

#endif

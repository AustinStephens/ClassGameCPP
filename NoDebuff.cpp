#include "NoDebuff.h"

NoDebuff::NoDebuff(Player *p):DebuffState(p)
{
	
}

void NoDebuff::dmgSpell(Player *enemy, int dmg)
{
	enemy->loseHealth(dmg);	
}

void NoDebuff::change()
{
	return;
}

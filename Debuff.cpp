#include "Debuff.h"

Debuff::Debuff(Player *p):DebuffState(p)
{
	
}
		
void Debuff::dmgSpell(Player *enemy, int dmg)
{
	enemy->loseHealth(floor((float)(dmg * 1.5)));
}

void Debuff::change()
{
	user->setDebuffState(user->noDebuff);
}

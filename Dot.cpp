#include "Dot.h"

Dot::Dot(Player *p): DotState(p)
{
	
}

void Dot::change()
{
	user->setDotState(user->noDot);
}

void Dot::dotSpell(Player *enemy)
{
  user->getDebuffState()->dmgSpell(enemy, user->getDotDmg());
}

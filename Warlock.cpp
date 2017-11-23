#include "Player.h"
#include "Warlock.h"

Warlock::Warlock():Player(15, 15, 5, "warlock.jpg","Fire Ball","fb.jpg","Burn","b.jpg","Death Shield","ds.jpg","Poison","p.jpg", true)
{
           	return;                      
}

void Warlock::damageSpell(Player *enemy)
{
   getDebuffState()->dmgSpell(enemy, getDamage());  // goes to debuff state to determine how much dmg will be dealt
}

void Warlock::dotSpell(Player *enemy)
{
	setDotState(dot);   // sets the state to dot, constructor will reset count
	setDotCount(3);
	getDebuffState()->dmgSpell(enemy, getDotDmg()); //dont need to floor since its integer division 
	//sends the pure damage to debuff state    
}

void Warlock::hosSpell()
{
     gainHealth(getHeal());
}

void Warlock::debuffSpell()
{
	
    setDebuffState(debuff);  // sets the state to debuff, constructor will reset count
    setDebuffCount(3);
}

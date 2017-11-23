#include "Player.h"
#include "Shaman.h"

Shaman::Shaman():Player(12, 18, 7, "shaman.jpg","Lava Bolt","lb.jpg","Frost Bite","frostb.jpg","Restore Spirit","restsp.jpg","Curse","curse.jpg", false)
{
   	return;                      
}

void Shaman::damageSpell(Player *enemy)
{
   getDebuffState()->dmgSpell(enemy, getDamage());  // goes to debuff state to determine how much dmg will be dealt
}

void Shaman::dotSpell(Player *enemy)
{
	setDotState(dot);   // sets the state to dot, constructor will reset count
	setDotCount(3);
	getDebuffState()->dmgSpell(enemy, getDotDmg()); //dont need to floor since its integer division 
	//sends the pure damage to debuff state    
}

void Shaman::hosSpell()
{
     gainHealth(getHeal());
}

void Shaman::debuffSpell()
{
	
    setDebuffState(debuff);  // sets the state to debuff, constructor will reset count
    setDebuffCount(3);
}

#include "Player.h"
#include "Warrior.h"

Warrior::Warrior():Player(20, 12, 3, "warrior.jpg","Stab","s.jpg","Bleed","bleed.jpg","Armor Up","au.jpg","Disarm","disarm.jpg", true)
{
                                 
}

void Warrior::damageSpell(Player *enemy)
{
   getDebuffState()->dmgSpell(enemy, getDamage());  // goes to debuff state to determine how much dmg will be dealt
}

void Warrior::dotSpell(Player *enemy)
{
	setDotState(dot);   // sets the state to dot, constructor will reset count
	setDotCount(3);
	getDebuffState()->dmgSpell(enemy, getDotDmg()); //dont need to floor since its integer division 
	//sends the pure damage to debuff state     
}

void Warrior::hosSpell()
{
     gainHealth(getHeal());
}

void Warrior::debuffSpell()
{
	
    setDebuffState(debuff);  // sets the state to debuff, constructor will reset count
    setDebuffCount(3);
}

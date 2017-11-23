#include "Player.h"
#include "Paladin.h"

Paladin::Paladin():Player(10, 20, 9, "paladin.jpg","Smite","smite.jpg","Holy Wrath","hw.jpg","Cleanse Soul","cleanseSoul.jpg","Curse Soul","curseSoul.jpg", false)
{
   	return;                      
}

void Paladin::damageSpell(Player *enemy)
{
   getDebuffState()->dmgSpell(enemy, getDamage());  // goes to debuff state to determine how much dmg will be dealt
}

void Paladin::dotSpell(Player *enemy)
{
	setDotState(dot);   // sets the state to dot, constructor will reset count
	setDotCount(3);
	getDebuffState()->dmgSpell(enemy, getDotDmg()); //dont need to floor since its integer division 
	//sends the pure damage to debuff state    
}

void Paladin::hosSpell()
{
     gainHealth(getHeal());
}

void Paladin::debuffSpell()
{
	
    setDebuffState(debuff);  // sets the state to debuff, constructor will reset count
    setDebuffCount(3);
}

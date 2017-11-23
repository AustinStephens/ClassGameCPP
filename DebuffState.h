//This is the first version of this game, very basic
#ifndef DEBUFFSTATE_H
#define DEBUFFSTATE_H

class Player;

class DebuffState
{
public:
	Player *user;
	
	DebuffState(Player *p);
	
  	void virtual dmgSpell(Player *enemy, int dmg) = 0;
  
  	void virtual change() = 0;
      
};

#endif

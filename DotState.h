//This is the first version of this game, very basic
#ifndef DOTSTATE_H
#define DOTSTATE_H

class Player;

class DotState
{
public:
	Player *user;
	
	DotState(Player *p);
	
    void virtual dotSpell(Player *enemy) = 0;
    
    void virtual change() = 0;
	    
      
};

#endif

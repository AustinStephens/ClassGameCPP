//This is the first version of this game, very basic.
// Making all the spells virtual because I assume I'll add some variability in future versions
// so I'm opening it to changes
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "DotState.h"
#include "Dot.h"
#include "NoDot.h"
#include "DebuffState.h"
#include "Debuff.h"
#include "NoDebuff.h"


using std::string;

class Player
{
	  private:
	  	//Name is name of spell, icon is the name of the file that contains the picture displayed for the spell
	    int health;
	    string classIcon;
	    int damage;
	    int dotDmg;
	    int heal;
	    bool shield; // whether or not the heal spell is a shield or a heal. Doesnt need a getter or setter because we never use it outside the class.
	      
	    //state properties
	    DotState *dotState;   //use state pattern to tell if dots are in effect, and debuffs
	    DebuffState *debuffState;
	      
	//spell 1
	    string damageName;
	    string damageIcon;
	//spell 2
	    string dotName;
	    string dotIcon;
	//spell 3
	    string hosName; //hos = healing or sheild
	    string hosIcon; //Warlock and Warrior have shield, Paladin and Shaman have healing
	//spell 4
	    string debuffName; 
	    string debuffIcon;
	//other properties
		int debuffCount;
		int dotCount;
		  
	public:
		// state properties
		NoDebuff *noDebuff;  //seems useless to add setters and getters, might make public if needed
	    Debuff *debuff;
	    NoDot *noDot;
	    Dot *dot;
	      
	    //functions
	    Player(int dmg, int h, int dd, string ci, string dn, string di, string don, string doi, string hn, string hi, string den, string dei, bool s);
	
			
	    virtual void damageSpell(Player *enemy) = 0; //spell 1
	    virtual void dotSpell(Player *enemy) = 0; //spell 2
	    virtual void hosSpell() = 0; //spell 3
	    virtual void debuffSpell() = 0; //spell 4
	      
	      
	    // getters for states
	    DotState * getDotState();
	      		
	    DebuffState * getDebuffState();
	      		
	    // settersr for states
	    void setDotState(DotState *dotS);
	      
	    void setDebuffState (DebuffState *debuffS);
	    	
	    // getters
	    int getHealth() const;
	    string getClassIcon() const;
	    int getDamage() const;
	    int getDotDmg() const;
	    int getHeal() const;
	      
	    string getDamageName() const;
	    string getDamageIcon() const;
	      
	    string getDotIcon() const;
	    string getDotName() const;
	             
	    string getHosName() const;
	    string getHosIcon() const;
	             
	    string getDebuffName() const;
	    string getDebuffIcon() const;
	      
	    int getDebuffCount() const;
	      		 
		int getDotCount() const;
	      		 
	    // setters
	    void loseHealth(int hpLost);
		
		void gainHealth(int hpGained);
	      
	    void setHealth(int hp);
	    void setClassIcon(string icon);
	           
	    void setDamage(int dmg);
		
		void setDotDmg(int dd);
		
		void setHeal(int h);
	      
	    void setDamageName(string name);
	    void setDamageIcon(string icon);
	      
	    void setDotIcon(string icon);
	    void setDotName(string name);
	             
	    void setHosName(string name);
	    void setHosIcon(string icon);
	             
	    void setDebuffName(string name);
	    void setDebuffIcon(string icon);
	      
	    void setDebuffCount(int count);
		void setDotCount(int count);
				
		void updateCounts();
		  

};



#endif

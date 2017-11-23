#include "Player.h"
#include "DebuffState.h"
#include "Debuff.h"
#include "NoDebuff.h"
#include "DotState.h"
#include "Dot.h"
#include "NoDot.h"
#include <string>

Player::Player(int dmg, int h, int dd, string ci, string dn, string di, string don, string doi, string hn, string hi, string den, string dei, bool s)
{
    setHealth(100);
    setDamage(dmg);
    setHeal(h);
    setDotDmg(dd);
    setClassIcon(ci);
    setDamageName(dn);
    setDamageIcon(di);
    setDotName(don);
    setDotIcon(doi);
    setHosName(hn);
    setHosIcon(hi);
    setDebuffName(den);
    setDebuffIcon(dei);
    
    shield = s;
       
    //initializing the different states
    noDot = new NoDot(this);
    dot = new Dot(this);
    noDebuff = new NoDebuff(this);
    debuff = new Debuff(this);
       
    setDebuffState(noDebuff);
    setDotState(noDot);
}

//accessor for states
DotState * Player::getDotState()
  	{ return dotState;}
  		
DebuffState * Player::getDebuffState()
  	{ return debuffState; }
  		
// mutators for states
void Player::setDotState(DotState *dotS)
	{ dotState = dotS;}
  
void Player::setDebuffState (DebuffState *debuffS)
	{ debuffState = debuffS; }
	
//accessors
int Player::getHealth() const
    {return health;}
string Player::getClassIcon() const
    {return classIcon;}
int Player::getDamage() const
  	{ return damage; }
int Player::getDotDmg() const
  	{ return dotDmg; }
int Player::getHeal() const
  	{ return heal; }
  
string Player::getDamageName() const
    {return damageName;}
string Player::getDamageIcon() const
    {return damageIcon;}
  
string Player::getDotIcon() const
    {return dotIcon;}
string Player::getDotName() const
    {return dotName;}
         
string Player::getHosName() const
    {return hosName;}
string Player::getHosIcon() const
    {return hosIcon;}
         
string Player::getDebuffName() const
    {return debuffName;}
string Player::getDebuffIcon() const
    {return debuffIcon;}
int Player::getDebuffCount() const
  	{return debuffCount; }
  		 
int Player::getDotCount() const
	{return dotCount;}
  		 
//mutators
void Player::loseHealth(int hpLost)
{
	setHealth(getHealth() - hpLost);
}

void Player::gainHealth(int hpGained)
{
	if(shield || getHealth() + hpGained <= 100)
		setHealth(getHealth() + hpGained);
	else
		setHealth(100);
}
  
void Player::setHealth(int hp)
{
    if (hp < 0) hp = 0;
    health = hp;
}
void Player::setClassIcon(string icon)
    {classIcon = icon;}
       
void Player::setDamage(int dmg)
	{ damage = dmg; }

void Player::setDotDmg(int dd)
	{ dotDmg = dd; }

void Player::setHeal(int h)
	{ heal = h; }
  
void Player::setDamageName(string name)
    {damageName = name;}
void Player::setDamageIcon(string icon)
    {damageIcon = icon;}
  
void Player::setDotIcon(string icon)
    {dotIcon = icon;}
void Player::setDotName(string name)
    {dotName = name;}
         
void Player::setHosName(string name)
    {hosName = name;}
void Player::setHosIcon(string icon)
    {hosIcon = icon;}
         
void Player::setDebuffName(string name)
    {debuffName = name;}
void Player::setDebuffIcon(string icon)
    {debuffIcon = icon;}

void Player::setDebuffCount(int count) 
{
	if(count <= 0)           //if the count is under 0
	{
		count = 0;
		getDebuffState()->change();           //call the change method
	}                                 //if its already in no-dot, change doesnt do anything; if in dot, change changes dot-state to no-dot
	debuffCount = count;
}
void Player::setDotCount(int count)
{ 
	if(count <= 0)
	{
		count = 0;
		getDotState()->change();         //same for above; nodebuff doesnt do anything; debuff changes to nodebuff
	}
	dotCount = count;
}
	
void Player::updateCounts()
{
	setDebuffCount(getDebuffCount() - 1);
  	setDotCount(getDotCount() - 1);
}

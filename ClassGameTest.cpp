// Testing the object oriented aspects of the class game in a console.
// This is the c++ version of the class game, no gui, completely text based.
// Rewrote it in java, with a gui. It's named "Java Class Game".
// /**/ means there is a printline that is helping find where a bug is.

// Also, before looking at this code please know I originally made this in Dev C++, I dont use Dev C++ anymore
// because it thinks indenting code with spaces is somehow acceptable. If you see any space indented code - just know I hate it just as much as you do.

/*	
Summary:
	You can pick a class: Warlock, Paladin, Shaman, or Warrior.
	You have 4 spells (right now they are all the same concept, might change in future)
		#1. A straight damage spell.
		#2. A dot, deals some damage at first, and for a certain amount of turns it will deal damage at the beginning of the turn.
		#3. A healing spell for Paladins and Shamans, a shield for Warrior and Warlocks, shield can make your hp go past 100.
		#4. A debuff casted on the other player, you deal more damage and dot damage against them.
	The enemy casts a random spell, will eventually add some AI so its not a cakewalk, might even add difficulty levels, so easy = random, normal = some AI, hard = intelligent AI.
	
	Once someones health drops to 0 or below, game is over, if both die in the same turn, the opponent dies since the player goes first, meaning the opponent would be dead before they killed the player.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "Player.h"
#include "Warlock.h"
#include "Warrior.h"
#include "Shaman.h"
#include "Paladin.h"

#include "DebuffState.h"
#include "Debuff.h"
#include "NoDebuff.h"
#include "DotState.h"
#include "Dot.h"
#include "NoDot.h"

#include "Player.cpp"
#include "Warlock.cpp"
#include "Warrior.cpp"
#include "Shaman.cpp"
#include "Paladin.cpp"
#include "DebuffState.cpp"
#include "Debuff.cpp"
#include "NoDebuff.cpp"
#include "DotState.cpp"
#include "Dot.cpp"
#include "NoDot.cpp"


using std::cout; // trying to stay away from using "using namespace std;" because most people think its bad practice.
using std::cin;
using std::endl;

int main()
{
	char flagChar;
	
	while (flagChar != 'n')
	{
		Player *user;
		Player *enemy;
		char classInt;
		int num;              
		
		// player chooses class
		do
		{
			cout << "Choose Class: 1. Warlock  2. Warrior  3. Shaman  4. Paladin" << endl;
			cin >> classInt;
			num = classInt - '0';
//**/		cout << num << endl;
		} while (num < 1 || num > 4);
		
		// switch to determine class
		switch (num)
		{
			case 1:
				user = new Warlock();
				break;
			case 2:
				user = new Warrior();
				break;
			case 3:
				user = new Shaman();
				break;
			case 4:
				user = new Paladin();
				break;
			default: break;
		}
                                      
		time_t timer;																			    
		srand(time(&timer));															  
		num = rand() % 4 + 1;
		
//**/	cout << num << endl;
		
		// randomly generates enemy class
		cout << "Your enemy is a ";
		switch (num){
			case 1:
				enemy = new Warlock();
				cout << "Warlock";
				break;
			case 2:
				enemy = new Warrior();
				cout << "Warrior";
				break;
			case 3:
				enemy = new Shaman();
				cout << "Shaman";
				break;
			case 4:
				enemy = new Paladin();
				cout << "Paladin";
				break;
			default: break;
		}
		cout << endl;
		
		Sleep(1000);
		
		// game loop
		while (user->getHealth() > 0 && enemy->getHealth() > 0)
		{
			// updates
			user->updateCounts();
			enemy->updateCounts();
			user->getDotState()->dotSpell(enemy);
			enemy->getDotState()->dotSpell(user);
			// player chooses spell
			do
			{	
				cout << "Pick a spell: 1. " << user->getDamageName() << "  2. " << user->getDotName() << "  3. " << user->getHosName() << "  4. " << user->getDebuffName() << endl;
				cin >> classInt;
				num = classInt - '0';
//**/			cout << num << endl;
			}while (num < 1 || num > 4);
			
			// switch to determine what spell was chosen and use it.
			switch (num) 
			{
				case 1: 
					user->damageSpell(enemy);
					break;
				case 2:
					user->dotSpell(enemy);
					break;
				case 3: 
					user->hosSpell();
					break;
				case 4: 
					user->debuffSpell();
					break;
				default: break;
			}
			
			// randomy generates enemy attack, should add some ai to this
			srand(time(&timer));															  
			num = rand() % 4 + 1; // dont really need to add 1, but I did it to match the switch statement above.
			
//**/		cout << num << endl;
			
			switch (num)
			{
				case 1:
					enemy->damageSpell(user);
					cout << "Enemy used " << enemy->getDamageName() << endl;
					break;
				case 2:
					enemy->dotSpell(user);
					cout << "Enemy used " << enemy->getDotName() << endl;
					break;
				case 3:
					enemy->hosSpell();
					cout << "Enemy used " << enemy->getHosName() << endl;
					break;
				case 4:
					enemy->debuffSpell();
					cout << "Enemy used " << enemy->getDebuffName() << endl;
					break;
				default: break;
			}
			
			cout << "Your health: " << user->getHealth() << endl;
			cout << "Opponents health: "<< enemy->getHealth() << endl;
		}		
		
		if (enemy->getHealth() <= 0) cout << "opponent died" << endl;       //based off of who went second, if they died they were hit first, so they died first
		else cout << "you died" << endl;
		
		
		
		cout << endl << "Want another? (n to exit)" << endl;
		cin >> flagChar;
		
		cin.ignore();	
		
	} 
	
	return 0;
}

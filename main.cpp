#include <iostream>
#include "army.h"


int main()
{
	Army human{0, 0, 0.6f, 250.0f, 200.0f, 250.0f};
	
	Army skeleton{0, 0, 0.4f, 120.0f, 110.0f, 120.0f};

	printStartupScreen();
	
	getNumberOfArmy(human.armyAmount, skeleton.armyAmount);
	
	human.startArmyAmount = human.armyAmount;
	skeleton.startArmyAmount = skeleton.armyAmount;
	

	float attackResult{};
	char turn = 'H';
	
	gameLoop(human, skeleton, attackResult, turn);
	
	printWinner(human.armyAmount, skeleton.armyAmount, human.startArmyAmount, skeleton.startArmyAmount);
	
	
   return 0;
}

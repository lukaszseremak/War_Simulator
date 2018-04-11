#include "army.h"

//chance of success an attack
std::mt19937 randomGenerator(time(NULL));
std::uniform_real_distribution<float> attackRoll(0.0f, 1.0f);

void printStartupScreen()
{
    cout << "### Sketetons vs Humans! ###"<< "\n";
	
}

void getNumberOfArmy(int& humanArmy, int& skeletonArmy)
{
    //get number of humans
    cout << "Enter the number of humans: ";
    cin >> humanArmy;
    
    //get number of skeltons
    cout << "Enter the number of skeletons: ";
    cin >> skeletonArmy;
}


void gameLoop(Army& _human, Army& _skeleton, float& attackResult, char& turn)
{
    // a check is a game over 
    while((_human.armyAmount > 0) && (_skeleton.armyAmount > 0))
    {
    	attackResult = attackRoll(randomGenerator);
    	
    	if(turn == 'H')
    	{
    	    if(attackResult <= _human.attack)
    	    {
    	        _skeleton.currentHealth -= _human.danmage;
    			
    		if(_skeleton.currentHealth < 0)
    		{
    		    _skeleton.armyAmount--;
    		    _skeleton.currentHealth = _skeleton.health;
    		}
    	    }
    	    //change to skeletons turn
    	    turn = 'S';	
    	}
    	
    	else
    	{
    	    if(attackResult <= _skeleton.attack)
    	    {
    	        _human.currentHealth -= _skeleton.danmage;
    			
    		if(_human.currentHealth < 0)
    		{
    		    _human.armyAmount--;
    		    _human.currentHealth = _human.health;
    		}
    	    }
    	    //change to human turn
    	    turn = 'H';	
    	}
    }	
}


void printWinner(const int& humanArmy, const int& skeletonArmy, const int& humanStartArmyAmount, const int& skeletonStartArmyAmount )
{
    cout << "The battle is over!!!\n";
	
    if(humanArmy > 0)
    	cout << "Humans wins. \n";
    
    else if(skeletonArmy > 0)
    	cout << "Skeleton wins.\n";	
    
    cout << "Number of humans left : " << humanArmy << '\n';
    cout << "Died: " << humanStartArmyAmount - humanArmy << '\n';
    cout << "Number of skeletons left : " << skeletonArmy << '\n';	
    cout << "Died: " << skeletonStartArmyAmount - skeletonArmy << '\n';
}

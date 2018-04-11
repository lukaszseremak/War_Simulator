#pragma once

#include <iostream>
#include <random>
#include <ctime>

using std::cout;
using std::cin;


struct Army
{
    int armyAmount;
    int startArmyAmount;
    float attack;
    float health;
    float danmage;
    float currentHealth;
};


void printStartupScreen();
void getNumberOfArmy(int& humanArmy, int& skeletonArmy);
void gameLoop(Army& _human, Army& _skeleton, float& attackResult, char& turn);
void printWinner(const int& humanArmy, const int& skeletonArmy, const int& humanStartArmyAmount, const int& skeletonStartArmyAmount );

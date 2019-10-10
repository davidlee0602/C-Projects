/*********************************************************************
** Program name: BlueMen.cpp
** Author: David Lee
** Date: 05/08/2019
** Description: Implementation file for the BlueMen class. Inherits from base class, Character.
 * It has a constructor that initializes the data members from the Character class.
 * [attack() and defend() functions are pure virtual functions from the Character class.]
 * BlueMen special ability: [Mob] Blue Men are actually a swarm of small individuals.
 * For every 4 points of damage, they lose one defense die. For example, if they have a strength of 8, they would have 2d6 for defense.
*********************************************************************/

#include "BlueMen.hpp"
#include <string>
#include <iostream>
#include <cmath>
using std::string;
using std::cout;
using std::endl;

BlueMen::BlueMen() : Character("BlueMen", 2, 10, 3, 6, 3, 12){ //inherits from Character class

}

BlueMen::~BlueMen() { //destructor
    cout << "BlueMen object deleted" << endl;
}

int BlueMen::attack(){ //attack function override
    int attackDamage = 0;
    for (int i = 0; i < getAttackDieCount(); i++) {
        int attackRoll = rand() % getAttackSides() + 1;
        cout << "Attack roll #" << i+1 << ": " << attackRoll << endl;
        attackDamage += attackRoll;
    }
    cout << "Attack roll total: " << attackDamage << endl;
    return attackDamage;
}
void BlueMen::defend(int attackDamage){ //defend function override
    int defendAmount = 0;
    int damageTaken = 0;
    setDefenseDieCount(ceil(static_cast<double>(getStrengthPoints()/4.0)));
    cout << "Blue Men[Mob] defense die count: " << getDefenseDieCount() << endl;
    for (int i = 0; i < getDefenseDieCount(); i++) {
        int defenseRoll = rand() % getDefenseSides() + 1; //defense die count goes down as BlueMen take damage
        cout << "Defense roll #" << i+1 << ": " << defenseRoll << endl;
        defendAmount += defenseRoll;
    }
    cout << "Defense roll total: " << defendAmount << endl;
    damageTaken = attackDamage - defendAmount - getArmorPoints();
    if(damageTaken > 0){
        cout << "Total Damage taken: " << damageTaken << endl;
        if((getStrengthPoints() - damageTaken) >= 0){
            setStrengthPoints(getStrengthPoints() - damageTaken);
        }else{
            cout <<"OVERKILL: Strength falls to floor amount 0." << endl;
            setStrengthPoints(0);
        }
    }else{
        cout << "Defence and Armor blocks attack damage. No Damage Taken." << endl;
    }
}

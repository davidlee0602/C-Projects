/*********************************************************************
** Program name: Barbarian.cpp
** Author: David Lee
** Date: 05/08/2019
** Description: Implementation file for the Barbarian class. Inherits from base class, Character.
 * It has a constructor that initializes the data members from the Character class.
 * [attack() and defend() functions are pure virtual functions from the Character class.]
*********************************************************************/

#include "Barbarian.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

Barbarian::Barbarian() : Character("Barbarian", 2, 6, 2, 6, 0, 12){ //inherits from Character class

}
Barbarian::~Barbarian(){ //destructor
    cout << "Barbarian object deleted" << endl;
}
int Barbarian::attack(){ //attack function override
    int attackDamage = 0;
    for (int i = 0; i < getAttackDieCount(); i++) {
        int attackRoll = rand() % getAttackSides() + 1;
        cout << "Attack roll #" << i+1 << ": " << attackRoll << endl;
        attackDamage += attackRoll;
    }
    cout << "Attack roll total: " << attackDamage << endl;
    return attackDamage;
}
void Barbarian::defend(int attackDamage){ //defend function override
    int defendAmount = 0;
    int damageTaken = 0;
    for (int i = 0; i < getDefenseDieCount(); i++) {
        int defenseRoll = rand() % getDefenseSides() + 1;
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

/*********************************************************************
** Program name: Vampire.cpp
** Author: David Lee
** Date: 05/08/2019
** Description: Implementation file for the Vampire class. Inherits from base class, Character.
 * It has a constructor that initializes the data members from the Character class.
 * [attack() and defend() functions are pure virtual functions from the Character class.]
 * Vampire special ability: [Charm] Vampires can charm an opponent into not attacking.
 * For a given attack there is a 50% chance that their opponent does not actually attack them.
*********************************************************************/


#include "Vampire.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

Vampire::Vampire() : Character("Vampire", 1, 12, 1, 6, 1, 18){ //inherits from Character class

}

Vampire::~Vampire(){ //destructor
    cout << "Vampire object deleted" << endl;
}

int Vampire::attack(){ //attack function override
    int attackDamage = 0;
    for (int i = 0; i < getAttackDieCount(); i++) {
        int attackRoll = rand() % getAttackSides() + 1;
        cout << "Attack roll #" << i+1 << ": " << attackRoll << endl;
        attackDamage += attackRoll;
    }
    cout << "Attack roll total: " << attackDamage << endl;
    return attackDamage;
}
void Vampire::defend(int attackDamage){ //defend function override
    int charmRoll = rand() % 2;//charm roll used to determine if vampire takes damage
    if (charmRoll == 0){
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
    else if (charmRoll == 1){ //charmRoll == 1
        cout << "[Charm] Activated! Vampire takes no damage." << endl; //no defense roll takes place
    }
    else{
        cout << "Error" << endl;
    }
}

/*********************************************************************
** Program name: Medusa.cpp
** Author: David Lee
** Date: 05/08/2019
** Description: Implementation file for the Medusa class. Inherits from base class, Character.
 * It has a constructor that initializes the data members from the Character class.
 * [attack() and defend() functions are pure virtual functions from the Character class.]
 * Medusa special ability: [Glare] If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins!
 * If Medusa uses Glare on Harry Potter on his first life, then Harry Potter comes back to life.
*********************************************************************/

#include "Medusa.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

Medusa::Medusa() : Character("Medusa", 2, 6, 1, 6, 3, 8){ //inherits from Character class

}

Medusa::~Medusa(){ //destructor
    cout << "Medusa object deleted" << endl;
}

int Medusa::attack(){ //attack function override
    int attackDamage = 0;
    for (int i = 0; i < getAttackDieCount(); i++) {
        int attackRoll = rand() % getAttackSides() + 1;
        cout << "Attack roll #" << i+1 << ": " << attackRoll << endl;
        attackDamage += attackRoll;
    }
    if (attackDamage == 12){ //instant kill ability if Medusa rolls 12
        attackDamage = 100;
        cout << "[Glare] Activated. Medusa instantly petrifies enemy. (*Attack roll becomes 100)" << endl;
    }
    cout << "Attack roll total: " << attackDamage << endl;
    return attackDamage;
}

void Medusa::defend(int attackDamage){ //defend function override
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

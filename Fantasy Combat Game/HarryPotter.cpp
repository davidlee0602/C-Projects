/*********************************************************************
** Program name: HarryPotter.cpp
** Author: David Lee
** Date: 05/08/2019
** Description: Implementation file for the HarryPotter class. Inherits from base class, Character.
 * It has a constructor that initializes the data members from the Character class.
 * [attack() and defend() functions are pure virtual functions from the Character class.]
 * Additionally, it contains a data member purely used within the class to allow for HarryPotter Hogwarts ability.
 * HarryPotter special ability: [Hogwarts] If Harry Potter's strength reaches 0 or below,
 * he immediately recovers and his total strength becomes 20. If he were to die again, then he’s dead.
*********************************************************************/


#include "HarryPotter.hpp"
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

HarryPotter::HarryPotter() : Character("HarryPotter", 2, 6, 2, 6, 0, 10){ //inherits from Character class
    hogwarts = true;
}

HarryPotter::~HarryPotter() { //destructor
    cout << "HarryPotter object deleted" << endl;
}

int HarryPotter::attack(){ //attack function override
    int attackDamage = 0;
    for (int i = 0; i < getAttackDieCount(); i++) {
        int attackRoll = rand() % getAttackSides() + 1;
        cout << "Attack roll #" << i+1 << ": " << attackRoll << endl;
        attackDamage += attackRoll;
    }
    cout << "Attack roll total: " << attackDamage << endl;
    return attackDamage;
}
void HarryPotter::defend(int attackDamage){ //defend function override
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
    if(getStrengthPoints() <= 0 && hogwarts){ //revives with 20 strength points after dying once
        cout << "[Hogwarts] Activated! Harry Potter revives with 20 strength points." << endl;
        setStrengthPoints(20);
        hogwarts = false;
    }
}

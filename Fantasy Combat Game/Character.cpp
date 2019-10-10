/*********************************************************************
** Program name: Character.cpp
** Author: David Lee
** Date: 05/08/2019
** Description: Abstract, Base class for the program where Barbarian, BlueMen, HarryPotter, Medusa and Vampire inherits from.
 * This is the implementation file for the Character class. Has constructor, destructor, pure virtual attack and defend functions and
 * accessor and mutator functions.
*********************************************************************/

#include "Character.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <random>
using std::string;
using std::cout;
using std::endl;

Character::Character(string type, int attackDieCount, int attackSides, int defenseDieCount, int defenseSides, int armorPoints, int strengthPoints){ //constructor
    this->type = type;
    this->attackDieCount = attackDieCount;
    this->attackSides = attackSides;
    this->defenseDieCount = defenseDieCount;
    this->defenseSides = defenseSides;
    this->armorPoints = armorPoints;
    this->strengthPoints = strengthPoints;
    srand(time(0));
}

//attack and defend members functions implement polymorphism

Character::~Character(){ //destructor
    cout << "Character object deleted" << endl;
}

int Character::attack(){ //pure virtual attack function
    int attackDamage = 0;
    for (int i = 0; i < getAttackDieCount(); i++) {
        int attackRoll = rand() % getAttackSides() + 1;
        cout << "Attack roll #" << i+1 << ": " << attackRoll << endl;
        attackDamage += attackRoll;
    }
    cout << "Attack roll total: " << attackDamage << endl;
    return attackDamage;
}

void Character::defend(int attackDamage){ //pure virtual defend function
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
        cout << "Defence and armor blocks attack damage. No Damage Taken." << endl;
    }
}

//accessor
string Character::getType(){
    return type;
} //returns type

int Character::getAttackDieCount(){
    return attackDieCount;
} //returns die count

int Character::getAttackSides(){
    return attackSides;
} //returns die sides

int Character::getDefenseDieCount(){
    return defenseDieCount;
} //returns die count

int Character::getDefenseSides(){
    return defenseSides;
} //returns die sides

int Character::getArmorPoints(){
    return armorPoints;
} // returns armor points

int Character::getStrengthPoints(){
    return strengthPoints;
} //returns strength or life points


//mutator
void Character::setType(string type){
    this->type = type;
} //returns type

void Character::setAttackDieCount(int attackDieCount){
    this->attackDieCount = attackDieCount;
} //returns die count

void Character::setAttackSides(int attackSides){
    this->attackSides = attackSides;
} //returns die sides

void Character::setDefenseDieCount(int defenseDieCount){
    this->defenseDieCount = defenseDieCount;
} //returns die count

void Character::setDefenseSides(int defenseSides){
    this->defenseSides = defenseSides;
} //returns die sides

void Character::setArmorPoints(int armorPoints){
    this->armorPoints = armorPoints;
} // returns armor points

void Character::setStrengthPoints(int strengthPoints){
    this->strengthPoints = strengthPoints;
} //returns strength or life points
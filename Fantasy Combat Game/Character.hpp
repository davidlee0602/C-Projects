/*********************************************************************
** Program name: Character.hpp
** Author: David Lee
** Date: 05/08/2019
** Description: Abstract, Base class for the program where Barbarian, BlueMen, HarryPotter, Medusa and Vampire inherits from.
 * This is the header file for the Character class. Has constructor, destructor, pure virtual attack and defend functions and
 * accessor and mutator functions.
*********************************************************************/


#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
using std::string;

class Character {
private:
    string type; //stores character type
    int attackDieCount; //stores attack die count
    int attackSides; //stores sides to attack die count
    int defenseDieCount; //stores defense die count
    int defenseSides; //stores sides to defense die count
    int armorPoints; //stores character armor points
    int strengthPoints; //stores character strength points
public:
    Character(string type, int attackDieCount, int attackSides, int defenseDieCount, int defenseSides, int armorPoints, int strengthPoints); //constructor
    ~Character(); //destructor
    //attack and defend members functions implement polymorphism
    virtual int attack() = 0; //pure virtual attack function
    virtual void defend(int attackDamage) = 0; //pure virtual defend function that takes attackDamage as parameter

    //accessor
    virtual string getType(); //returns type
    virtual int getAttackDieCount(); //returns die count
    virtual int getAttackSides(); //returns die sides
    virtual int getDefenseDieCount(); //returns die count
    virtual int getDefenseSides(); //returns die sides
    virtual int getArmorPoints(); // returns armor points
    virtual int getStrengthPoints(); //returns strength or life points

    //mutator
    virtual void setType(string type); //set type
    virtual void setAttackDieCount(int attackDieCount); //set die count
    virtual void setAttackSides(int attackSides); //set die sides
    virtual void setDefenseDieCount(int defenseDieCount); //set die count
    virtual void setDefenseSides(int defenseSides); //set die sides
    virtual void setArmorPoints(int armorPoints); // set armor points
    virtual void setStrengthPoints(int strengthPoints); //set strength or life points
};


#endif

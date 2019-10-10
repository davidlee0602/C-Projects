/*********************************************************************
** Program name: Barbarian.hpp
** Author: David Lee
** Date: 05/08/2019
** Description: Header file for the Barbarian class. Inherits from base class, Character.
 * It has a constructor that initializes the data members from the Character class.
 * [attack() and defend() functions are pure virtual functions from the Character class.]
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Character.hpp"
#include <string>
using std::string;

class Barbarian : public Character{ //inherits from Character class
public:
    Barbarian(); //constructor
    ~Barbarian(); //destructor
    int attack() override ; //attack function override
    void defend(int attackDamage) override ; //defend function override
};


#endif
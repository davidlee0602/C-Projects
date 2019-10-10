/*********************************************************************
** Program name: Vampire.hpp
** Author: David Lee
** Date: 05/08/2019
** Description: Header file for the Vampire class. Inherits from base class, Character.
 * It has a constructor that initializes the data members from the Character class.
 * [attack() and defend() functions are pure virtual functions from the Character class.]
 * Vampire special ability: [Charm] Vampires can charm an opponent into not attacking.
 * For a given attack there is a 50% chance that their opponent does not actually attack them.
*********************************************************************/


#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"
#include <string>
using std::string;

class Vampire : public Character{ //inherits from Character class
public:
    Vampire(); //constructor
    ~Vampire(); //destructor
    int attack() override ; //attack function override
    void defend(int attackDamage) override ; //defend function override
};


#endif
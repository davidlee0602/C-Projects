/*********************************************************************
** Program name: Medusa.hpp
** Author: David Lee
** Date: 05/08/2019
** Description: Header file for the Medusa class. Inherits from base class, Character.
 * It has a constructor that initializes the data members from the Character class.
 * [attack() and defend() functions are pure virtual functions from the Character class.]
 * Medusa special ability: [Glare] If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins!
 * If Medusa uses Glare on Harry Potter on his first life, then Harry Potter comes back to life.
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Character.hpp"
#include <string>
using std::string;

class Medusa : public Character{ //inherits from Character class
public:
    Medusa(); //constructor
    ~Medusa(); //destructor
    int attack() override ; //attack function override
    void defend(int attackDamage) override ; //defend function override
};


#endif
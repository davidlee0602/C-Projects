/*********************************************************************
** Program name: BlueMen.hpp
** Author: David Lee
** Date: 05/08/2019
** Description: Header file for the BlueMen class. Inherits from base class, Character.
 * It has a constructor that initializes the data members from the Character class.
 * [attack() and defend() functions are pure virtual functions from the Character class.]
 * BlueMen special ability: [Mob] Blue Men are actually a swarm of small individuals.
 * For every 4 points of damage, they lose one defense die. For example, if they have a strength of 8, they would have 2d6 for defense.
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"
#include <string>
using std::string;

class BlueMen : public Character{ //inherits from Character class
public:
    BlueMen(); //constructor
    ~BlueMen(); //destructor
    int attack() override ; //attack function override
    void defend(int attackDamage) override ; //defend function override
};


#endif
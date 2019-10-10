/*********************************************************************
** Program name: HarryPotter.hpp
** Author: David Lee
** Date: 05/08/2019
** Description: Header file for the HarryPotter class. Inherits from base class, Character.
 * It has a constructor that initializes the data members from the Character class.
 * [attack() and defend() functions are pure virtual functions from the Character class.]
 * Additionally, it contains a data member purely used within the class to allow for HarryPotter Hogwarts ability.
 * HarryPotter special ability: [Hogwarts] If Harry Potter's strength reaches 0 or below,
 * he immediately recovers and his total strength becomes 20. If he were to die again, then he’s dead.
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Character.hpp"
#include <string>
using std::string;

class HarryPotter : public Character{ //inherits from Character class
private:
    bool hogwarts; //flag to check if hogwarts ability was previously triggered
public:
    HarryPotter(); //constructor
    ~HarryPotter(); //destructor
    int attack() override ; //attack function override
    void defend(int attackDamage) override ; //defend function override
};


#endif
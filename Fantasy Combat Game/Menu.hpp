/*********************************************************************
** Program name: Menu.hpp
** Author: David Lee
** Date: 05/08/2019
** Description: Header file for the Menu class that creates two players within the game and allows them to pick
 * the character type to fight each other. It has a constructor, destructor, run function that drives the program, setCharacter function that
 * sets the character for the player and general inputValidation function.
*********************************************************************/


#ifndef MENU_HPP
#define MENU_HPP
#include "Character.hpp"

class Menu {
private:
    Character* player1; //store character type for player1
    Character* player2; //store character type for player2

public:
    Menu(); //constructor
    ~Menu(); //destructor
    void setCharacter(Character*& player, int type); //set character type to player1 and player2
    void run(); //program driver
    int inputValidation(string message, int min, int max); //general input validation that only accepts integers

};


#endif

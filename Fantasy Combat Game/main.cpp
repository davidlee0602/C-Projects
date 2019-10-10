/*********************************************************************
** Program name: main.cpp
** Author: David Lee
** Date: 05/08/2019
** Description: main file and entry point to the program for project 3. Project 3 is a fantasy combat game involving
 * different classes for different character types, implements inheritance and polymorphism from base Character class.
 * It also contains a menu for users to test the characters.
*********************************************************************/

#include <iostream>
#include "Character.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"
#include "Menu.hpp"
using namespace std;

int main() {
    Menu menu; //initialize menu object
    menu.run(); //invoke run menu member function
    return 0;
}
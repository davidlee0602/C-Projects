/*********************************************************************
** Program name: Menu.cpp
** Author: David Lee
** Date: 05/08/2019
** Description: Implementation file for the Menu class that creates two players within the game and allows them to pick
 * the character type to fight each other. It has a constructor, destructor, run function that drives the program, setCharacter function that
 * sets the character for the player and general inputValidation function.
*********************************************************************/

#include "Menu.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include "Character.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;

Menu::Menu(){ //constructor
    player1 = nullptr;
    player2 = nullptr;
}

Menu::~Menu(){ //destructor
    delete player1;
    player1 = nullptr;
    delete player2;
    player2 = nullptr;
    cout << "Menu object deleted" << endl;
}

void Menu::run(){ //driver for fantasy combat program
    bool menuRun = true;
    while(menuRun){
        int userInput = inputValidation("Welcome to Fantasy Combat Game. Press 1 for to START. Press 2 for END.", 1, 2);
        if (userInput == 1) {
            int round = 0;
            int player1Type = inputValidation("Select character type for player 1. \n[1]Vampire, [2]Barbarian, [3]Blue Men, [4]Medusa, [5]Harry Potter", 1, 5);
            int player2Type = inputValidation("Select character type for player 2. \n[1]Vampire, [2]Barbarian, [3]Blue Men, [4]Medusa, [5]Harry Potter", 1, 5);
            setCharacter(player1, player1Type);
            setCharacter(player2, player2Type);
            cout << "The following types have been chosen:" << endl;
            cout << "Player 1: " << player1->getType() << endl;
            cout << "Player 2: " << player2->getType() << endl;
            cout << "Let's fight to the death!" << endl;
            while(player1->getStrengthPoints() > 0 && player2->getStrengthPoints() > 0){
                cout << "**********************************************************************" << endl;
                if(player1->getStrengthPoints() > 0){ //player1 always attacks first
                    cout << "Round: #"<< ++round << endl;
                    cout << "**Player 1: " << player1->getType() << " attacks.**" << endl;
                    int player1Attack = player1->attack();
                    cout << "**Player 2: " << player2->getType() << " defends.**\n[Stats before defending]\n" << "Armor: " << player2->getArmorPoints() << ", Strength: "<< player2->getStrengthPoints() << "." << endl;
                    player2->defend(player1Attack);
                    cout << "Player 2: " << player2->getType() << " strength after defending: " << player2->getStrengthPoints() << "." << endl;
                }
                if(player2->getStrengthPoints() > 0){
                    cout << "------------------------------------------------------------" << endl;
                    cout << "**Player 2: " << player2->getType() << " attacks.**" << endl;
                    int player2Attack = player2->attack();
                    cout << "**Player 1: " << player1->getType() << " defends.**\n[Stats before defending]\n" << "Armor: " << player1->getArmorPoints() << ", Strength: "<< player1->getStrengthPoints() << "." << endl;
                    player1->defend(player2Attack);
                    cout << "Player 1: " << player1->getType() << " strength after defending: " << player1->getStrengthPoints() << "." << endl;
                }
            }
            if (player1->getStrengthPoints() > player2->getStrengthPoints()){ //round result
                cout << "Result****************************************************************" << endl;
                cout << "Player 1: " << player1->getType() << " WINS!" << endl;
            }
            else if(player2->getStrengthPoints() > player1->getStrengthPoints()){
                cout << "Result****************************************************************" << endl;
                cout << "Player 2: " << player2->getType() << " WINS!" << endl;
            }
            else{
                cout << "Result****************************************************************" << endl;
                cout << "Error in match." << endl;
            }
            delete player1;
            player1 = nullptr;
            delete player2;
            player2 = nullptr;

        }
        else{
            menuRun = false;
            cout << "Program ended. Thank you." << endl;
        }
    }
}

void Menu::setCharacter(Character*& player, int type){ //sets player1 or player2 to the character type they choose
    switch(type){
        case 1:
            player = new Vampire();
            break;
        case 2:
            player = new Barbarian();
            break;
        case 3:
            player = new BlueMen();
            break;
        case 4:
            player = new Medusa();
            break;
        case 5:
            player = new HarryPotter();
            break;
        default:
            cout << "Entry error" << endl;
            break;
    }
}
int Menu::inputValidation(string message, int min, int max){ //input validation to accept integers only
    double input;
    bool repeatEntry = true;
    char errorTest;
    string inputLine;
    while (repeatEntry == true) {
        cout << message << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> input)) {
            cout << "Input was not a number. Please try again." << endl;
        } else if ((input < min) || (input > max)) {
            cout << "Input out of range. Please try again." << endl;
        } else if (input - static_cast<int>(input) != 0) {
            cout << "Input with decimals and not an integer. Please try again." << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters. Please try again." << endl;
        } else {
            repeatEntry = false;
            input = input;
            cout << "Input accepted." << endl;
        }
    }
    return input;
}
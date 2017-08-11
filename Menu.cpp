/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/5/2017
** Description: Definitions of the menu class functions
***************************************************************************************************/

#include "Menu.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/****************************************************************************************************
**                                         displayMenu
**                       Displays the menu of game options on the screen.
**                        I pulled this function idea from the textbook.
****************************************************************************************************/
void Menu::displayMenu()
{
	cout << "\tQueue List" << endl;
	cout << "1: Enter a value to be added to the queue" << endl;
	cout << "2: Display first node (front) value" << endl;
	cout << "3: Remove first node (front) value" << endl;
	cout << "4: Display the queue contents" << endl;
	cout << "5: Display the queue in reverse" << endl;
	cout << "6: Display looped list" << endl;
	cout << "7: Display looped reverse list" << endl;
	cout << "8: Exit" << endl;
	cout << endl;
}


/****************************************************************************************************
**                                          setChoice
**                              Sets the menu choice from the user
****************************************************************************************************/
void Menu::setChoice()
{
	do
	{
		cout << "Choose an option: " << endl;
		choice = inputVal1.isPosInteger();
	} while (choice > 8 || choice < 1);
}


/****************************************************************************************************
**                                          getChoice
**                       Gets the menu choice from the user and returns it
****************************************************************************************************/
int Menu::getChoice()
{
	return choice;
}

/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/5/2017
** Description: Main function
***************************************************************************************************/

#include "Queue.h"

int main()
{
	
	Queue queue;
	Menu menu;
	InputValid inputVal;
	do
	{
		menu.displayMenu();
		menu.setChoice();

		if (menu.getChoice() == 1)
		{
			cout << "Enter an integer to add to the list" << endl;
			int val = inputVal.isInteger();
			queue.addBack(val);
		}

		else if (menu.getChoice() == 2)
		{
			cout << queue.getFront() << endl;
		}

		else if (menu.getChoice() == 3)
		{
			queue.removeFront();
		}

		else if (menu.getChoice() == 4)
		{
			queue.displayList();
		}

		else if (menu.getChoice() == 5)
		{
			queue.displayReverse();
		}

		else if (menu.getChoice() == 6)
		{
			queue.displayLoop();
		}

		else if (menu.getChoice() == 7)
		{
			queue.displayLoopReverse();
		}

		else
		{
			return 0;
		}
	} while (menu.getChoice() != 8);
}
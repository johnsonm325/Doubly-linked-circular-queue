/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/5/2017
** Description: Definitions of the Queue class functions
***************************************************************************************************/

#include "Queue.h"

/****************************************************************************************************
**						Sets front and rear pointers to null for empty list
****************************************************************************************************/
Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
}


/****************************************************************************************************
**							Destructs pointers in list by traversing list
****************************************************************************************************/
Queue::~Queue()
{
	// Temp pointer used for traversing the list
	QueueNode *traverse = front;

	// Loops through the list while the temp pointer doesn't equal the rear pointer
	while (traverse != rear)
	{
		// Temp pointer used for deleting memory, set equal to wherever traverse pointer is
		QueueNode *garbage = traverse;
		// Moves through the list by pointing to next and deletes the memory
		traverse = traverse->next;
		delete garbage;
	}
	// Deletes the final memory at rear
	delete traverse;
}


/****************************************************************************************************
**							Adds a value to the back of the list
****************************************************************************************************/
void Queue::addBack(int val)
{
	// If the list is empty, it allocates a new node and points the front and rear to that node
	// Then it points next and prev pointers to make it circular and doubly-linked
	if (isEmpty())
	{
		front = rear = new QueueNode(val);
		rear->prev = rear->next = front;
		front->prev = front->next = rear;
	}
	
	// If there is at least one value in the list, a temp node is created and placed after the rear
	// Then the pointers at the previous rear are moved up to the new node, followed by rear
	// Then the rear->next and front->prev are reattached to make it circualar
	else
	{
		QueueNode *temp = new QueueNode(val);
		rear->next = temp;
		temp->prev = rear;
		rear = temp;
		rear->next = front;
		front->prev = rear;
	}
}


/****************************************************************************************************
**								Returns the front value of the list
****************************************************************************************************/
int Queue::getFront()
{
	return front->number;
}


/****************************************************************************************************
**								Removes the front value of the list
****************************************************************************************************/
void Queue::removeFront()
{
	// If the list is empty the user will be informed
	if (isEmpty())
	{
		cout << "The queue is empty" << endl;
		return;
	}

	// If the list has only 1 value, then all pointers are set to null
	else if (front == rear)
	{
		front = rear = rear->next = rear->prev
			  = front->next = front->prev = nullptr;
	}

	// If the list has more than one value, a temp pointer is allocated
	// Then all pointers that point to the front value are detached and moved to point to the
	// rear and front->next respectively. The front value is stored in temp and then deleted
	else
	{
		QueueNode *temp;
		rear->next = front->next;
		temp = front;
		front = front->next;
		front->prev = rear;
		delete temp;
	}
}


/****************************************************************************************************
**								Checks to see if list is empty
****************************************************************************************************/
bool Queue::isEmpty() const
{
	if (front == nullptr)
	{
		return true;
	}

	else
	{
		return false;
	}
}


/****************************************************************************************************
**							Displays contents of list from front to back
****************************************************************************************************/
void Queue::displayList()
{
	QueueNode *temp = front;

	if (temp == nullptr)
	{
		cout << "The list is empty" << endl;
	}
	else if (temp->next == front)
	{
		cout << temp->number << "  ";
		cout << endl;
	}
	else
	{
		while (temp->next != front)
		{
			cout << temp->number << "  ";
			temp = temp->next;
		}
		cout << rear->number << endl;
	}
}


/****************************************************************************************************
**				Displays contents of list from back to front to prove doubly-linked
****************************************************************************************************/
void Queue::displayReverse()
{
	QueueNode *temp = rear;

	if (temp == nullptr)
	{
		cout << "The list is empty" << endl;
	}
	else if (temp->prev == rear)
	{
		cout << temp->number << "  ";
		cout << endl;
	}
	else
	{
		while (temp->prev != rear)
		{
			cout << temp->number << "  ";
			temp = temp->prev;
		}
		cout << front->number << endl;
	}
}


/****************************************************************************************************
**		Displays contents of list from front to back in a recurring loop to prove circular
****************************************************************************************************/
void Queue::displayLoop()
{
	QueueNode *temp = front;

	if (temp == nullptr)
	{
		cout << "The list is empty" << endl;
	}
	else if (temp->next == front)
	{
		cout << temp->number << "  ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < 15; i++)
		{
				cout << temp->number << "  ";
				temp = temp->next;
		}
		cout << endl;
	}
}


/****************************************************************************************************
** Displays contents of list from back to front in recurring loop to prove doubly-linked and circular
****************************************************************************************************/
void Queue::displayLoopReverse()
{
	QueueNode *temp = rear;

	if (temp == nullptr)
	{
		cout << "The list is empty" << endl;
	}
	else if (temp->prev == rear)
	{
		cout << temp->number << "  ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < 15; i++)
		{
			cout << temp->number << "  ";
			temp = temp->prev;
		}
		cout << endl;
	}
}
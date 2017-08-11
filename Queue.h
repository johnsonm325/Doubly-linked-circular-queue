/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/5/2017
** Description: Header file for Queue class
***************************************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "Menu.h"

class Queue
{

	struct QueueNode
	{
		// Defines struct and ability to create a new node
		int number;
		QueueNode *next;	// Used as pointers to next
		QueueNode *prev;	// and previous nodes
		QueueNode(int number1, QueueNode *next1 = nullptr, QueueNode *prev1 = nullptr)
		{
			number = number1;
			next = next1;
			prev = prev1;
		}
	};
		QueueNode *front;	// Used to point to front
		QueueNode *rear;	// and rear nodes

public:
	Queue();
	~Queue();
	void addBack(int);
	int getFront();
	void removeFront();
	bool isEmpty() const;
	void displayList();
	void displayReverse();
	void displayLoop();
	void displayLoopReverse();
};
#endif
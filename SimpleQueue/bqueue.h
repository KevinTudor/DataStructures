#pragma once

#include <iostream>
#include <string>

using namespace std;

/*********************************************************************************************
				b q u e u e . h		 (given class declarations)
**********************************************************************************************

	Description: QUEUE (doubly linked list) first come first out

*********************************************************************************************/
#ifndef QUEUE
#define QUEUE

class bqnode
{
public:
	int priority;
	bqnode* prev,* next;
};

class bqueue
{
public:
	bqueue();						   // default constructor
	~bqueue();						   // destructor
	bqueue(const bqueue&);			   // copy constructor
	void enqueue(const int&);		   // adding a new item to the queue
	void dequeue();					   // delete queue
	bool empty() { return front == 0;} // empty checker
	void print();					   // print queue
private:
	bqnode* front;                     //use ONLY one pointer
};

#endif 

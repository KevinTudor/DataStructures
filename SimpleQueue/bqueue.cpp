#include "bqueue.h"


/*********************************************************************************************
				b q u e u e . c p p 
**********************************************************************************************

	Description: To hold the function definitions that were decared in the class declaration

*********************************************************************************************/



/*************************************************************************************
Name: Default constructor
Precondition: new object created in the main
Postcondition: new object created in main is initialized as doubly-linked list with top = 0
Description: default constructor will set front of linked list to 0.
*************************************************************************************/
bqueue::bqueue()
{
	//cout<<"Inside Default Constructor\n"; 

	front = 0;
}


/*************************************************************************************
Name: ~bqueue (destructor)
Precondition: queue has been created and initialized.
Postcondition: queue has been deleted
Description: function will transverse through the queue and pop each term untill is empty.
*************************************************************************************/
bqueue::~bqueue()
{
	//cout << "-bqueue has been called" << endl;

	while (!empty())
	{
		dequeue();
	}
}


/*************************************************************************************
Name: Copy constructor
Precondition: queue k has been created and initialized.
Postcondition: queue j will have a copy of contents in queue k. (j = k)
Description: copy constructor will initialize this front to 0 and transverse through
queue k pushing each priority term into queue j.
*************************************************************************************/
bqueue::bqueue(const bqueue& obj)
{
	//cout << "Copy constructor has been called" << endl;

	front = 0;
	bqnode* p = obj.front;

	while (p->next != obj.front)
	{
		enqueue(p->priority);
		p = p -> next;
	}
	enqueue(p->priority);
}


/*************************************************************************************
Name: enqueue (push)
Precondition: queue has been created and initialized.
Postcondition: enqueue will add the item to the doubly linked list.
Description: if the queue is empty the function will make a new front node and doubly link the prev and next to front. 
It will also set the front node priority to the value of the item.
if the queue is not empty the function uses a pointer to create a new node and it adds an item to the priority 
then it shifts the prev pointer to the front prev. it also sets the next to point to front and then shifts the front prev to p
so p will become the prev of the queue front.
*************************************************************************************/
void bqueue::enqueue(const int& item)
{
	//cout << "enqueue has been called (push)" << endl;

	if (empty()) 
	{
		front = new bqnode;
		front->prev = front->next = front;
		front->priority = item;
	}
	else
	{
		bqnode * p = new bqnode;
		p->priority = item;
		p->prev = front->prev;
		p->next = front;
		front->prev = p;            //p become the prev of Queue front
		//p->prev->next = p;
	}
}


/*************************************************************************************
Name: dequeue
Precondition: queue has been created and initialized.
Postcondition: the doubly linked queue will dequeue (pop) the front node. (bottom) ex: 60 40 30 becomes: 40 30 
Description: dequeue will only act if the queue is NOT empty, if so, it will use p to point to the front bqnode
if p is NOT equal to the front->next then the function will shift all node following the first so that the secong node becomes the first node.
and it deletes the first node. if p = front->next the function caught the last deque and will set the front to 0.
*************************************************************************************/
void bqueue::dequeue()
{
	//cout << "dequeue has been called (push)" << endl;

	if (!empty())
	{ 
		bqnode* p = front;

		if (p != front->next)
		{
			front->prev->next = front->next;
			front->next->prev = front->prev;
			front = front->next;
		}
		else
		{
			front = 0;
		}
		delete p;	
	}
	else
	{ 
		cout << "Cannot dequeue because queue is empty\n"; 
	}
}


/*************************************************************************************
Name: print queue
Precondition: queue has been created and initialized.
Postcondition: queue priority terms have been printed term by term to the screen.
Description: if the queue is populated the function will loop/transverse through the loop 
and cout every term untill it is empty... which it will then break the loop.
*************************************************************************************/
void bqueue::print()
{
	//cout << "print has been called" << endl;

	bqnode* p = front;
	
	if (!empty())
	{
		while (p->next != front)
		{
			cout << p->priority << endl;
			p = p->next;
		}
		cout << p->priority << endl;
	}
}

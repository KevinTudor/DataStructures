#include "bqueue.h"
#include "bqueue.cpp"

using namespace std;

/*********************************************************************************************
				b q u e u e _ d r i v e r . c p p (given)
**********************************************************************************************

Name: Kevin Tudor (Z23468207)
Course: Date Structures/Algorithm Analysis  (COP3530)   Professor: Dr. Lofton Bullard
Due Date: 03/10/2021									Due Time: 11:59pm
Total Points: 25										Module 8: implement a doubly-linked circular queue of integers

Description: The purpose of this program is to (1) manipulate pointers,(2) allocatememory dynamically,
(3) implement a default constructor, copy constructor and destructor,(4) use only one pointer to add 
to the back and to delete from the front of the queue.

*********************************************************************************************/

int main()
{
	bqueue k;
	/*Test 1*/
	cout << "Test 1" << endl;
	k.enqueue(60);  //adds a new node (like push)
	k.print();      //60

	/*Test 2*/
	cout << "Test 2" << endl;
	k.enqueue(20);
	k.enqueue(30);
	k.print();      //60 20 30

	/*Test 3*/
	cout << "Test 3" << endl;
	k.enqueue(10);
	k.print();      //60 20 30 10

	/*Test 4*/
	cout << "Test 4" << endl;
	k.enqueue(50);
	k.enqueue(40);
	k.print();      //60 20 30 10 50 40

	/*Test 5*/
	cout << "Test 5" << endl;
	bqueue j = k;
	j.dequeue();
	j.print();      //20 30 10 50 40

	/*Test 6*/
	cout << "Test 6" << endl;
	j.dequeue();
	j.dequeue();
	j.dequeue();
	j.print();       //50 40

	/*Test 7*/
	cout << "Test 7" << endl;
	j.dequeue();
	j.dequeue();
	j.print();       //NULL

	/*Test 8*/
	cout << "Test 8" << endl;
	j.dequeue();      //cannot deque because queue is empty
	j.dequeue();      //cannot deque because queue is empty

	/*End Tests*/     //result: destruct objects using deque
	return 0;
}
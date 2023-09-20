#pragma once

#include <iostream>
#include <string>

using namespace std;


/*********************************************************************************************
				S t a c k . h		 (given class declarations)
**********************************************************************************************

	Description: Stack ADT (Last-In-First-Out data structure)

*********************************************************************************************/
#ifndef STACK
#define STACK


//const int STACK_CAPACITY;
typedef string stack_element;


class stack_node
{
public:
	stack_element data;       //typedef string data
	stack_node* next;
};

class stack
{
public:
	//Default constructor
	stack();      

	//destructor
	~stack();                    

	//copy construstor
	stack(const stack&);  

	//retrieve the top element
	stack_element top();		 //if stack not empty, return "node [top]"               
	
	//remove the top element
	string pop();					 //if array not empty, decrement Top

	//push element to the top
	void push(const stack_element&);    //if linked list not full increment top by 1, and store value in linked list [top]

	//print data
	void print();                        

private:

	stack_node* s_top;
};

#endif 

/* Notes *****************************************************************

**********Queue Property - FIFO - First-in First-out**********************

Definition:

1.  Data: a sequence of items, and the list may only 
   be accessed atthe front and the back.  Items are 
   deleted from the front, and items are added to the back.
2. Operations:
	a. Constructor - construct a queue.
	b. enqueue - adds item to the back of the queue
	c. dequeue - removes item from the front of the queue
	d. front - retrieve the item at the front of the queue
	e. empty

tree information:
postfix = L R P traverse left then right then parent

************infix and postfix***********************************************

	compilers convert an expression in "infix" notation to "postfix"
	operators are written AFTER the opperands
		- infix "a * b + c" becomes postfix "a b * c +"
		-- Advantage: expressions can be written without parentheses

Examples of infix to postfix

	1. infix "A + B" becomes postfix "A B +"
	2. infix "A * B + C" becomes postfix "A B * C +"
	3. infix "A * (B + C)" becomes postfix "A B C + *"
	4. infix "A - (B - (C - D))" becomes postfix " A B C D---"
	5. infix "A - B - C - D" becomes postfix "A B-C-D-"

Examples of postfix to infix evaluation (by hand)

	postfix "  2 3 4 + 5 6 - - *  "

		2 (3 4 +) 5 6 - - *
		2 "7" (5 6 -) - *
		2 (7 "1" -) *
		(2 "8" *)

	result	"  16  "

**********STACK ALGORITHM to evaluate postfix expressions******************

	1. initialize an empty stack
	2. Repeat the following until the end of the expression is encountered
		a) Get the next token (const, var, operator) in the expression
		b) Operand - push onto stack
		c) Operator - do the following...
			i)Pop 2 values from stack
			ii)Apply operator to the two values
			iii)Push resulting value back onto stack
	3. When end of expression encountered, 
	value of expression is 	the (only) number left in stack.


* End Notes *************************************************************/
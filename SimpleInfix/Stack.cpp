#include "Stack.h"

/*********************************************************************************************
				S t a c k . c p p (GIVEN)
**********************************************************************************************

	Description: To hold the function definitions that were decared in the class declaration

*********************************************************************************************/



/*************************************************************************************
Name: Default constructor
Precondition: new stack object created in the main
Postcondition: new stack object created in main is initialized as stack with top = 0
Description: default constructor will set top of stack to 0.
*************************************************************************************/
stack::stack() 
{
	//cout<<"Inside Default Constructor\n"; 
	s_top = 0; 
}


/*************************************************************************************
Name: Copy constructor
Precondition: stack one has been created and initialized.
Postcondition: stack two will have a copy of contents in stack one
Description: copy constructor will initialize this top to 0 and transverse through
stack one pushing each data term into stack temp, it then transverses this stack (stack two)
and it pushed each term into the new stack.
*************************************************************************************/
stack::stack(const stack& Org)
{
	//cout<<"Inside the Copy Constructor\n";
	(*this).s_top = 0;

	stack temp;
	stack_node* p = Org.s_top;
	while (p != 0)
	{
		temp.push(p->data);
		p = p->next;
	}

	p = temp.s_top;
	while (p != 0)
	{
		(*this).push(p->data);
		p = p->next;
	}
}


/*************************************************************************************
Name: stack destructor
Precondition: stack has been created and initialized
Postcondition: stack has been deleted
Description: function will transverse through the stack and pop each term.
*************************************************************************************/
stack::~stack()
{
	//cout<<"Inside !stack (destructor) \n";
	while (s_top != 0)
	{
		pop();
	}
}


/*************************************************************************************
Name: pop
Precondition: stack is created and initialized
Postcondition: removes the top element and returns the result.
Description: removes the top element
*************************************************************************************/
string stack::pop()
{
	//cout<<"Inside pop \n";
	string my_result;
	stack_node* p;

	if (s_top != 0)
	{
		p = s_top;
		my_result=p->data;
		s_top = s_top->next;
		delete p;
	}
	return my_result;
}


/*************************************************************************************
Name: push
Precondition: stack is created and initialized
Postcondition: push element to the top of the stack
Description: push element to the top if linked list not full increment top by 1, 
and store value in linked list [top]
*************************************************************************************/
void stack::push(const stack_element& item)
{
	//cout<<"Inside push \n";
	stack_node* p = new stack_node;

	p->data = item;
	p->next = s_top;
	s_top = p;
}


/*************************************************************************************
Name: print
Precondition: stack is created and initialized
Postcondition: stack is printed onto the screen
Description: function will transverse through the stack and cout every term.
*************************************************************************************/
void stack::print()
{
	//cout<<"Inside print \n";
	for (stack_node* p = s_top; p != 0; p = p->next)
	{
		cout << p->data << endl;
	}
}


/*************************************************************************************
Name: top
Precondition: stack is created and initialized
Postcondition: top data of the stack is returned if the stack is not empty.
Description: top data of the stack is returned if the stack is not empty.
*************************************************************************************/
stack_element stack::top()
{
	//cout<<"Inside top \n";

	if (s_top == 0)
	{
		exit(1);
	}
	else
	{
		return s_top->data;
	}
}
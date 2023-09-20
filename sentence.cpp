#include "sentence.h"

/*********************************************************************************************
				S E N T E N C E . C P P 
**********************************************************************************************

	Description: To hold the function definitions that were decared in the class declaration

*********************************************************************************************/


/*************************************************************************************
Name: sentence (default constructor) 
Precondition: cin calls default constructor in the main
Postcondition: default constructor creats a "sentence" that has empty node.
Description: 
	1) The default constructor will initialize your state variables. 
	2) The front of the linked list is initially set to NULL or 0; this implies a non-header node 
	3) implementation of the link list.
*************************************************************************************/
sentence::sentence()
{
	front = NULL;
	back = NULL;
}


/*************************************************************************************
Name: sentence (explicit constructor)
Precondition: cin calls explicit constructor in the main with given string value
Postcondition: explicit constructor creates a linked list with the given string.
Description: the function will check to see if the string at point [i] is not a space, if it is 
not a space it will add the character to a temp string and continue through the loop. 
if the function finds a space, it will add the temp it created in the first loop and then the space.
*************************************************************************************/
sentence::sentence(const string& s)
{
	front = NULL;
	back = NULL;
	string temp = "";

		for (int i = 0; i < s.length(); i++)			  //only iterate untill the string is done
		{
			if (s[i] != ' ')							  // checks if not a space
			{
				temp += s[i];
				if (i == s.length() - 1) //backup for when the string has no space at the end and needs to add the "word" to themp.
				{
					add_back(temp);
				}
			}
			else									   	// checks if it is a space
			{ 
					add_back(temp);						 //if space then add the temp that was built in the first if.
					//cout << "TEMP : (" << temp << ")" << endl;
					add_back(" ");						//add the space after the "word"
					//cout << "SPACE : ( )" << endl;
					temp = "";
			}
		}
}

/*************************************************************************************
Name: add_back
Precondition: a "key" is created like temp in the explicit constructor
Postcondition: the key is put into the back most node of the linked list being created.
Description: function checks if the first node has the null "next". if so, the function will create a new word and add it behing the first.
if the list has more that one nodde it will point to a new word and add the node in the back. it then makes that the final node with back->next = p;
*************************************************************************************/
void sentence::add_back(const string& key)
{

	if (front == 0)
	{
		front = new word;
		front->term = key;
		front->next = 0;
		back = front;
	}
	else
	{
		word* p = new word;
		p->next = 0;
		p->term = key;
		back->next = p;
		back = p;
	}
	
}

/*************************************************************************************
Name: sentence (copy constructor)
Precondition: cin calls copy constructor in the main with given predefined sentence.
Postcondition: the new sentence will hold the same node values as the node values in the predefined sentence.
Description: the function initializes the sentence to have front and back = NULL then it iterates
through the predefined list and add_back the predefined terms in the new copied sentence.
*************************************************************************************/
sentence::sentence(const sentence& org)
{
	front = 0;
	back = 0;

	word* p = org.front;

	while (p != 0)
	{
		add_back(p->term);
		p = p->next;
	}
}

/*************************************************************************************
Name: sentence destructor
Precondition: the main driver creates multiple or single object of the sentence class. (default, explicit, copy, etc..)
Postcondition: the destructor deallocates memory held in the objects created by sentence class.
Description: the function iterates through the current object and deletes each node as it shifts through it.
*************************************************************************************/
sentence::~sentence()
{
	cout << "Destructor has been called\n";
	while (front != 0)         //iterate through the sentence
	{
		word* p = front;
		front = front->next;   //shift to next term
		delete p;
	}
}

/*************************************************************************************
Name: length (length of sentence)
Precondition: a string or sentence is created
Postcondition: the function finds the length of all terms in the list added together
Description: the function will iterate through the list and add all terms to a temp string.
it the sets the variable cout to the length of the temp creted in the end.
*************************************************************************************/
int sentence::length()
{
	word* p = front;		//initialize p to front to help in the 
	string temp;
	int count = 0;

	while (p != 0)
	{
		temp += p->term;
		p = p->next;
	}
	
	count = temp.length();

	return count;
}

/*************************************************************************************
Name: sentence operator= with string
Precondition: the function is called in main using = string.
Postcondition: the function will add back all terms in the string to a new sentence using = string
Description: take a string (C-style or C++ string, just be consistent in your implementation)
as an argument and assigns its value to the current object;
*************************************************************************************/
void sentence::operator=(const string& s)
{
	this->front = NULL;
	string temp = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			temp += s[i];
			if (i == s.length() - 1)
			{
				add_back(temp);
			}
		}
		else
		{
			if (i != s.length())
			{
				add_back(temp);
				//cout << "TEMP : (" << temp << ")" << endl;
				add_back(" ");
				//cout << "SPACE : ( )" << endl;
				temp = "";
			}
		}
	}
}

/*************************************************************************************
Name: sentence operator= with sentence
Precondition: the main driver calls function using =(sentence)
Postcondition: the function wil set new sentence = the pre-allocated sentence.
Description: the function iterates through the current object and deallocates all memory
it then iterates through the w sentence and adds each node from the pre allocated sentence
to the new one. 
*************************************************************************************/
sentence& sentence::operator=(const sentence& w)
{
	while (front != 0)
	{
		word* p = front;
		front = front->next;
		delete p;
	}

	word* p = w.front;

	while (p != 0)
	{
		add_back(p->term);
		p = p->next;
	}

	return *this;
}



/*************************************************************************************
Name: operator+
Precondition: two objects hold values in the sentence
Postcondition: the function will add the sentence B to the end of the first sentence.
Description: the funtion will iterate through sentence B and add each node to the back of 
the first object of class sentence.
*************************************************************************************/
void sentence::operator+(sentence& B) // us = will be okay               their = everything
{
	word* p = B.front;

	while (p != 0)
	{
		add_back(p->term);
		p = p->next;
	}
}

/*************************************************************************************
Name: isEqual
Precondition: two objects of class sentence hold a sentence of values or null.
Postcondition:the function will determine if the two objects have the same values. (node for node)
Description: the function first checks if the first node of sentence B and this sentence have NULL next
if so, the function returns true. the function then iterates through both sentences and checks node
by node to see if each node holds the same value. if else, it will return false.
*************************************************************************************/
bool sentence::isEqual(sentence& B)
{
	word* p = B.front;

	if (p == 0 && this->front == 0)
	return true;

		while (p != 0 && this->front != 0)
		{
			if (this->front != NULL && p != NULL)
				if (this->front->term != p->term)
				{
					return false;
				}
			p = p->next;
			front = front->next;
		}
		if (p == this->front)
			return true;
		else
			return false;
}
/*************************************************************************************
Name: sentence search key
Precondition: a sentence is created and search is needed to find the key
Postcondition: the function return the node the key is found in
Description: the function iterates throught the list and if the term = the key it will 
return the p node. 
*************************************************************************************/
word* sentence::Search(const string& key)    //  front [value/address]-> [value/null]-> back
{
	word* p = front;			//initialize p to front to help in the 
							    //traversal of the list
		
	while (p != NULL)  //traverse (iterate through list)
	{
		
		if (p->term == key) //check if key equal to data in current node
		{
			//cout << "gotcha" << key << endl;
				return p;       //key located, return its location in list
		}
		p = p->next; //move to next node in the list {111 111 454 }
	}
	
	return p; //return location if found, otherwise 0 (null)
}

/*************************************************************************************
Name: sentence remove key
Precondition: a sentence is created
Postcondition: the function will remove the node holding the key string term from the list and shift the rest. 
Description: the function first checks if the list is empty. It then iterates through the list untill 
the string term is found and removes it then shifts the rest.
*************************************************************************************/
void sentence::remove(const string& s)
{
	//p=0 if key not in list; otherwise p holds the address of the node key is in.
	word* p = Search(s); //check to see if key in list

	//key was not found
	if (p == 0)  //key was not found in the list
	{
		cout << s << "\n" << " not in list\n";
	}
	else  //this block is executed because key was found in the list
	{
		//Remove the front node; there is only one node in the list
		if (p == front && front == back)
		{
			delete p;
			front = back = NULL;
		}
		//Remove the front node; there are at least 2 nodes in the list
		else if (p == front)
		{
			front = front->next;
			delete p;
		}
		//front does not contain key and there are at least 2 nodes
		else
		{
			word* back_ptr = front;

			//find node before the node that contains key
			while (back_ptr != 0 && back_ptr->next != p)
			{
				back_ptr = back_ptr->next;
			}
			//if key is in the last node, set back to node before last node
			if (p == back)
			{
				back = back_ptr;
			}
			back_ptr->next = p->next;
			delete p;
		}
	}
}

void sentence::Delete_All_Even()
{
    word* current = front;
    word* prev = nullptr;

    while (current != nullptr)
    {
        if (current->term != " "){          // If term is a number
            int x = stoi(current->term);    // String to int
            if (x % 2 == 0){ 				// If term is even
                if (prev == nullptr){		// If it's the first element
                    front = current->next;
                    delete current;
                    current = front;
                }
				else{                       // If it is NOT the first element
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            }                               // If term is odd
            else{
                prev = current;
                current = current->next;
            }
        }
        else{                               //If term is NOT a number
            prev = current;
            current = current->next;
        }
    }
}

/*************************************************************************************
Name: operator<< (out)
Precondition: main driver calls using <<
Postcondition: the function will pass the values to ostream& out
Description: the function iterates through thte curent object and passes the term to out
and ultimatelt returns out.
*************************************************************************************/
ostream& operator<<(ostream& out, const sentence& obj)
{
	word* p = obj.front;
	
	while (p != 0)
	{
		out << p->term;
		p = p->next;
	}

	return out;
}

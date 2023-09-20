#pragma once

#include <iostream>
#include <string>

using namespace std;

/*********************************************************************************************
				S E N T E N C E . H		 (given class declarations)
**********************************************************************************************

	Description: To hold private/public function and variable declarations

*********************************************************************************************/

#ifndef SENTENCE_H
#define SENTENCE_H

class word
{
public:
	string term;
	word* next;
};

class sentence
{
public:
	sentence();                      // 1) The default constructor will initialize your state variables. 
									 // 2) The front of the linked list is initially set to NULL or 0; this implies a non-header node 
									 // 3) implementation of the link list.

	sentence(const string& s);       // 1) Explicit-value constructor: This constructor will have one argument; 
							         // 2) a C-style string or a C++ string representing the word to be created;

	sentence(const sentence& org);   // 1) Copy Constructor: Used during a call by value, return, or initialization/declaration of a word object;
	
	~sentence();                     // 1) Destructor: The destructor will de-allocate all memory allocated for the word. Put the message 
							         // 2) "destructor called\n" inside the body of the destructor.

	int length();                    // Length: Determines the length of the word A; remember A is the current object;

	void add_back(const string& key);        // adds the key to yhe new node in abck then shifts p pointer

	friend ostream& operator<<(ostream& out, const sentence& obj); //Overload the insertion operator as a friend function with chaining to print a word A;

	void operator=(const string& s); // 1) Overload the assignment operator as a member function to take a 
									 // 2) string (C-style or C++ string, just be consistent in your implementation) as an argument and 
									 // 3) assigns its value to A, the current object;

	sentence& operator=(const sentence& w); // 1) Overload the assignment operator= as a member function with chaining to take a word                                       
	
	void operator+(sentence& B);    // 1) Overload the �+� operator as a member function without chaining to add word B 
					                // 2) (adds the set of symbols that makep B's linked list to the back of A's linked list) to the back of word A; 
					                // 3) remember A is the current object;
	
	bool isEqual(sentence& B);      // Returns true if two word objects are equal; otherwise false; remember A is the current

	word* Search(const string&);
	
	void remove(const string& s);   // Deletes the first occurrence of the string s from the list A;

	void Delete_All_Even();

private:
	word* front, * back;            // points to front and the back nodes
};

#endif

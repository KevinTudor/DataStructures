#include "string_class.h"

//*********************************************************************************************
//	string_class.cpp (functions)
//
//	Description: To hold the function definitions that were decared in the class declaration 
//	
//*********************************************************************************************



//*************************************************************************************
//Name:	Date (default constructor) 
//Precondition: cin calls default constructor in the main
//Postcondition: current_string is given the value of " ".
//Description:	current_string is given the value of " ".
//
//*************************************************************************************

string_class::string_class()
{
	cout << "Default constructor has been called" << endl;
	current_string = "";
}

//*************************************************************************************
//Name:	Date (explicit constructor) 
//Precondition: explicit constructor is called with given values.
//Postcondition: current string is given the value of the string in the main.
//Description:	cerrrent string is equal to the string in the main.
//
//*************************************************************************************

string_class::string_class(string ss)
{
	current_string = ss ;
}

//*************************************************************************************
//Name:	palindrome  
//Precondition: current_string has a string associated with it.
//Postcondition: function returns true or false depending if the current_string is 
// spelled the same way wackwards
//Description:	The function will start by finding the length (0-n) then it will convert
// all letters in the current_string tolower. It then goes through the first half of the 
// string and swaps the letters in the front to the back. ex: madam; for( i = 0 to i < (4/2) )i = 0; m swap m
// i = 1; a swap a; 
//*************************************************************************************

bool string_class::palindrome()
{
	int n = current_string.length() -1;
	
	for (int i = 0; i <= n; i++)
	{
		current_string[i] = tolower(current_string[i]);
	}

	string swap_string = current_string;

	for (int i = 0; i < (n / 2); i++)
	{
		swap(swap_string[i], swap_string[n - i]);
	}
	cout << swap_string << endl;

	if (swap_string == current_string)
		return true;
	else
		return false;
}

//*************************************************************************************
//Name:	operator <<
//Precondition: overload operator is called in the main with a given value for 
// const string_class& obj.
//Postcondition: function returns output stream 'out' with the values in obj.current_string.
//Description:	this function returns the output stream 'out' with the values in 
// obj.current_string.
//*************************************************************************************

ostream& operator<<(ostream& out, const string_class& obj)
{
	out << obj.current_string;
	return out;
}

//*************************************************************************************
//Name:	replace all
//Precondition: function is called in the main and populated with cin values for 
// old_string, new_string, and current_string
//Postcondition: the function will replace the old_values it finds in the current_string
// with the given new_values.
//Description:	the function will use the length of the current and old string to set predefined
// conditions then it will use a for loop with a nested if to replace the old_values it finds in 
//the current_string with the given new_values.
//*************************************************************************************

void string_class::replace_all(string old_substring, string new_substring)
{
	/*
	01234567
	aaaababa  orignal current
	aa        old
	x         new
	*/

	int current = current_string.length() - 1;
	int old = old_substring.length();

	if (current <= -1 || old > current)
	{
		current_string;
	}

	for (int i = 0; i <= current; i++)
	{
		//cout << "this is i " << i << endl;;
		if ((current_string.compare(i, old, old_substring)) == 0)
		{
			current_string.erase(i, old);
			current_string.insert(i, new_substring);
			//cout << "This is current_string " << current_string << endl;
			current = current_string.length() - 1;
		}
	}
}



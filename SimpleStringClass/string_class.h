#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> 

using namespace std;

//*********************************************************************************************
//	string_class.h (class declarations)
//
//	Description: To hold private/public function and variable declarations for class string_class
//
//*********************************************************************************************


class string_class
{
public:
	string_class();               //default constructor, sets current_string to empty string ("").
	string_class(string ss);      //explicit consctructor, sets current_string to variable in 

	bool palindrome();            //function returns true or false depending if the current_string is spelled the same way wackwards
	void replace_all(string old_substring, string new_substring);

	friend ostream& operator<<(ostream& out, const string_class& obj);   //function returns output stream 'out' with the values in obj.current_string.

private:
	string current_string;
};


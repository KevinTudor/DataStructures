#include <iostream>
#include <string>


using namespace std;

/*********************************************************************************************
				r e c u r s i v e _ f u n c t i o n s . c p p
**********************************************************************************************

Name: Kevin Tudor (z23468207)
Course: Date Structures/Algorithm Analysis  (COP3530)   Professor: Dr. Lofton Bullard
Due Date: 03/26/2021									Due Time: 11:59pm
Total Points: 25										Module 10: program that contains two
                                                        recursive and one non-recursive functions

**********************************************************************************************

Description: Write a programthat contains two recursive and one non-recursive functions

1. A recursive boolean function called palindrome that accepts one string argument(for the user)
and returns true if the string reads the same forward as it does backwards.For example madam,
463364, and �ABLE WAS I ERE I SAW ELBA� are all palindromes.(10 pts)

2. A recursive function called printReverse that accepts one string argument(for the user)
and returns the reverse of that string.(10 pts)

3. A non-recursive function called printIterReverse that accepts one string argument(from the user)
and returns the reverse of that string.(5 pts)

*********************************************************************************************/


/*********************************************************************************************
Function Name: palindrome 
Description: accepts one string argument(for the user) and returns true if the string reads 
the same forward as it does backwards
*********************************************************************************************/

bool palindrome(const string& s) //ex: madam, 463364, ABLE WAS I ERE I SAW ELBA.
{
	if (s == "")
	{
		return true;
	}

	char f = s[0];
	char l = s[s.length() - 1];

	if (f != l)
	{
		return false;
	}
	else
	{
		if (s.length() <= 1)
		{
			return true;
		}
		if (s.length() == 2)
		{
			if (f == l)
			{
				return true;
			}
		}
		string temp = s.substr(1, s.length() - 2);
		return palindrome(temp);
	}
};


/*********************************************************************************************
Function Name: printReversel
Description: A recursive function called printReverse that accepts one string argument (for the user)
and returns the reverse of that string.(10 pts)
*********************************************************************************************/
string  printReversel(const string& s) //ex: madam, 463364, ABLE WAS I ERE I SAW ELBA.
{
	string reverse = "";

	if (s.length() != 0)
	{
		reverse += s[s.length() - 1];
		reverse += printReversel(s.substr(0, s.length() - 1));
	}

	return reverse;
};


/*********************************************************************************************
Function Name: printIterReverse
Description: A non-recursive function called printIterReverse that accepts one string argument 
(from the user) and returns the reverse of that string.(5 pts)
*********************************************************************************************/
string printIterReverse(const string& s) //ex: madam, 463364, ABLE WAS I ERE I SAW ELBA.
{ 
	string reverse = "";

	for (int i = s.length() - 1; i >= 0; i--)
	{
		reverse += s[i];
	}

	return reverse; 
};



/*********************************************************************************************
Function Name: Main driver
Description: Program should ask the user for a string and run each function on that string, 
and produce the appropriate output (messages); it should also ask the user if they wish to continue.
*********************************************************************************************/
int main()
{
	string s = "";
	string response = "y";

	while (response == "y" || response == "Y")
	{
		cout << "Please enter string: ";
		getline(cin, s);
		if (palindrome(s) == true)
		{
			if (s == "")
			{
				cout << "\"\" is a palindrome \n";
			}
			else
			cout << s << " is a palindrome \n";
		}
		else
		{
			cout << s << " is a not palindrome \n";
		}

		cout << "The Rec-reverse of \"" << s << "\" is \"" << printReversel(s) << "\"" << endl;
		cout << "The Iter-reverse of \"" << s << "\" is \"" << printIterReverse(s) << "\"" << endl;
		cout << endl << "Do you wish to continue ('y/Y' for yes; 'n/N' for no) ? ";
		cin >> response;
		cin.ignore();
	}
	return 0;
}


/* NOTES***********************************************************************************************************

All recursive algorythms can be implemented iteratively. Meaning they can be implemented using loops (while, for, etc...).
Anything you do recursively you can do with a while loop.

* direct recursion is when the functon calls itself
* inDirect recursion is when the function calls other functions ultimately back to the original function

Definitions/Important Terms

* A base sometimes refered to as the anchor or trival case, it is very easy solution that does not require much thought to solve
* Recursive case is the step in the algorythm where the problem is divided into smaller less complex problems.

SYNTAX for RECURSIVE FUNCTION; to write a recursive function requires two steps. Identify the base case and identify any recursive cases.

FORMAT:
	if(base case)
		return trivial solution
	else(recursive case 1)
		return (solution from the recursive call)
		.....

EXAMPLE:
void recursive_countdown(int count)
{
	if(count = 0)
		cout << "count = " << count << endl;
	else
	{
		cout << "count = " << count << endl;
	}
}

/* END NOTES***********************************************************************************************************/

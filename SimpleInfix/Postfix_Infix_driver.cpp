#include "Stack.h"
#include "Stack.cpp"

/*********************************************************************************************
				I n f i x _ d r i v e r . c p p 
**********************************************************************************************

Name: Kevin Tudor (Z23468207)
Course: Date Structures/Algorithm Analysis  (COP3530)   Professor: Dr. Lofton Bullard
Due Date: 03/03/2021									Due Time: 12:00 am
Total Points: 25										Module 7: stack implemented as singly LINKED LIST

Description: The purpose of this program is to convert a postfix expression to the
corresponding fully-parenthesized infix expression

*********************************************************************************************/


int main()
{
	/* MY MAIN ********************************************************************************************/

	/*TEST 1 **********************************************************************************************/
	cout << "Test 1" << endl;
	stack s1;
	
	string retry = "Y";
	string postfix;
	string operand2;
	string operand1;
	string expression;
	string my_infix;
	bool flag = 0;

	do{
		cout << "Please input postfix expression as input" << endl;   // ask the user for a postfix expression as input
		getline(cin, postfix);

		for (int i = 0; i < postfix.length(); i++)
		{
			string myoperator = postfix.substr(i, 1);
			if (myoperator == "*" || myoperator == "/" || myoperator == "+" || myoperator == "-")
			{
				operand2 = s1.pop();  
				//cout << "operator 2:" << operand2 << endl;
				if (operand2 == "\0")
				{
					if (myoperator.length() == 1)
					{
						cout << "\nInvalid expression: Too many operators and not enough operands\n" << endl;
						flag = 1;
					}
					else
					cout << "\nInvalid expression: Too many operands and not enough operators\n" << endl;
					//cout << "\nToo many operators and not enough operands\n" << endl;
					flag = 1;
					break;
				}
				
				operand1 = s1.pop();
				//cout << "operator 1:" << operand1 << endl;
				if (operand1 == "\0")
				{
					cout << "\nInvalid expression: Too many operators and not enough operands\n" << endl;
					//cout << "\nToo many operands and not enough operators\n" << endl;
					flag = 1;
					break;
				}
				expression = "( " + operand1 + " " + myoperator + " " + operand2 + " )";
				s1.push(expression);
			}
			else if (myoperator == " ")
			{
				continue;
			}
			else
			{
				s1.push(myoperator);
			}
		}
		if (!flag)
		{
			my_infix = s1.pop();
			if (s1.pop() == "\0")
			{
				if (my_infix.length() == 1)
				{
					cout << "\nThe infix is: ( " << my_infix << " )" << endl;
				}
				else
				cout << "\nThe infix is: " << my_infix << endl;
			}
			else
			{
				cout << "\nInvalid expression: Too many operands and not enough operators\n" << endl;
				while (s1.pop() != "\0");
			}
		}
		else
		{
			flag = 0;
		}

	cout << "\nWould you like to convert another postfix expression to an infix expression? (Y or N) " << endl;
	cin >> retry;
	getchar();
	cout << endl;
	}
	while (retry == "y" || retry == "Y");

	return 0;

	/*END TEST 1 **********************************************************************************************/
}
#include "vlist.h" 
#include "vlist.cpp" 

using namespace std;

/*********************************************************************************************
				v l i s t _ d r i v e r . c p p (given)
**********************************************************************************************

Name: Kevin Tudor (z23468207)
Course: Date Structures/Algorithm Analysis  (COP3530)   Professor: Dr. Lofton Bullard
Due Date: 03/19/2021									Due Time: 11:59pm
Total Points: 25										Module 9: use the vector class to manage a dynamic array

Description: use the vector class to manage a dynamic array
After completing this assignment you will be able to perform the following:

(1) Manage a vector(allocatm and de-allocate memory, insert inorder, remove, etc).
(2) Implement a default constructor and a copy constructor.
(3) Implement an insert function to add a string, in order, into a vector
(4) Implement a remove function to delete a string from a vector
*********************************************************************************************/

int main()
{
	/* Test 1 ***********************************************************************************/
	//Testing default constructor
	cout << "***********************************************************" << endl;
	cout << "Test1:Testing the default constructor for string\n";
	vlist String_List;
	cout << endl << endl;
	cout << "*****************End of Test1******************************\n" << endl;
	/* End Test 1 ***********************************************************************************/

	/* Test 2 ***********************************************************************************/
	//Testing functionality for string list 
	cout << "***********************************************************" << endl;
	cout << "Test2: Testing Insert \n";
	String_List.insert("Hello");          
	String_List.insert("Zebra");
	String_List.insert("Good_Bye");
	String_List.insert("Space");
	String_List.insert("No_One");
	String_List.print();
	cout << "*****************End of Test2******************************\n" << endl;
	/* End Test 2 ***********************************************************************************/

	/* Test 3 ***********************************************************************************/
	cout << endl << endl;
	cout << "***********************************************************" << endl;
	cout << "Test 3: Testing copy constructor for string \n";
	vlist Copied_String = String_List;
	cout << "Copied String: ";
	Copied_String.print();
	cout << "Original String: ";
	String_List.print();
	cout << "*****************End of Test3******************************\n" << endl;
	/* End Test 3 ***********************************************************************************/

	/* Test 4 ***********************************************************************************/
	cout << endl << endl;
	cout << "***********************************************************" << endl;
	cout << "Test 4: Testing Remove for string \n";
	cout << "Testing Search and IsEmpty also\n";
	String_List.remove("Zebra");
	String_List.remove("Good_Bye");
	String_List.remove("Hello");
	String_List.remove("No_One");
	String_List.remove("Space");
	String_List.remove("Hello");

	if (String_List.isEmpty())
	{
		cout << "String_List is Empty!" << endl;
	}
	else
	{
		cout << "String_List is NOT Empty!" << endl;
	}
	cout << "*****************End of Test4******************************\n" << endl;
	/* End Test 4 ***********************************************************************************/
	cout << endl << endl;
	cout << "When end -> main destructor will be called" << endl;

	return 0;
}

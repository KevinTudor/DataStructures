#include "bst.h"
#include "bst.cpp"

using namespace std;

/*********************************************************************************************
				b s t _ d r i v e r . c p p (given)
**********************************************************************************************

Name: Kevin Tudor (z23468207)
Course: Date Structures/Algorithm Analysis  (COP3530)   Professor: Dr. Lofton Bullard
Due Date: 04/18/2021									Due Time: 11:59pm
Total Points: 25										Module 11: Binary search tree

Description: This is a simple program to give the student experience writing code
for binary trees.  This is a CLASS implementation of the BST ADT.
The student should study, comment, correct errors, compile,
implement/un-implemented/undeveloped functions, and modify code to make
it more efficient when ever necessary. The student should be able to
discuss the advantages and disadvantages of using such an
implementation.

*********************************************************************************************/

int main()
{
	/*Test 1*/
	cout << "**************************************************************" << endl;
	cout << "Test1: default constuctor" << endl;
	bst myTree;
	cout << "\n\nPrint contents of bst in order to the screen" << endl << endl;
	myTree.print_tree();

	myTree.count();
	myTree.count2();

	cout << "*************End Test1*****************************************" << endl;
	cout << endl << endl;
	/*End Test 1*/

	/*Test 2*
	cout << "**************************************************************" << endl;
	cout << "Test2: insert" << endl;
	myTree.insert("New County", 234658);
	cout << endl << "\n\nPrint contents of bst in order to the screen" << endl << endl;;
	myTree.print_tree();
	cout << "*************End Test2*****************************************" << endl;
	cout << endl << endl;
	/*End Test 2*/

	/*Test 3*
	cout << "**************************************************************" << endl;
	cout << "Test3: county_ranges" << endl;
	cout << "Print contents of bst range between B and K in order to the screen (INCLUSIVELY)" << endl << endl;; //including b and k
	myTree.county_ranges("B", "K");
	cout << "*************End Test3*****************************************" << endl;
	cout << endl << endl;
	/*End Test 3*/

	/*Test 4*
	cout << "**************************************************************" << endl;
	cout << "Test4: del_name" << endl;
	myTree.del_name("Miami Dade");
	cout << endl << "Print contents of bst in order, with Miami Dade removed, to the screen" << endl << endl;;
	myTree.print_tree();
	cout << "*************End Test4*****************************************" << endl;
	cout << endl << endl;
	/*End Test 4*/

	/*Test 5*
	cout << "**************************************************************" << endl;
	cout << "Test5: sorted_info" << endl << endl;
	cout << "Print contents of bst inorder to the output file, county_info.txt, with name and associated population size shown" << endl << endl;
	myTree.sorted_info();
	cout << "*************End Test5*****************************************" << endl;
	cout << endl << endl;
	/*End Test 5*/

	/*Test 6*
	cout << "**************************************************************" << endl;
	cout << "Test6: empty_tree" << endl << endl;
	myTree.empty_tree();
	cout << endl << "Print contents of an empty bst to the screen" << endl << endl;;
	myTree.print_tree();
	cout << "*************End Test6*****************************************" << endl;
	cout << endl << endl;
	/*End Test 6*/

	return 0;
}

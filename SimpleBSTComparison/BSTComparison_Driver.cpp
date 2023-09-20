#include "BSTComparison.h"
#include "BSTComparison.cpp"

using namespace std;

/*********************************************************************************************
				B S T C o m p a r i s o n _ d r i v e r . c p p
**********************************************************************************************

Name: Kevin Tudor (z23468207)
Course: Date Structures/Algorithm Analysis (COP3530)   Professor: Dr. Lofton Bullard
Due Date: NONE									       Due Time: NONE
Total Points: 0										   Module 11B: CHECK IF 2 BINARY SEARCH TREES ARE EQUAL

Description: CHECK IF 2 BINARY SEARCH TREES ARE EQUAL

*********************************************************************************************/

int main()
{
	/*Test 1*/
	cout << "**************************************************************" << endl;
	cout << "Test1: default constuctor" << endl;

	bst myTree;
	bst myTree2;

	myTree.insert(-6);
	//myTree2.del_name(1);
	myTree2.del_name(2);
	myTree2.del_name(3);

	cout << "Tree 1" << endl;
	myTree.print_tree();
	cout << "Tree 2" << endl;
	myTree2.print_tree();


	if (myTree.count() == 0)
	{
		cout << "Tree 1 is empty" << endl;
	}
	if (myTree2.count() == 0)
	{
		cout << "Tree 2 is empty" << endl;
	}

	if (myTree.count() == 0 && myTree2.count() == 0)
	{
		cout << "\nBoth trees are empty so they have the same number of nodes (0)" << endl;
	}
	else 
	{
		if (myTree.count() == myTree2.count())
		{
			cout << "Both trees are equal" << endl;
		}
		else
		{
			cout << "Trees are not equal" << endl;
			cout << "\nTree 1 has " << myTree.count() << " nodes \n" << endl;
			cout << "\nTree 2 has " << myTree2.count() << " nodes \n" << endl;
		}
	}

	cout << "*************End Test1*****************************************" << endl;
	cout << endl << endl;

	/*End Test 1*/

	return 0;
}

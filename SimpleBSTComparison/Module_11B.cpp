#include "Module_11B.h"
#include <fstream>
#include <stdlib.h> 

using namespace std;

/*********************************************************************************************
				M o d u l e _ 1 1 B . c p p
**********************************************************************************************

Description: CHECK IF 2 BINARY SEARCH TREES ARE EQUAL

*********************************************************************************************/


/*********************************************************************************************
Function Name: Default Constructor
Description: the default constructor will open the test2 file holding a list of numbers to add to
the BST.
*********************************************************************************************/
bst::bst()
{
	root = 0;

	ifstream data;

	data.open("test2.txt");

	if (data.fail())
	{
		cout << "Country Data input did not load.\n\n";
		exit(1);
	}
	else
	{
		//cout << "Country data input success\n\n";
	}

	string temp;
	int pop;

	while (!data.eof())
	{
		getline(data, temp);

		pop = stod(temp);

		insert(pop);
	}
}


/*********************************************************************************************
Function Name: isempty?
Description: returns whether or not the tree is empty.
*********************************************************************************************/
bool bst::empty()
{
	return (root == 0);
}


/*********************************************************************************************
Function Name: insert AUX (for main)
Description: this function will be used in the main and overloaded insert to recursivly navigate
the tree and insert the data into its respective location.
*********************************************************************************************/
void bst::insert(const int& population)
{
	insert(root, population);
}


/*********************************************************************************************
Function Name: insert
Description: this overloaded insert function will recursivly navigate the tree from lchild (lowest)
to rchild(highest).
*********************************************************************************************/
void bst::insert(treenode*& loc_ptr, const int& population)
{
	if (loc_ptr == 0) // base case, tree is empty create new node
	{
		loc_ptr = new treenode;
		loc_ptr->lchild = loc_ptr->rchild = 0;
		//loc_ptr->county_name = item;
		loc_ptr->number = population;
	}
	else if (loc_ptr->number > population)
		insert(loc_ptr->lchild, population);
	else if (loc_ptr->number < population)
		insert(loc_ptr->rchild, population);
	else
		cout << "the item is already in the tree\n";
}



/*********************************************************************************************
Function Name: print tree AUX (for main)
Description: This recursive function will be used in the main and the overloaded print tree function
to navigate the tree and print the items.
*********************************************************************************************/
void bst::print_tree()
{
	print_tree(root);
}


/*********************************************************************************************
Function Name: print tree (inorder)
Description: This recursive function will be used in the main and the overloaded print tree function
to navigate the tree and print the items.
*********************************************************************************************/
void bst::print_tree(treenode*& loc_ptr)
{
	if (loc_ptr != 0)
	{


		/* (in order LVR) */

		print_tree(loc_ptr->lchild);
		cout << setw(12) << loc_ptr->number << endl;
		//cout << setw(12) << loc_ptr->population_size << endl;  //echo for testing
		print_tree(loc_ptr->rchild);

		/* end in order */

		/* (preorder VLR) *

		cout << loc_ptr->county_name << endl;
		print_tree(loc_ptr->lchild);
		print_tree(loc_ptr->rchild);

		/* end preorder */

		/* (postorder LRV) *

		print_tree(loc_ptr->lchild);
		print_tree(loc_ptr->rchild);
		cout << loc_ptr->county_name << endl;

		/* end postorder */
	}
}



/*********************************************************************************************
Function Name: del name AUX (far main)
Description: This function will be used in the main and the overloaded del name function
to navigate the tree and delete the item.
*********************************************************************************************/
void bst::del_name(int number)
{
	del_name(root, number);
}


/*********************************************************************************************
Function Name: del name
Description: This overloaded del name function will be used to navigate the tree and delete the item.
*********************************************************************************************/
void bst::del_name(treenode*& loc_ptr, int item)
{

	if (loc_ptr == 0) //base case return root = 0 (else search tree)
		cout << "Item not in the tree\n";

	else if (loc_ptr->number > item)
		del_name(loc_ptr->lchild, item);

	else if (loc_ptr->number < item)
		del_name(loc_ptr->rchild, item);

	else
	{
		treenode* ptr;

		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->number = ptr->number;
			del_name(loc_ptr->rchild, ptr->number);
		}
	}
}


/*********************************************************************************************
Function Name: in order succ
Description: reorders the left and right nodes if an item is deleted by shifting the pointers.
*********************************************************************************************/
treenode* bst::inorder_succ(treenode* loc_ptr)
{
	treenode* ptr = loc_ptr->rchild;

	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}
	return ptr;
}


/*********************************************************************************************
Function Name: count node aux
Description: de-allocate all nodes that were allocated to the bst
*********************************************************************************************/
int bst::count()
{
	return count(root);
}

/*********************************************************************************************
Function Name: count nodes
Description: count the # of nodes in BT
*********************************************************************************************/
int bst::count(treenode* loc_ptr)
{
	if (loc_ptr == 0)
	{
		return 0;
	}
	else
	{
		return 1 + count(loc_ptr->lchild) + count(loc_ptr->rchild);
	}
}


/*********************************************************************************************
Function Name: count nodes with 2 children AUX
Description: count the # of nodes in BT
*********************************************************************************************/
int bst::count2()
{
	return count2(root);
}


/*********************************************************************************************
Function Name: count nodes with 2 children
Description: count the # of nodes in BT with 2 children
*********************************************************************************************/
int bst::count2(treenode* loc_ptr)
{
	if (loc_ptr == 0)
	{
		return 0;
	}
	else if (loc_ptr->lchild != 0 && loc_ptr->rchild != 0)
	{
		return 1 + count2(loc_ptr->lchild) + count2(loc_ptr->rchild);
	}
	else
	{
		return count2(loc_ptr->lchild) + count2(loc_ptr->rchild);
	}
}


/*********************************************************************************************
Function Name: destructor
Description: de-allocates dynamic memory allocate for tree
*********************************************************************************************/
bst::~bst()
{
	cout << "The Destructor called" << endl;

	while (root != 0)
	{
		del_name(root->number);
	}
}


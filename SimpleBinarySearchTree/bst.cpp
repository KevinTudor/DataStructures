#include "bst.h"
#include <fstream>
#include <stdlib.h> 

using namespace std;

/*********************************************************************************************
				b s t . c p p
**********************************************************************************************

Description: This is a simple program to give the student experience writing code
for binary trees.  This is a CLASS implementation of the BST ADT.
The student should study, comment, correct errors, compile,
implement/un-implemented/undeveloped functions, and modify code to make
it more efficient when ever necessary. The student should be able to
discuss the advantages and disadvantages of using such an
implementation.

*********************************************************************************************/


/*********************************************************************************************
Function Name: Default Constructor
Description: the default constructor will open the test file holding all county names and populations.
It will then get each line and split the line by the first space it finds and created substrings of name and population.
The substring containing the population would not stod correctly if the string of numbers was 7 digits or more.
Default constructor will then insert each lines country name and population.
*********************************************************************************************/
bst::bst()
{
	root = 0;

	ifstream data;

	data.open("Data/RawData.txt");

	if (data.fail())
	{
		cout << "Country Data input did not load.\n\n";
		exit(1);
	}
	else
	{
		cout << "Country data input success\n\n";
	}

	string temp, name, population;
	int pop;
	
	//long double poptest = 1234567; //stod will not work for string of 7 digits. (I kept getting ######e# the dtod would only work on 6 digits and float the final integer as a straing e double)

	while (!data.eof())
	{
		getline(data, temp);

		for (int i = 0; i <= temp.length(); i++)
		{
			if (temp[i] == ' ')
			{
				name = temp.substr(0, i);
				population = temp.substr(i + 1);
			}
		}

		pop = stoi(population);
		//(READ ME) neither stod or static/type cast would correctly convert a string of 7 digits. (I kept getting ######e# the dtod would only work on 6 digits and float the final integer as a straing e double)
		//int popint = stoi(population);
		//double pop = (double)popint;

		//cout << setw(12) << name << setw(12) << population << endl;

		insert(name, pop);
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
void bst::insert(const string& item, const int& population)
{
	insert(root, item, population);
}


/*********************************************************************************************
Function Name: insert
Description: this overloaded insert function will recursivly navigate the tree from lchild (lowest) 
to rchild(highest).
*********************************************************************************************/
void bst::insert(treenode*& loc_ptr, const string& item, const int& population)
{
	if (loc_ptr == 0) // base case, tree is empty create new node
	{
		loc_ptr = new treenode;
		loc_ptr->lchild = loc_ptr->rchild = 0;
		loc_ptr->county_name = item;
		loc_ptr->population_size = population;
	}
	else if (loc_ptr->county_name > item)
		insert(loc_ptr->lchild, item, population);
	else if (loc_ptr->county_name < item)
		insert(loc_ptr->rchild, item, population);
	else
		cout << "the item is already in the tree\n";
}


/*********************************************************************************************
Function Name: search tree AUX (for main)
Description: This function will be used in the main and the overloaded search tree function 
to navigate the tree and search from lowest to highest for the item.
*********************************************************************************************/
treenode* bst::search_tree(string item)
{
	return search_tree(root, item);
}


/*********************************************************************************************
Function Name: search tree 
Description: This overloaded search tree function will be used to navigate the tree and search
from lowest to highest for the item by recursively checking the left child then the right child.
*********************************************************************************************/
treenode* bst::search_tree(treenode* loc_ptr, string item)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->county_name == item) //base case
		{
			return loc_ptr;
		}	
		else if (loc_ptr->county_name > item)
			return search_tree(loc_ptr->lchild, item);
		else
			return search_tree(loc_ptr->rchild, item);
	}
	else
		return loc_ptr;
}


/*********************************************************************************************
Function Name: del name AUX (far main)
Description: This function will be used in the main and the overloaded del name function 
to navigate the tree and delete the item.
*********************************************************************************************/
void bst::del_name(string item)
{
	del_name(root, item);
}


/*********************************************************************************************
Function Name: del name
Description: This overloaded del name function will be used to navigate the tree and delete the item.
*********************************************************************************************/
void bst::del_name(treenode*& loc_ptr, string item)
{

	if (loc_ptr == 0) //base case return root = 0 (else search tree)
		cout << "Item not in the tree\n";

	else if (loc_ptr->county_name > item)
		del_name(loc_ptr->lchild, item);

	else if (loc_ptr->county_name < item)
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
			loc_ptr->county_name = ptr->county_name;
			del_name(loc_ptr->rchild, ptr->county_name);
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
Function Name: country ranges AUX (for main)
Description: This recursive function will be used in the main and the overloaded county ranges function.
*********************************************************************************************/
void bst::county_ranges(const string& min_name, const string& max_name) //recursive
{
	county_ranges(root, min_name, max_name); //(recursive)
}


/*********************************************************************************************
Function Name: country ranges
Description:This recursive overloaded country ranges function will be used to navigate the tree
and print out the given (min-max) county ranges. (INCLUSIVE)
*********************************************************************************************/
void bst::county_ranges(treenode*& loc_ptr, const string& min_name, const string& max_name)
{
	if (loc_ptr != 0)    
	{
		county_ranges(loc_ptr->lchild, min_name, max_name);                      //(recursive) lchild < r < rchild

		if (loc_ptr->county_name[0] >= min_name[0] && loc_ptr->county_name <= max_name) //inclusively
		{
			cout << setw(12) << loc_ptr->county_name << endl;
		}

		county_ranges(loc_ptr->rchild, min_name, max_name);                       //(recursive)
	}
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
		cout << setw(12) << loc_ptr->county_name << endl;
		//cout << setw(12) << loc_ptr->population_size << endl;  //echo for testing
		print_tree(loc_ptr->rchild);
		/* end in order */

		/* (preorder VLR) */
		cout << loc_ptr->county_name << endl;
		print_tree(loc_ptr->lchild);
		print_tree(loc_ptr->rchild);
		/* end preorder */

		/* (postorder LRV) */
		print_tree(loc_ptr->lchild);
		print_tree(loc_ptr->rchild);
		cout << loc_ptr->county_name << endl;
		/* end postorder */
	}
}


/*********************************************************************************************
Function Name: sorted info AUX (for main)
Description: This recursive function will be used in the main and the overloaded sorted info function 
to navigate the tree and print the items to a new sorted output file (country_info.txt).
*********************************************************************************************/
void bst::sorted_info()
{
	ofstream sorted;

	sorted.open("country_info.txt");

	if (sorted.fail())
	{
		cout << "Country Data output file did not load.\n\n";
		exit(1);
	}
	else
	{
		cout << "Country data output success\n\n";
	}

	sorted_info(sorted, root);

	sorted.close();
}


/*********************************************************************************************
Function Name: sorted info
Description: This recursive function will be used to navigate throughout the tree and diplay
the contents to the screen in order.
*********************************************************************************************/
void bst::sorted_info(ostream& sorted, treenode*& loc_ptr)
{
	if (loc_ptr != 0)
	{
		sorted_info(sorted, loc_ptr->lchild);
		sorted << setw(12) << loc_ptr->county_name << setw(12) << loc_ptr->population_size << endl;
		sorted_info(sorted, loc_ptr->rchild);
	}
}


/*********************************************************************************************
Function Name: empty tree
Description: de-allocate all nodes that were allocated to the bst
*********************************************************************************************/
void bst::empty_tree()
{
	bst::~bst();
}


/*********************************************************************************************
Function Name: count node aux
Description: de-allocate all nodes that were allocated to the bst
*********************************************************************************************/
void bst::count()
{
	count(root);
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
void bst::count2()
{
	count2(root);
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
		del_name(root->county_name);
	}
}


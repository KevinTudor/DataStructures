#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <iomanip>


using namespace std;

/*********************************************************************************************
				M o d u l e _ 1 1 B . h		 (class declarations)
**********************************************************************************************

	Description: CHECK IF 2 BINARY SEARCH TREES ARE EQUAL

*********************************************************************************************/

#ifndef BST
#define BST

class treenode //node 
{
public:
	int number;        //stod would not convert string of 7 digit correctly
	treenode* lchild, * rchild; //left and right children pointers 
};

class bst
{
public:
	bst();                   //store the data file (county_data.txt) into initial bst. 
	~bst();                  //de-allocates dynamic memory allocate for tree               

	bool empty();                                                       //return true if bst is null; otherwise false is retured.
	void insert(const int& population);             //auxiliary function.
	void insert(treenode*&, const int& population); //inserts an item into the bst; this function is invoked, in main, by the auxiliary function described above.

	void del_name(const int population);                            //auxiliary function. 
	void del_name(treenode*& loc_ptr, const int population);        //function deletes an item from the bst; this function is invoked, in main, by the auxiliary function described above. 					        
	treenode* inorder_succ(treenode*);                     //returns a pointer to the inorder successor, based on county name.									   
	void print_tree();                       //auxiliary function. 
	void print_tree(treenode*&);             //prints each county record to the screen sorted by county name. "loc_ptr"

	int count();                   //counts number of nodes in a tree
	int count(treenode* loc_ptr);

	int count2();                 //counts the number of nodes with 2 children in a tree
	int count2(treenode* loc_ptr);

private:
	treenode* root;
};

#endif
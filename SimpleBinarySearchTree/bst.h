#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <iomanip>


using namespace std;

/*********************************************************************************************
				b s t . h		 (given class declarations)
**********************************************************************************************

	Description: BINARY SEARCH TREE

*********************************************************************************************/

#ifndef BST
#define BST

class treenode //node 
{
public:
	string county_name;
	int population_size;        //stod would not convert string of 7 digit correctly
	treenode* lchild, * rchild; //left and right children pointers 
};

class bst
{
public:
	bst();                   //store the data file (county_data.txt) into initial bst. 
	~bst();                  //de-allocates dynamic memory allocate for tree               
																		    
	bool empty();                                                       //return true if bst is null; otherwise false is retured.
	void insert(const string& item, const int& population);             //auxiliary function.
	void insert(treenode*&, const string& item, const int& population); //inserts an item into the bst; this function is invoked, in main, by the auxiliary function described above.
			  
	void del_name(string item);                            //auxiliary function. 
	void del_name(treenode*& loc_ptr, string item);        //function deletes an item from the bst; this function is invoked, in main, by the auxiliary function described above. 					        
	treenode* search_tree(string item);                    //auxiliary fucntion
	treenode* search_tree(treenode* loc_ptr, string item); //returns a pointer to the node in bst with a  
				                                           //county name county name that matches item; this function is invoked, in main, by the auxiliary function describes above.
	
	treenode* inorder_succ(treenode*);                     //returns a pointer to the inorder successor, based on county name.									   
	void county_ranges(const string& min_name, const string& max_name);                     //auxiliary function.
	void county_ranges(treenode*& loc_ptr, const string& min_name, const string& max_name); //prints all the county names to the screen that lie between min_name and max_name, inclusive.					
	void print_tree();                       //auxiliary function. 
	void print_tree(treenode*&);             //prints each county record to the screen sorted by county name. "loc_ptr"
	void sorted_info();                      //auxiliary function.
	void sorted_info(ostream&, treenode*&);  //prints each county record to a file called county_info.txt sorted by county name. "out", "loc_ptr"
	void empty_tree();                       //de-allocate all nodes that were allocated to the bst

	void count();
	int count(treenode* loc_ptr);

	void count2();
	int count2(treenode* loc_ptr);

private:
	treenode* root;
};

#endif
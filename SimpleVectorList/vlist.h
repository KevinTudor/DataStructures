#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*********************************************************************************************
				v l i s t . h		 (given class declarations)
**********************************************************************************************

	Description: Vector List

*********************************************************************************************/

#ifndef vlist_H
#define vlist_H

class vlist
{
public:
	vlist();
	vlist(const vlist&);
	~vlist();
	bool isEmpty();
	vector<string>::iterator search(const string&);
	void insert(const string&);
	void remove(const string&);
	void print();
private:
	vector<string> DB;
	int count;
};

#endif

/*********************************************************************************************
				NOTES
**********************************************************************************************

	Member of the vector class: 

	resize(integer) DB.resize(9);
	clear() - DB.clear(); clears cells of value, but does not de-allocate the memory
	shrink_to_fit() - DB.shrink_to_fit() de-allocate cells
	size() - return capacity (amount of cells you have)
	end() - returns an iterator at the cell after the end of the vector
	begin() - returns an iterator to the begining of the vector, (points to it)
	insert(iterator, key) - 
	erase(iterator) - 
	operator= - 
	.at - 
	.push_back - put some element into the DB into the end of current vector


*********************************************************************************************/


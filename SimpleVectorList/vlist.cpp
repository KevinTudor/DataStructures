#include "vlist.h" 

using namespace std;

/*********************************************************************************************
				v l i s t . c p p
**********************************************************************************************

Description: This file contains the 'main' function. Program execution begins and ends there.

*********************************************************************************************/


/*********************************************************************************************
Function Name: vlist
Precondition: Constructor has not been invoked.
Postcondition: count = 0; vector size is 9.
Description: Constructs an instance of a vlist object.
*********************************************************************************************/
vlist::vlist()
{
	cout<<"Default Constructor Invoked"; 

	count = 0;
	DB.resize(9);
}


/*********************************************************************************************
Function Name: vlist (copy constructor)
Precondition: A vlist object is being passed by reference.
Postcondition: A hard copy of a vlist object has been created.
Description: Creates a hard copy of a vlist object and prints the contents of each vlist object on
single separate lines.
*********************************************************************************************/
vlist::vlist(const vlist& Org)
{
	cout << "Copy Constructor Invoked\n";

	DB = Org.DB;
	count = Org.count;
	print();
}

/*********************************************************************************************
Function Name: ~vlist
Precondition: Destructor has not been invoked.
Postcondition: array DB deleted.
Description: Deallocates memory of a vlist object.
*********************************************************************************************/
vlist::~vlist()
{
	cout << "~Destructor Invoked" << endl;

	DB.clear();
	DB.shrink_to_fit();
}


/*********************************************************************************************
Function Name: isEmpty
Precondition: vector list object is created
Postcondition: returns true if object count = 0 false if not.
Description: returns true if object count = 0 false if not.
*********************************************************************************************/
bool vlist::isEmpty() 
{ 
	return count == 0;
}


/*********************************************************************************************
Function Name: vector<string>::iterator vlist::search(const string& key)
Precondition: vector list object is created
Postcondition: function returns pointer i to the location of the key in the vector.
Description: function uses a for loop to iterate through the list and check if the
element at location the pointer points to is equal to the key.
*********************************************************************************************/
vector<string>::iterator vlist::search(const string& key)
{
	for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++)
	{
		if (*i == key)
		{
			return i;
		}
	}
	return DB.end();
}


/*********************************************************************************************
Function Name: insert
Precondition: function called in the driver to add new element into the list.
Postcondition: adds an item to the vector in order (alphabetical order).
Description: if the list is currently empty the function will insert the first given element, 
if not empty the function will determine if the key is supposed to go before the current item and will insert
the given element into the vector list.
*********************************************************************************************/
void vlist::insert(const string& key)
{
	if (DB.size() == 0)
	{
		DB.push_back(key);
	}
	else
	{
		for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++) 
		{
			if (*i >= key)
			{
				cout << key << " > DB:" << *i << endl;
				DB.insert(i, key);
				count++;
				return;
			}
		}
		DB.insert(DB.end(), key);
		count++;
	}
}


/*********************************************************************************************
Function Name: remove
Precondition: function called in the driver to remove given element from the list.
Postcondition: removes an item from the vector if it is there, otherwise prints a message stating it was not in vector.
Description: use an iterator and the erase function to remove an item from the vector.
*********************************************************************************************/
void vlist::remove(const string& key)
{
	vector<string>::iterator position= search(key);
	if (position != DB.end())
	{
		DB.erase(position);
		count--;
	}
	else
	{
		cout << "We could not find the item in the vector\n";
	}

}


/*********************************************************************************************
Function Name: print
Precondition: function called in the driver to print all elements of the list.
Postcondition: print every item stored in the vector.
Description: print every item stored in the vector.
*********************************************************************************************/
void vlist::print() 
{
	//cout << "Print Invoked" << endl;
	
	for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++)
	{
		cout <<  *i << " ";
	}
	cout << endl;
}


/* END vlist.cpp ********************************************************************************************/
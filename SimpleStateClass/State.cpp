
#include "state.h"
#include <iomanip>  //need to use formatting manipulators



/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Default Constructor
Pre-Conditon: The count, capacity, and the dynamic array (pop_DB) have not been initialized.
Post-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
Description:  The function initiailizes the state (private data) of the class state_class. It reads the data stored in the datafile "census2020_data.txt"
			  into the dynamic array, pop_DB.  Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.  If pop_DB become full,
			  double_size is called, which doubles the capacity of pop_DB. The function initializes string linereader in order to take input from the file containing
			  numbers and words. It also initializes int spacelocation in order to index the location of the final space before the popluation numbers. It creates an
			  input file named in to read in data from the census 2020 file. while it is not the end of the file if the array is count = capacity the function will
			  call double size and create more memory for the array. It then gets the entire line and seperates the state name and the state populations.

**********************************************************************************************************************************************************/
state_class::state_class()
{
	//intially count, capacity, and pop_DB are initialized with the following values:

	cout << "Default Constructor\n";
	count = 0;
	capacity = 5;
	pop_DB = new population_record[capacity];

	string lineReader;
	int spacelocation = 0;

	ifstream in;
	in.open("census2020_data.txt");

	while (!in.eof())
	{
		if (Is_Full())
			double_size();

		getline(in, lineReader);

		for (int i = lineReader.length() - 1; i >= 0; i--)
		{
			if (lineReader[i] == ' ')
			{
				spacelocation = i;
				break;
			}
		}
		pop_DB[count].state_name = lineReader.substr(0, spacelocation);        // takes input from begining of the line to the final space and puts it into .statename.  
		pop_DB[count].population = stod(lineReader.substr(spacelocation + 1, lineReader.length() - spacelocation - 1));

		count++;
		//spacelocation = 0;
	}
	in.close();
}

/******************************************************************************************************************************************************
Name: Copy Constructor
Pre-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
Post-Condition The copy constructor will create a new dynamic array containing the same values as the default construstor
Description: The purpose of the copy construstor was to transfer the values of count and capacity from the original array to 
create a new dynamic array so changes can be made to one of the copies.
******************************************************************************************************************************************************/
state_class::state_class(const state_class& org)
{
	//place your code here
	cout << "Copy constructor invoked\n";

	capacity = org.capacity;

	count = org.count;

	pop_DB = new population_record[capacity];

	for (int i = 0; i < capacity; i++)
	{
		pop_DB[i] = org.pop_DB[i];
	}
}

/******************************************************************************************************************************************************
Name: Destructor
Pre-Condition: Dynamic array pop_DB has been declared and memory allocated
Post-Condition: The destructor will delete the memory inside the dynamic array pop_DB
Description: The destructor function is implemented so memory can be de-allocated from the dynamic arrray.
******************************************************************************************************************************************************/
state_class::~state_class()
{
	//place your code here
	delete[] pop_DB;
}

/******************************************************************************************************************************************************
Name: Double Size
Pre-Condition: pop_DB dynamic array has no more memory space (Is_Full)
Post-Condition: The capacity and memory of pop_DB will double in size.
Description: The purpose of this function was to double the size of the array capacity (memory allocation) so all values in the census data will
have a memory location in the array pop_DB. This is done by locally doubling the value of capacity then filling in a temp array with values from pop_DB.
The function then deletes the old array and procedes to create a new pop_DB from the temp.
******************************************************************************************************************************************************/
void state_class::double_size()
{
	//place your code here
	capacity = capacity * 2;
	population_record*  temp = new population_record[capacity];
	for (int i = 0; i < count; i++) 
	{
		temp[i] = pop_DB[i];
	}
	delete[] pop_DB;        //deletes the old (small) array 
	pop_DB = temp;          //switches data from temp to new double size array pop_DB
}

/******************************************************************************************************************************************************
Name: operator+ 
Pre-Condition: The population of each state has a value allocated in the array from the census file.
Post-Condition: The function will add the population of the state in the array to the value in the main function with the corresponding state name. EX: r.state_name = "Alabama"; r.population = 1111111;
Description: The function will search for the given r.statename in the array then it will add the r.population value to the number already in the array from the file.
******************************************************************************************************************************************************/
void state_class::operator+(const population_record& r)
{
	cout << "operator + has been invoked \n";
	if (!Is_Full())
	{
		pop_DB[count].population = r.population;
		pop_DB[count].state_name = r.state_name;
		count++;
	}
}

/******************************************************************************************************************************************************
Name: Search
Pre-Condition: The operator+ or remove functions have been invoked
Post-Condition: The function will look through the array to find the given state count [i] value.
Description: The function loops through the array from [i] = 0 to [i] < count to find the [i] location of that state in the array. If it is not found 
the function returns -1 (error)
******************************************************************************************************************************************************/
int state_class::Search(const string& state)
{
	cout << "Search has been invoked \n";
	for (int i = 0; i < count; i++)
	{ 
		if (pop_DB[i].state_name == state) 
		{ 
			return i;
		} 
	}
	return -1;
}


/******************************************************************************************************************************************************
Name: Remove
Pre-Condition: Remove has been invoked
Post-Condition: The chosen state will be removed from the array and the next items in the array will take its place. no gap in the array
Description: The function will search for the given state and replace it with the next state. It will follow through with the remaining states effectively 
removing it without creating an empty memory location.
******************************************************************************************************************************************************/
void state_class::Remove(const string& state)
{
	cout << "Remove has been invoked \n";
	int i = Search(state);

	if (Is_Empty())
		cout << "Pop_DB is empty\n";
	else
	{
		for (int j = i; j < count - 1; j++) //shifting array down
		{
			pop_DB[j] = pop_DB[j + 1];
		}
		count--;
	}
}


/******************************************************************************************************************************************************
Name: Print all To file
Pre-Condition: The new array has been copied from the default constructor then sorted and organized to our liking and Print_ALL_To_File has been called with a valid filename.
Post-Condition: The sorted/organized values in the new array have been printed to the file named in the main.
Description: The function will create an object that will open an output file stream with a given filename in the main. It organized the output with flags
and outputs all statename and population values to the file.
******************************************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{
	ofstream output;
	output.open(filename);

	output.setf(ios::left);
	output.setf(ios::fixed);
	output.precision(0);

	if (output.is_open())
	{
		for (int i = 0; i < count; i++)
		{
			output << std::setw(20) << pop_DB[i].state_name << " " << pop_DB[i].population << endl;
		}
	}
	output.close();
}
/******************************************************************************************************************************************************
Name: Print all
Pre-Condition: Print All has been invoked and all items in the array are ready to be displayed.
Post-Condition: All items in the array have been neatly output to the screen using cout.
Description: The function sets flag to make the output more neat then it loops through the array using the i < count condition and outputs the items 
to the screen.
******************************************************************************************************************************************************/
void state_class::Print_ALL()
{
	cout.setf(ios::left);
	cout.setf(ios::fixed);
	cout.precision(0);

	cout << "Print All has been Invoked\n\n";
	
	for (int i = 0; i < count; i++) 
	{ 
		cout << std::setw(20) << pop_DB[i].state_name << " " << pop_DB[i].population  << endl;
	}
}


/******************************************************************************************************************************************************
Name: Print Range
Pre-Condition: Array has been allocated memory from the input file and all items in the array are ready to be displayed.
Post-Condition: Items in the array within the range given (min to max) are printed to the screen.
Description: The function sets flags so the output will be neat. It then loops through the array using i < count. If the pop_DB[i].population value is within
the given range the function will neatly ouput the state and population to the screen and continue the loop.
******************************************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
	cout.setf(ios::left);
	cout.setf(ios::fixed);
	cout.precision(0);

	for (int i = 0; i < count; i++)
	{
		if (pop_DB[i].population > min && pop_DB[i].population < max)
		{
			cout << std::setw(20) << pop_DB[i].state_name << " " << pop_DB[i].population << endl;
		}
	}
}


/******************************************************************************************************************************************************
Name: State Count
Pre-Condition: Array has been allocated memory from the input file and all items in the array are ready to be displayed.
Post-Condition: The states that satisfy the condition of having a population within the range will be printed.
Description: The function will loop through the array and increment the local state variable by 1 everytime it finds a population within the range.
The total amount of states in the file with the range should be 12.
******************************************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{
	int states = 0;
	for (int i = 0; i < count; i++) 
	{
		if (pop_DB[i].population > min && pop_DB[i].population < max)
		{
			states++;
		}
	}
	return states;
}

/******************************************************************************************************************************************************
Name: Insertion sort
Pre-Condition: Default constructor must be invoked
Post-Condition: The population record will be sorted based on the state name.
Description: In the sort function we are sorting the array based off the first letter of every state, first we set the key to type population_record, then we compare the state at index 0 with the state at index 1 and 
swap the states if the statename is greater the state name of the key (z - a). Then the key shifts to the next value in the array and the loop continues.
******************************************************************************************************************************************************/
void state_class::Sort()
{
	for (int i = 1; i < count; i++)
	{
		population_record key = pop_DB[i];									//setting key type population_record 
		int j = i - 1;														
		while (j >= 0 && pop_DB[j].state_name > key.state_name)             //comparing the state at index 0 with thte state at index 1 (first run of the loop)
		{
			pop_DB[j + 1] = pop_DB[j];                                      //swapping the states if the are not a - z
			j = j - 1;
		}
		pop_DB[j + 1] = key;                                                //key = the next value, next step in the loop
	}
}
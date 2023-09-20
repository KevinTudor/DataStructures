#include "date.h"

//*********************************************************************************************
//*********************************************************************************************
//	D A T E	. C P P


//This stub (for now) should be implemented in date.cpp
//*************************************************************************************
//Name:	Date (default constructor) sets m=01, d=01, y=0001
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description:	This is the default constructor which will be called automatically when
//an object is declared. It will initialize the state of the class
//
//*************************************************************************************
Date::Date()          
{
	cout << "Default constructor has been called" << endl;
	myMonth = 01;    //myMonth = 01;
	myDay = 01;      //myDay = 26; 
	myYear = 0001;   //myYear = 2020;
	cout << setfill('0') << setw(2) << myDay << "/";
	cout << setfill('0') << setw(2) << myMonth << "/";
	cout << setfill('0') << setw(4) << myYear << "\n" << endl;
}


//*************************************************************************************
//Name:	Date (explicit value constructor)
//Precondition: The unsigned value for the explicit value constructor have been given in test 1 - test 5
//Postcondition: The explicit value constructor will verify if the date given in the main is within reason
//Description: This function initialized the states of the object (private data) with the given values in the main and 
//checks if the given date has a valid month, day, and year. The function will first set two boolean variables. bool i will 
//be used to set a flag if the year is a leap year (TRUE IF IT IS A LEAP YEAR).The second bool is the bool flag, this is used to
//determine any "bad" day, month or year. The flag is set to true so if there is no "bad" day, month or year the program will display the date.
// If it is false the program will not display the date.
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	myMonth = m;
	myDay = d;
	myYear = y;

	bool i;  //check if leap year
	bool flag = true;  //check if date is correct and display if it is. Otherwise will only display incorrect portion of the date

	cout << "Explicit-value constructor has been called" << endl;
	

	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)               //formula to check if year is leap year
		i = true; //is leap year
	else
		i = false; //is not leap year


	if (myMonth < 1 || myMonth > 12) //month validator
	{
		cout << "Month = " << myMonth << " is incorrect" << endl;
		flag = false;
	}
		
	if (myDay < 0 || myDay > 31)
	{
		cout << "Day = " << myDay << " is incorrect" << endl;
		flag = false;
	}


	if (myMonth == 2)             //febuary (leap year/not leap year day validator)
	{
		if (i == true)
		{
			if (myDay < 1 || myDay > 29)
			{
				cout << "Day = " << myDay << " is incorrect" << endl;
				flag = false;
			}
		}
		else if (i == false)
		{
			if (myDay < 1 || myDay > 28)
			{
				cout << "Day = " << myDay << " is incorrect" << endl;
				flag = false;
			}
		}
	}


	if (myMonth == 1 || myMonth == 3 || myMonth == 5 || myMonth == 7 || myMonth == 8 || myMonth == 10 || myMonth == 12) //months with 31 days
	{
		if (myDay < 1 || myDay > 31)
		{
			cout << "Day = " << myDay << " is incorrect" << endl;
			flag = false;
		}
	}
	else if (myMonth == 4 || myMonth == 6 || myMonth == 9 || myMonth == 11) //months with 30 days
	{
		if (myDay < 1 || myDay > 30)
		{
			cout << "Day = " << myDay << " is incorrect" << endl;
			flag = false;
		}
	}
	

	if (myYear > 1) // year validator
	{
		if (i == true)
			cout << "This is a leap year" << endl;
	}
	else
	{
		cout << "Year = " << setfill('0') << setw(4) << myYear << " is incorrect" << endl;
		flag = false;
	}


	if (flag == true) //IF ALL PORTIONS OF THE DATE ARE CORRECT (TRUE) THE ENTIRE DATE IS DISPLAYED
		cout << myMonth << "/" << myDay << "/" << myYear << "\n" << endl;

}

//*************************************************************************************
//Name:	Display
//Precondition: myDay, myMonth, and myYear are all holding values
//Postcondition: myDay, myMonth, and myYear are displayed to screen in neat manner
//Description: The function allocates '0' to empty spaces in date portions and sets the width
//ex: 11/05/2020
//*************************************************************************************
void Date::display()
{
	cout << setfill('0') << setw(2) << myDay << "/";
	cout << setfill('0') << setw(2) << myMonth << "/";
	cout << setfill('0') << setw(4) << myYear << "\n" << endl;
}

//*************************************************************************************
//Name:	getMonth (accessor)
//Precondition: myMonth holds a value 
//Postcondition: functions returns the value held in myMonth
//Description: This function finds the value held in the given objects .myMonth and returns
//the value held when called.
//*************************************************************************************
int Date::getMonth()
{
	return myMonth;
}

//*************************************************************************************
//Name:	getDay (accessor)
//Precondition: myDay holds a value 
//Postcondition: functions returns the value held in myDay
//Description: This function finds the value held in the given objects .myDay and returns
//the value held when called.
//*************************************************************************************
int Date::getDay()
{
	return myDay;
}

//*************************************************************************************
//Name:	getYear (accessor)
//Precondition: myYear holds a value
//Postcondition: functions returns the value held in myYear
//Description:This function finds the value held in the given objects .myYear and returns
//the value held when called.
//*************************************************************************************
int Date::getYear()
{
	return myYear;
}

//*************************************************************************************
//Name: setMonth (mutator)
//Precondition: the main function calls .setMonth(); and gives a value to insert
//Postcondition: the function mutates the objects myMonth value to the value set in .setMonth();
//Description: the function sets the value of myMonth to the value of the variable m 
//given when called in the main
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	myMonth = m;
}

//*************************************************************************************
//Name:	setDay (mutator)
//Precondition: the main function calls .setDay(); and gives a value to insert
//Postcondition: the function mutates the objects myDay value to the value set in .setDay();
//Description: the function sets the value of myDay to the value of the variable d 
//given when called in the main
//*************************************************************************************
void Date::setDay(unsigned d)
{
	myDay = d;
}

//*************************************************************************************
//Name:	setYear (mutator)
//Precondition: the main function calls .setYear(); and gives a value to insert
//Postcondition: the function mutates the objects myYear value to the value set in .setYear();
//Description: the function sets the value of myYear to the value of the variable y 
//given when called in the main
//*************************************************************************************
void Date::setYear(unsigned y)
{
	myYear = y;
}

//*************************************************************************************
//Name:	operator<< (overload operator)
//Precondition: dateObj has been initialized with myDate, test22Date, and herDate.
//Postcondition: the function reference outputs the given objects month, day and year
//Description: the function outputs the given objects month, day and year with '/' between
//each portion of the date
//*************************************************************************************
ostream& operator<<(ostream& out, Date& dateObj)              
{
	out << dateObj.myMonth << "/" << dateObj.myDay << "/" << dateObj.myYear;
	return out;
}
#include "date.h"
#include "date.cpp"


//*********************************************************************************************
//*********************************************************************************************
//	D A T E	D R I V E R . C P P


//EXAMPLE OF PROGRAM HEADER
/********************************************************************************************

Name: Kevin Tudor (Z23468207)
Course: Date Structures and Algorithm Analysis  (COP3530) Professor: Dr. Lofton Bullard
Due Date: 1/29/29								Due Time: 12:00 am
Total Points: 25                                Assignment 3: Date program

Description: The purpose of this program is to determine if a user inputs a valid date. 
The program will test the month, day, and year and echo back any portion of the date that is invalid.
The program is able to determine if the year is a leap year. It also will determine if the particular month has 
28,29,30 or 31 days depending on the month and if it is a leap year (for febuary).


*********************************************************************************************/


int main()
{

	Date myDate;
	Date herDate(11, 14, 1953);
	Date test1Date(25, 1, 1982);  //should generate error message that bad month
	Date test22Date(2, 29, 2020); //ok, should say leep year (2020)
	Date test3Date(2, 30, 2021);  //should generate error message that bad day
	cout << endl;				  //for EXACT same spacing as expected output
	Date test4Date(1, 25, 0000);  //should generate error message that bad year
	cout << endl;				  //for EXACT same spacing as expected output
	Date test5Date(80, 40, 0000); //should generate error message that bad month, day and year
	cout << endl;

	herDate.display();
	cout << herDate.getMonth() << endl;
	cout << herDate.getDay() << endl;
	cout << herDate.getYear() << endl;
	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);
	cout << "myDate: " << myDate << " test22Date: " << test22Date << " herDate: " << herDate << endl;

	return 0;

}



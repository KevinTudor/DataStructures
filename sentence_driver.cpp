#include "sentence.h"
#include "sentence.cpp"


/*********************************************************************************************
				S E N T E N C E _ D R I V E R . C P P  (given)
**********************************************************************************************

Name: Kevin Tudor (Z23468207)
Course: Date Structures/Algorithm Analysis  (COP3530)   Professor: Dr. Lofton Bullard
Due Date: 02/19/2021									Due Time: 12:00 am
Total Points: 25										Module 6: LINKED LISTS

Description: The purpose of this program is to ...


*********************************************************************************************/


using namespace std;

int main()
{
	/*TEST 1 **********************************************************************************************/
	cout << "****Test#1: default constructor, length, and operator<<***\n\n";
	sentence you;
	cout<<"\""<<you << "\"" <<" : length = "<<you.length()<< endl;
	cout<<"\n****End of Test#1*******************************************\n";
	cout<<endl;

	/*TEST 2 **********************************************************************************************/
	cout << "****Test#2: explicit-value constructor, length, and operator<<***\n\n";
	sentence me("Today is a wonderful day!   ");										//sentence with 3 spaces at end
	cout<<"me is "<<"\""<<me<<"\""<<" =  "<<"\""<<"Today is a wonderful day!   "<<"\""<<"\n";
	cout << "The length of me is " << me.length() << "\n\n";
	sentence me_to("");
	cout << "me_to is " << "\"" << me_to << "\"" << " = " << "\""<< "\""<<"\n";			//sentence should be empty string
	cout << "The length of me_to is " << me_to.length() << "\n\n";
	sentence you_to(" ");
	cout << "you_to is " << "\"" << you_to << "\"" << " =  "<<"\"" <<" "<< "\"" << "\n";//sentence is one space
	cout << "The length of you_to is " << you_to.length() << "\n\n";
	cout << "****End of Test#2*******************************************\n";
	cout<<endl;

	/*TEST 3 **********************************************************************************************/
	cout << "****Test#3: copy constructor, length, isEqual, and operator<<***\n\n";
	sentence them = me;
	cout<<"them is "<<"\""<<them<<"\""<<"\n";
	cout << "The length of me is " << me.length()
	     << " = The length of them is " << them.length()<<"\n";
	cout <<"isEqual should equal 1 = "<< them.isEqual(me) << endl<<endl;
	cout << "****End of Test#3*******************************************\n";
	cout<<endl;

	/*TEST 4 **********************************************************************************************/
	cout<<"****TEST#4: overloaded operator= with string, and operator<<*******************\n\n";
	sentence us;
	us = "There are five racoons in the palm tree.";
	cout<<"Testing operator = by assigning the value of "<<
		"\""<<"There are five racoons in the palm tree."<<"\""<<"\n";
	cout<<"The sentence us is "<< "\""<<us<<"\""<<endl<<endl;
	cout<<"****End of Test#4*********************************************\n";
	cout<<endl;

	/*TEST 5 **********************************************************************************************/
	cout<<"****TEST#5: overloaded operator= with string, isEqual, and operator<<*********\n\n";
	sentence her, him;

	her = "I am very happy";
	him = "They are very happy";
	cout << "isEqual should equal 0 = " << her.isEqual(him) << endl;
	
	her = "";
	him = "";
	cout << "isEqual should equal 1 = " << her.isEqual(him) << endl;
	
	her = " ";
	him = " ";
	cout << "isEqual should equal 1 = " << her.isEqual(him) << endl;

	her = "";
	him = " ";
	cout << "isEqual should equal 0 = " << her.isEqual(him) << endl;

	her = "        ";
	him = "        ";
	cout << "isEqual should equal 1 = " << her.isEqual(him) << endl;

	her = "       ";
	him = "        ";
	cout << "isEqual should equal 0 = " << her.isEqual(him) << endl;

	cout << "****End of Test#5*********************************************\n";
	cout << endl;

	/*TEST 6 **********************************************************************************************/
	cout<<"****TEST#6: operator= with a string, operator+ with a sentence, and operator<<*****\n\n";

	cout<<"Adding 2 sentences by adding us to the back of their.  Their is the current object \n";
	sentence their("Everything ");
	us = "will be okay.";
	cout << "us = " <<"\""<< us <<"\""<<" and length = "<<us.length()<< endl;
	cout << "their = " <<"\""<< their <<"\""<<" and length = "<<their.length()<< endl;
	their + us;
	cout<<"their followed by us is "<< "\""<<their<< "\""<<" and length = " << their.length() << endl << endl;

	cout << "us = " << "\"" << us << "\"" << " and length = " << us.length() << endl;
	cout << "their = " << "\"" << their << "\"" << " and length = " << their.length() << endl;
	us + their;
	cout << "us followed by their is " << "\"" << us << "\"" <<" and length = "<< us.length()<< endl;
	cout<<"*************************************************\n";
	cout<<endl<<endl;
	
	us = "123 456";
	their = "123";
	cout << "us = " << "\"" << us << "\"" << " and length = " << us.length() << endl;
	cout << "their = " << "\"" << their << "\"" << " and length = " << their.length() << endl;
	us + their;
	cout << "us followed by their is " << "\"" << us << "\"" << "and length = " << us.length() << endl;

	us = "123 456";
	their = "";
	cout << "us = " << "\"" << us << "\"" << " and length = " << us.length() << endl;
	cout << "their = " << "\"" << their << "\"" << " and length = " << their.length() << endl;
	their + us;
	cout << "their followed by us is " << "\"" << their << "\"" << " and length = " << their.length() << endl<<endl;
	cout << "****End of Test#6*********************************************\n\n";

	/*TEST 7 **********************************************************************************************/
	cout<<"****TEST#7: remove with a string without spaces, and operator<<*****\n\n";
	them = "";
	them.remove("123");
	cout << "\"" << them << "\"" << " length of them = " << them.length() << endl;

	them = "123";
	them.remove("123");
	cout <<"\""<< them<< "\"" << " length of them = "<<them.length()<<endl;

	them = "123 abc 124 abc 123 4567";
	them.remove("123");
	cout << "\""<<them <<"\""<< " length of them = " << them.length() << endl;

	them = "123 abc 124 abc 123 4567";
	them.remove("4567");
	cout <<"\""<< them <<"\"" " length of them = " << them.length() << endl;
	them = "123 abc 124 abc 123 4567";
	them.remove("124");
	cout << "\"" << them << "\"" " length of them = " << them.length() << endl;
	them.remove(" ");
	cout << "\"" << them << "\"" " length of them = " << them.length() << endl;
	them.remove(" ");
	cout << "\"" << them << "\"" " length of them = " << them.length() << endl;
	them.remove(" ");
	cout << "\"" << them << "\"" " length of them = " << them.length() << endl;
	them.remove(" ");
	cout << "\"" << them << "\"" " length of them = " << them.length() << endl;
	them.remove(" ");
	cout << "\"" << them << "\"" " length of them = " << them.length() << endl<<endl;
	cout << "****End of Test#7*********************************************\n";
	cout << endl;

	/*TEST 8 **********************************************************************************************/
	cout << "****TEST#8: operator= with a sentence object and operator<<*****\n\n";
	sentence h("123 456 780");
	them = h;
	cout << "right object = " << h << endl;
	cout << "them = "<<them << endl<<endl;
	cout << "****End of TEST#8****************************************\n\n";
	cout << "****End of Program*********************************************\n";

	/*TEST 8 end **********************************************************************************************/

	/*TEST 9 **********************************************************************************************/
	cout << "****TEST#9: delete all evens*****\n\n";
	sentence number("1 2 3 4 5 6 7 8 9");
	cout << "Initial sentence: " << number << endl;
	number.Delete_All_Even();
	cout << "Odd sentence: " << number << endl;
	cout << "****End of TEST#9****************************************\n\n";
	cout << "****End of Program*********************************************\n";

	return 0;
}

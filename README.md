# DataStructures

### Technology

* [IOstream](https://cplusplus.com/reference/iostream/): Iostream stands for standard input-output stream. This header file contains definitions of objects like cin, cout, cerr, etc. iomanip: iomanip stands for input-output manipulators. The methods declared in these files are used for manipulating streams. This file contains definitions of setw, setprecision, etc.
* [IOmanip](https://cplusplus.com/reference/iomanip/): A library in C++ that is used to manage input and output formatting. It gives the user the power to control output formatting processes, such as alignment, text formatting, and numeric precision in the console for better data visualization.
* [fstream](https://cplusplus.com/reference/fstream/fstream/): This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream which means it can create files, write information to files, and read information from files.
* [string](https://cplusplus.com/reference/string/string/): The standard string class provides support for such objects with an interface similar to that of a standard container of bytes, but adding features specifically designed to operate with strings of single-byte characters.
* [stdlib](https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm): This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
* [cstdio](https://cplusplus.com/reference/cstdio/): Input and Output operations can also be performed in C++ using the C Standard Input and Output Library (cstdio, known as stdio.h in the C language). This library uses what are called streams to operate with physical devices such as keyboards, printers, terminals or with any other type of files supported by the system. Streams are an abstraction to interact with these in an uniform way; All streams have similar properties independently of the individual characteristics of the physical media they are associated with.
* [vector](https://cplusplus.com/reference/vector/vector/): Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.


### [SimpleBSTComparison](SimpleBSTComparison) using [Tree1.txt](SimpleBSTComparison/Data)
- The purpose of this program is to check if two binary search trees are equal in size. This is done by searching the trees and counting the total number of nodes.

### [SimpleBinarySearchTree](SimpleBinarySearchTree) using [RawData](SimpleBinarySearchTree/Data/RawData.txt)
- This is a simple program to experience writing code for binary trees. This is a CLASS implementation of the BST ADT. The program allows for insertion of nodes into the tree, deletion of nodes from the tree, sorting of the tree and printing the tree in full or by certain ranges. The program should be display the advantages and disadvantages of using such an implementation.

Output: [Modified and Sorted Tree](SimpleBinarySearchTree/Data/CountryInfo.txt)

### [SimpleDateClass](SimpleDateClass)
- The purpose of this program is to determine if a user inputs a valid date. The program will test the month, day, and year and echo back any portion of the date that is invalid. The program is able to determine if the year is a leap year. It also will determine if the particular month has 28,29,30 or 31 days depending on the month and if it is a leap year (for Febuary).

### [SimpleInfix](SimpleInfix)
- The purpose of this program is to convert a postfix expression to the corresponding fully-parenthesized infix expression.
  
Examples of postfix to infix evaluation (by hand)

* postfix " 2 3 4 + 5 6 - - * "

* 2 (3 4 +) 5 6 - - *
* 2 "7" (5 6 -) - *
* 2 (7 "1" -) *
* (2 "8" *)

* result	"  16  "

### [SimpleQueue](SimpleQueue)
- The purpose of this program is to (1) manipulate pointers, (2) allocate memory dynamically, (3) implement a default constructor, copy constructor and destructor, (4) use only one pointer to add to the back and to delete from the front of the queue.

### [SimpleRecursion](SimpleRecursion)
- Write a program that contains two recursive and one non-recursive functions

1. A recursive boolean function called palindrome that accepts one string argument(for the user)
and returns true if the string reads the same forward as it does backwards.For example madam,
463364, and "ABLE WAS I ERE I SAW ELBA" are all palindromes.

2. A recursive function called printReverse that accepts one string argument(for the user)
and returns the reverse of that string.

3. A non-recursive function called printIterReverse that accepts one string argument(from the user)
and returns the reverse of that string.

### [SimpleSentenceClass](SimpleSentenceClass)
- The purpose of this program is to (1) manipulate pointers in a sentence class (2) utilize overloaded functions, (3) implement a default constructor, copy constructor and destructor, (4) delete all nodes containing even values.

### [SimpleStateClass](SimpleStateClass) using [census2020_data.txt](SimpleStateClass/Data/census2020_data.txt)
- The purpose of this program is to parse an input file and allocate each coresponding state and population to its own node. The program allows for insertion of nodes into the tree, deletion of nodes from the tree, sorting of the tree and printing the tree in full or by certain ranges. The program is then able to neatly output the sorted and altered data into a new file.

Output: [state_data_update.txt](SimpleStateClass/Data/state_data_update.txt)

### [SimpleStringClass](SimpleStringClass)
- The purpose of this program is to learn how to create an empty default string constructor, populated explicit constructor, string palindrome checker, and string replace function.

### [SimpleVectorList](SimpleVectorList)
- use the vector class to manage a dynamic array

(1) Manage a vector(allocate and de-allocate memory, insert inorder, remove, etc).
(2) Implement a default constructor and a copy constructor.
(3) Implement an insert function to add a string, in order, into a vector
(4) Implement a remove function to delete a string from a vector

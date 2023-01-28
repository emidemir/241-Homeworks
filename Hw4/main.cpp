#include <iostream>
#include <initializer_list>
#include <fstream>
#include "dayOfYearSet.hpp"


using namespace std;
using namespace _DayofYear;


int main(){

	fstream FILE;
	FILE.open("Driver_Results.txt", ios::out);

	dayOfYearSet set1 =
	{
		dayOfYearSet::DayofYear(1,6),
		dayOfYearSet::DayofYear(2,6),
		dayOfYearSet::DayofYear(3,6)
	};

	dayOfYearSet set2 =
	{
		dayOfYearSet::DayofYear(1,6),
		dayOfYearSet::DayofYear(2,6),
		dayOfYearSet::DayofYear(3,6),
		dayOfYearSet::DayofYear(4,6),
		dayOfYearSet::DayofYear(4,7),
		dayOfYearSet::DayofYear(4,8),
		dayOfYearSet::DayofYear(4,9),
	};

	/*Getting input from user, if Q, program will be terminated*/
	int Day;
	Months Month;
	if (inputChecker(Day,Month) == false){
		exit(1);
	}

	/*Creating the first object as user wanted*/
	dayOfYearSet::DayofYear obj1(Day,Month);

	/*Creating the second object*/
	dayOfYearSet::DayofYear obj2(12,12);


	cout << "1)_____Printing a set with cout (ostream object) is working, no leak is here___" << endl;
	cout << set1;

	FILE << "1)_____Printing a set with cout (ostream object) is working, no leak is here___" << endl;
	FILE << set1;
/*__________________________________________________________________________________________________________________________________*/

	cout << "2)_____Adding a DOY object into a set, no leak is here___" << endl;
	cout << "Set1's first state" << endl;
	cout << set1;
	FILE << "2)_____Adding a DOY object into a set, no leak is here___" << endl;
	FILE << "Set1's first state" << endl;
	FILE << set1;
	set1 = set1 + obj1;
	cout << "Set1's state after adding an object__" << endl;
	cout << set1;

	FILE << "Set1's state after adding an object" << endl;
	FILE << set1;

/*__________________________________________________________________________________________________________________________________*/

	cout << "3)___Checking if operator== and operator != works, no leaks here___" << endl;
	FILE << "3)___Checking if operator== and operator != works, no leaks here___" << endl;

	cout << "Using == opeartor" << endl;
	FILE << "Using == opeartor" << endl;
	cout << "Comparing set1 with set1 (same set)" << endl;
	FILE << "Comparing set1 with set1 (same set)" << endl;
	cout << (set1 == set1)<< endl;
	FILE << (set1 == set1)<< endl;
	cout << "Comparing set1 with set2 (different set)" << endl;
	FILE << "Comparing set1 with set2 (different set)" << endl;
	cout << (set1 == set2)<< endl;
	FILE << (set1 == set2)<< endl;

	cout << "Using != opeartor" << endl;
	FILE << "Using != opeartor" << endl;
	cout << "Comparing set1 with set1 (same set)" << endl;
	FILE << "Comparing set1 with set1 (same set)" << endl;
	cout << (set1 != set1)<< endl;
	FILE << (set1 != set1)<< endl;
	cout << "Comparing set1 with set2 (different set)" << endl;
	FILE << "Comparing set1 with set2 (different set)" << endl;
	cout << (set1 != set2)<< endl;
	FILE << (set1 != set2)<< endl;
/*__________________________________________________________________________________________________________________________________*/

	cout << "4)___Remove member function removes the element you specify from set, no leaks here___" << endl;
	FILE << "4)___Remove member function removes the element you specify from set, no leaks here___" << endl;

	cout << "Set1's first state" << endl << set1;
	FILE << "Set1's first state" << endl << set1;
	set1.remove(1,Months::June);
	cout << "Set1's second state after removing an object" << endl << set1;
	FILE << "Set1's second state after removing an object" << endl << set1;

	cout << "If user try to remove an object that is not in the set, function is gonna stop since it returns void" << endl << set1;
	FILE << "If user try to remove an object that is not in the set, function is gonna stop since it returns void" << endl << set1;

/*__________________________________________________________________________________________________________________________________*/

	cout << "5)___Size function returns the size of set ,no leaks here___" << endl;
	FILE << "5)___Size function returns the size of set ,no leaks here___" << endl;

	cout << "Size of set1 is " << set1.size() << "and size of set2 is " << set2.size() << endl;
	FILE << "Size of set1 is " << set1.size() << "and size of set2 is " << set2.size() << endl;
/*__________________________________________________________________________________________________________________________________*/

	cout << "6)___Operator+ adds an element to set,no leaks here___" << endl;
	FILE << "6)___Operator+ adds an element to set,no leaks here___" << endl;

	cout << "First state of set1 is " << endl << set1 << endl;
	FILE << "First state of set1 is " << endl << set1 << endl;

	set1 = set1 + obj2;

	cout << "Second state of set1 after adding obj2 " << endl << set1 << endl;
	FILE << "Second state of set1 after adding obj2 " << endl << set1 << endl;
/*__________________________________________________________________________________________________________________________________*/

	cout << "7)___Operator+ returns a union set,no leaks here___" << endl;
	FILE << "7)___Operator+ returns a union set,no leaks here___" << endl;

	cout << "First state of set1 and set2 are" << endl << "set1" << endl << set1 << "set2" << endl << set2;
	FILE << "First state of set1 and set2 are" << endl << "set1" << endl << set1 << "set2" << endl << set2;

	dayOfYearSet set3;
	set3 = set1 + set2;

	cout << "After merging two set with +operator, set3 is" << endl << set3; 
	FILE << "After merging two set with +operator, set3 is" << endl << set3;

	cout << "Operator also does not allow any duplication on set. We can say that because first 3 element of set2 is same with set1 but there are only 4 elements on set3" << endl;
	FILE << "Operator also does not allow any duplication on set. We can say that because first 3 element of set2 is same with set1 but there are only 4 elements on set3" << endl;
/*__________________________________________________________________________________________________________________________________*/

	cout << "8)___Operator- returns the difference set,no leaks here___" << endl;
	FILE << "8)___Operator- returns the difference set,no leaks here___" << endl;
	
	
	cout << "First state of set1 and set2 are" << endl << "set1" << endl << set1 << "set2" << endl << set2;
	FILE << "First state of set1 and set2 are" << endl << "set1" << endl << set1 << "set2" << endl << set2;

	dayOfYearSet set4;
	set4 = set2 - set1;
	cout << set4;
	cout << "After getting difference of two set with -operator, set4 is" << endl << "-----" << endl << set4 << "-----" <<endl; 
	FILE << "After getting difference of two set with -operator, set4 is" << endl << "-----" << endl << set4 << "-----" <<endl;

	cout << "If the left set is subset of right set, the difference will make nothing and we will see only empty set. For example set1 is subset of set2 and set1-set2 will result empty set" << endl;
	FILE << "If the left set is subset of right set, the difference will make nothing and we will see only empty set. For example set1 is subset of set2 and set1-set2 will result empty set" << endl;

	set4 = set1 - set2;
	cout << set4;

	cout << "The set4 is" << endl << "-----" << endl << set4 << "-----" << endl;
	FILE << "The set4 is" << endl << "-----" << endl << set4 << "-----" << endl;
/*__________________________________________________________________________________________________________________________________*/
	
	cout << "9)___Operator- removes an element from set ,no leaks here___" << endl;
	FILE << "9)___Operator- removes an element from set ,no leaks here___" << endl;

	cout << "First state of set2 is " << endl << "-----" << endl << set2 << "-----" << endl; 
	FILE << "First state of set2 is " << endl << "-----" << endl << set2 << "-----" << endl; 
	
	set2 = set2 - dayOfYearSet::DayofYear(4,9);

	FILE << "After removing object 4th September(9) from set2" << endl << "-----" << endl << set2 << "-----" << endl; 
	cout << "After removing object 4th September(9) from set2" << endl << "-----" << endl << set2 << "-----" << endl; 
/*__________________________________________________________________________________________________________________________________*/

	cout << "10)___Operator^ gets the intersection set ,no leaks here___" << endl;
	FILE << "10)___Operator^ gets the intersection set ,no leaks here___" << endl;

	cout << "First state of set1 and set2 are" << endl << "set1" << endl << set1 << "set2" << endl << set2;
	FILE << "First state of set1 and set2 are" << endl << "set1" << endl << set1 << "set2" << endl << set2;
	
	dayOfYearSet set5;
	set5 = set1 ^ set2;

	cout << "set5 after getting the intersection of both set is" << endl << set5;
	FILE << "set5 after getting the intersection of both set is" << endl << set5;
/*__________________________________________________________________________________________________________________________________*/

	cout << "11)___Operator! gets the complement set ,no leaks here___" << endl;
	FILE << "11)___Operator! gets the complement set ,no leaks here___" << endl;

	cout << "set2's current state is " << endl << set2; 
	FILE << "set2's current state is " << endl << set2;

	dayOfYearSet set6 = !set2;

	cout << "Complement set is " << endl << set6;
	FILE << "Complement set is " << endl << set6;
/*__________________________________________________________________________________________________________________________________*/


	cout << "12)___Operator[] returns the value at given index ,no leaks here___" << endl;
	FILE << "12)___Operator[] returns the value at given index ,no leaks here___" << endl;

	cout << "set2's current state is " << endl << set2; 
	FILE << "set2's current state is " << endl << set2;

	cout << "Value at index 0 and 1 is " << endl << set2[0] << set2[1];
	FILE << "Value at index 0 and 1 is " << endl << set2[0] << set2[1];

	FILE.close();
	return (0);
}
#include <iostream>
#include <initializer_list>
#include "dayOfYearSet.hpp"

using namespace std;
using namespace _DayofYear;

bool _DayofYear::convertInt(string ui_input, int &amount){
	unsigned long long int holder = 0;
	if (ui_input[0] == '0')
		return (false);

	for (auto i: ui_input){			// i is iterator which is an object of the string ui_input (20min to realise ">_<" -angry face- )	
		if (i < '0' || i > '9')
			return (false);
		else if (holder > 2147483647)
			return (false);
		holder = (holder*10) + (i-'0');
	}

	amount = holder;
	return (true);
};

/*List parameter constructure*/
dayOfYearSet::dayOfYearSet(const initializer_list<DayofYear> &objL){
	_size = objL.size();
	_used = 0;
	setArr = new DayofYear[_size];

	int index = -1;
	for (auto iter = objL.begin(); iter != objL.end(); iter++){
		this->setArr[++index]  = *iter;		/*List elements are stored inside pointer of dayOfYearSet*/
		_used++;
	}
};

/*Printing dayOfYearSet set*/
ostream& _DayofYear::operator<<(ostream& COUT, const dayOfYearSet::DayofYear& obj){
	COUT << "Day: " << obj.Day << "Month: " << (int)obj.Month << endl;
	return (COUT);
}

/*Printing single DayOfYear object*/
ostream& _DayofYear::operator<<(ostream& COUT, const dayOfYearSet& obj){
	
	for (int i = 0; i < obj._used; i++){
		COUT << obj.setArr[i] << endl;
	}
	return (COUT);
}

/*Adding DOY object to set*/
dayOfYearSet& _DayofYear::operator+(dayOfYearSet&doy_set, const dayOfYearSet::DayofYear& day_obj){

	/*If object already exist on the set*/
	for (int i = 0; i < doy_set._used; i++){
		if (doy_set.setArr[i].getDay() == day_obj.getDay() && doy_set.setArr[i].getMonth() == day_obj.getMonth())
		{
			return (doy_set);
		}
	}

	/*If there is no place for new object*/
	if (doy_set._size == doy_set._used){
		
		doy_set._size *= 2;
		
		dayOfYearSet::DayofYear *ptr = new dayOfYearSet::DayofYear [doy_set._size];

		for (int i = 0; i < doy_set._used; i++){
			ptr[i] = doy_set.setArr[i];
		}

		ptr[doy_set._used++] = day_obj;

		delete [] doy_set.setArr;

		doy_set.setArr = ptr;
		
		return (doy_set);
	}

	/*If there is space for new element*/
	doy_set.setArr[doy_set._used] = day_obj;
	doy_set._used += 1;
	return (doy_set);

}

/*The equal-to operator (==) returns true if both operands have the same value*/
bool _DayofYear::operator==(const dayOfYearSet& set1 ,const dayOfYearSet& set2){
	
	if (set1._used != set2._used)
		return (false);
	
	for (int i = 0; i < set1._used; i++){
		
		if (set1.setArr[i].getDay() != set2.setArr[i].getDay())
			return (false);

		if (set1.setArr[i].getMonth() != set2.setArr[i].getMonth())
			return (false);
	}
	return (true);
}

/*The not-equal-to operator (!=) returns true if the operands don't have the same value*/
bool _DayofYear::operator!=(const dayOfYearSet& set1 ,const dayOfYearSet& set2){
	if (set1._used != set2._used)
		return (true);
	
	for (int i = 0; i < set1._used; i++){
		
		if (set1.setArr[i].getDay() != set2.setArr[i].getDay())
			return (true);

		if (set1.setArr[i].getMonth() != set2.setArr[i].getMonth())
			return (true);
	}
	return (false);
}

/*Removes an element from list*/
void _DayofYear::dayOfYearSet::remove(int day, Months Month){

	DayofYear *newArr = new DayofYear[_size];
	int j = -1;
	for (int i = 0; i <= _used; i++)
	{	
		/*If incoming object is different copy it into new array*/
		if (setArr[i].getDay() != day || setArr[i].getMonth() != Month)
		{
			newArr[++j] = setArr[i];
		}
		/*If object is same, do not copy it and decrement _used for 1*/
		else
		{
			_used--;
		}
	}

	delete [] setArr;
	setArr = newArr;

	/*If used is half of size, than we can free half of the array memory of set*/
	if (_used == _size / 2){
		
		DayofYear* ptr = new DayofYear[_used];
		_size = _size / 2;

		for (int i = 0;  i < _used; i++){
			ptr[i] = setArr[i];	
		}

		delete [] setArr;
		setArr = ptr;
	}
}

dayOfYearSet& _DayofYear::operator+(dayOfYearSet& set1, const dayOfYearSet& set2){
	int size1 = set1.size();
	int size2 = set2.size();
	int index = -1;		/*Index of newArr which holds the combination of two sett*/

	dayOfYearSet::DayofYear* newArr = new dayOfYearSet::DayofYear[size1+size2];

	/*Copy first set into new set*/
	for (int i = 0; i < size1; ++i){
		newArr[++index] = set1.setArr[i];
	}

	int _usedList2 = 0;	/*Since We are not gonna copy the same elements, we must count how many did we copy*/

	for (int i = 0; i < size2; ++i){
		
		bool canCopy = true;

		for (int j = 0; j < size1; ++j){
			/*If set1 and set2 has same element*/
			if ((set2.setArr[i].getDay() == set1.setArr[j].getDay()) && (set2.setArr[i].getMonth() == set1.setArr[j].getMonth()))
			{
				canCopy = false;
				break;
			}
		}

		if (canCopy == true){
			newArr[++index] = set2.setArr[i];
			_usedList2++;
		}
	}


	delete [] set1.setArr;

	set1.setArr = newArr;
	set1._size = size1 + size2;
	set1._used = size1 + _usedList2;

	return (set1);
}

dayOfYearSet& _DayofYear::operator-(const dayOfYearSet& set1, const dayOfYearSet& set2){

	int size1 = set1.size();
	int size2 = set2.size();

	/*I could not find a way for this part. I am using a pointer to store the difference of two set without changing the originla set*/
	/*BUT I can not free afterwards on main. I can not expect my client to free it everytime it used an object specificly with - opeartor*/
	/*in conclusion, I could not find a solution without condoning some memory leak :/ */
	dayOfYearSet *temp = new dayOfYearSet[1];

	for (int i = 0; i < size1; ++i){
		
		bool canCopy = true;
		
		for (int j = 0; j < size2; ++j){
			/*If set1 and set2 has same element*/
			if ((set1.setArr[i].getDay() == set2.setArr[j].getDay()) && (set1.setArr[i].getMonth() == set2.setArr[j].getMonth()))
			{
				canCopy = false;
				break;
			}
		}

		if (canCopy == true){
			(*temp) = (*temp) + set1.setArr[i];
		}
	}
	return (*temp);
}

dayOfYearSet& _DayofYear::operator-(dayOfYearSet& set ,const dayOfYearSet::DayofYear& obj){

	dayOfYearSet::DayofYear* newArr = new dayOfYearSet::DayofYear[set.size()];
	int newUsed = 0;


	for (int i = 0; i < set._used; ++i){
		if (set.setArr[i].getDay() != obj.getDay() || set.setArr[i].getMonth() != obj.getMonth())
			newArr[newUsed++] = set.setArr[i];
	}


	delete [] set.setArr;

	set.setArr = newArr;
	set._used = newUsed;

	return (set);
}

dayOfYearSet& _DayofYear::operator^(const dayOfYearSet& set1, const dayOfYearSet& set2){

	/*Max intersection amount can not be more than smaller set, getting the smaller size for new set*/
	int newArrSize = (set1.size() > set2.size()) ?  set2.size() : set1.size();

	dayOfYearSet* temp = new dayOfYearSet[1];

	(*temp).setArr = new dayOfYearSet::DayofYear[newArrSize];

	(*temp)._size = newArrSize;

	int newArrUsed = 0;

	for (int i = 0; i < set1._size; ++i){
		for (int j = 0; j < set2._size; ++j){
			if (set1.setArr[i].getDay() == set2.setArr[j].getDay() && set1.setArr[i].getMonth() == set2.setArr[j].getMonth()){
				(*temp).setArr[newArrUsed++] = set1.setArr[i];
				break;
			}
		}
	}

	(*temp)._used = newArrUsed;

	return (*temp);
}

void _DayofYear::dayOfYearSet::operator=(const dayOfYearSet& set){

	/*Assigning same array into itself is pointless, just return*/
	if (this == &set){
		return;
	}

	/*If the set user is trying to assign is empty, delete old setArr and assign new one to old one*/
	if (set._used == 0){
		delete [] this->setArr;
		this->setArr = set.setArr;
		this->_size = 0;
		this->_used = 0;
		return;
	}

	/*If assignment is normal this steps are essential, no point to explain*/
	_size = set._size;
	_used = set._used;
	
	DayofYear* newArr = new DayofYear[_used];
	
	for (int i = 0; i < set._used; i++)
		newArr[i] = set.setArr[i];

	delete [] this->setArr;
	this->setArr = newArr;
}

dayOfYearSet& _DayofYear::dayOfYearSet::operator!(){

	int* maxDaysOfMonths = new int[12];

	maxDaysOfMonths[0] = 31;
	maxDaysOfMonths[1] = 28;
	maxDaysOfMonths[2] = 31;
	maxDaysOfMonths[3] = 30;
	maxDaysOfMonths[4] = 31;
	maxDaysOfMonths[5] = 30;
	maxDaysOfMonths[6] = 31;
	maxDaysOfMonths[7] = 31;
	maxDaysOfMonths[8] = 30;
	maxDaysOfMonths[9] = 31;
	maxDaysOfMonths[10] = 30;
	maxDaysOfMonths[11] = 31;

	dayOfYearSet* temp = new dayOfYearSet[1];
	// dayOfYearSet temp;

	for (int i = 1; i <= 12; ++i){
		for (int j = 1; j <= maxDaysOfMonths[i]; ++j){
			(*temp) = (*temp) + dayOfYearSet::DayofYear(j,i);
		}
	}

	for (int i = 0; i < this->_used; ++i){
		(*temp).remove(this->setArr[i].getDay(), this->setArr[i].getMonth());
	}

	delete [] maxDaysOfMonths;
	
	return (*temp);
}

dayOfYearSet::DayofYear& _DayofYear::dayOfYearSet::operator[](int index){

	if (index >= this->_size)
	{
		cout << "Index given for set is out of scope, try a number less than size of set !!" << endl;
		exit(1);
	}

	if (index < 0)
	{
		cout << "Dude, Are you realy trying a number less than zero as index for a set AHAHAHAHAHAHAHAH. Promes I won't tell anyone. Go change your number" << endl;
		exit(1);
	}

	return (this->setArr[index]);
}

bool _DayofYear::inputChecker (int& Day, Months& enteredMonth)
{
	int maxDays;
	string userInput;
	cout << "Month (Q for quiting) :";

	bool keepSearching = true;
	/*Getting the month*/
	while (keepSearching){
		
		getline(cin,userInput);
		
		keepSearching = false;	/*If none of if statements are satisfied, compiler will run else statement which will make this
		bool value true and loop will continue untill a condition is satisfied*/

		if (userInput == "January" || userInput == "january" || userInput == "1"){
			enteredMonth = Months::January;
			maxDays = 31;
		}else if (userInput == "February" || userInput == "february" || userInput == "2"){
			enteredMonth = Months::February;
			maxDays = 29;
		}else if (userInput == "March" || userInput == "march" || userInput == "3"){
			enteredMonth = Months::March;
			maxDays = 31;
		}else if (userInput == "April" || userInput == "april" || userInput == "4"){
			enteredMonth = Months::April;
			maxDays = 30;
		}else if (userInput == "May" || userInput == "may" || userInput == "5"){
			enteredMonth = Months::May;
			maxDays = 31;
		}else if (userInput == "June" || userInput == "june" || userInput == "6"){
			enteredMonth = Months::June;
			maxDays = 30;
		}else if (userInput == "July" || userInput == "July" || userInput == "7"){
			enteredMonth = Months::July;
			maxDays = 31;
		}else if (userInput == "August" || userInput == "august" || userInput == "8"){
			enteredMonth = Months::August;
			maxDays = 31;
		}else if (userInput == "September" || userInput == "september" || userInput == "9"){
			enteredMonth = Months::September;
			maxDays = 31;
		}else if (userInput == "October" || userInput == "october" || userInput == "10"){
			enteredMonth = Months::October;
			maxDays = 30;
		}else if (userInput == "November" || userInput == "november" || userInput == "11"){
			enteredMonth = Months::November;
			maxDays = 30;
		}else if (userInput == "December" || userInput == "december" || userInput == "12"){
			enteredMonth = Months::December;
			maxDays = 31;
		}else if (userInput == "Q"){
			cout << "Terminating. Have a nice day" << endl;
			return (false);
		}
		else{
			cout << "Try again please" << endl;
			keepSearching = true;
		}

	}

	cout << "Day : ";

	keepSearching = true;
	userInput = "";
	/*Getting the day*/
	while (keepSearching){

		getline(cin,userInput);

		if (convertInt(userInput,Day) == false || (Day < 0 || Day > maxDays))
		{
			cout << "Try Again" << endl;
			keepSearching = true;
		}
		else
			keepSearching = false;
	}

	// cout << Day << "'th  of month " << (int)enteredMonth << endl;

	return (true);
};
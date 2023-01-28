#include "../Headers/PFArray.hpp"
#include "../Headers/PFArrayIterator.hpp"
#include "../Implementations/PFArray.cpp"
#include <vector>
#include <string>
#include <algorithm>

using namespace Emirhan;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class foo1{
	public:
	int a;
};

struct foo2{
	int b;
};

PFArray<int> foo(){

	PFArray<int> temp(177);

	temp.PushBack(11);
	temp.PushBack(21);
	temp.PushBack(31);
	temp.PushBack(41);
	temp.PushBack(51);
	temp.PushBack(61);
	temp.PushBack(71);
	temp.PushBack(81);
	temp.PushBack(91);
	temp.PushBack(101);
	return (temp);
}

int main()
{

	/*Object is created*/
	PFArray<int> test1;

	for (int i = 0; i < 10; ++i)
	{
		/*Pushback function to insert element works*/
		test1.PushBack(i+2);
	}

	/*<< operation works*/
	cout << "test1 PFArray at the beginning : " << endl; 
	cout << test1 << endl;

	/*At function works*/
	cout << "Element at position 2 : test1.At(2) : " << test1.At(2) << endl;
	/*Size function works*/
	cout << "test1 PFArray size at the beginning : " << test1.size() << endl;

	/*PopBack function to delete the last element from array works*/
	test1.PopBack();
	test1.PopBack();

	cout << "test1 PFArray after 2 PopBack function : " << endl; 
	cout << test1 << endl;
	cout << "test1 PFArray size after 2 PopBack function : " << test1.size() << endl;
	

	// /*Copy constructer works*/
	PFArray<int> test2(test1);

	cout << "test1 : " << endl;
	cout << test1 << endl;
	cout << "test2 (test1 is used as copy constrtucter) : " << endl;
	cout << test2 << endl;

	PFArray<int> test3;

	/*Move assignment works perfectly because even thoug I have not defined test3, it has some values 
	which is coming from foo() function*/
	cout << "Test3 before move assignment operator: " << endl;
	test3 = foo();
	cout << "Test3 (Move assignment is used Temp object of return value of foo function is assigned) : " << endl;
	cout << test3 << endl;

	test3 = test1;

	// /*Copy assignment works because test3's values has changed*/
	cout << "Normal copy assignment is used (test1 is assigned to test3 -deep copy-) test3 : " << endl;
	cout << test3 << endl;
	
	cout << "Is test3 empty? : " << test3.empty() << endl;
	test3.PopBack();
	test3.PopBack();
	test3.PopBack();
	test3.PopBack();
	test3.PopBack();
	test3.PopBack();
	test3.PopBack();
	test3.PopBack();
	/*Empty function works*/
	cout << "I did 8 PopBack, is it empty now ? : " << test3.empty() << endl;

	/*Iterator is created*/
	PFArrayIterator<int> iter;

	/*Iterator is assigned to first element of test2 PFArray*/
	iter = test2.begin();

	cout << "Using iterator to print test2 " << endl;
	for (iter = test2.begin(); iter != test2.end(); ++iter)
	{
		cout << (*iter) << endl;
	}


	PFArray<int> test4;

	test4.PushBack(5);
	test4.PushBack(7);
	test4.PushBack(4);
	test4.PushBack(10);
	test4.PushBack(3);
	test4.PushBack(1);
	test4.PushBack(6);
	test4.PushBack(2);
	test4.PushBack(9);
	test4.PushBack(8);

	cout << "Test4 before erasing first element : " << test4 << endl;

	PFArrayIterator<int> deleteIter;
	deleteIter = test4.begin();

	test4.erase(deleteIter);

	cout << "After erasing first element : " << test4 << endl;

	/*PFArray class is compatable with std::sort*/
	cout << "Test4 before sort function : "<< endl;
	cout << test4 << endl;

	PFArrayIterator<int> itrBegin;
	PFArrayIterator<int> itrEnd;

	itrBegin = test4.begin();
	itrEnd = test4.end();

	std::sort(itrBegin, itrEnd);

	cout << "Test4 after sort function : " << endl;
	cout << test4 << endl;

	/*PFArray class is compatable with std::find*/

	cout << "If 5 exist in test4, std::find will return an iterator to the element of 5"
	<< endl << "otherwise it will return to the last element of the test4" << endl;

	/*PFArray is competable with std::find*/
	PFArrayIterator<int> resultIter;

	resultIter = std::find(itrBegin, itrEnd, 5);

	cout << "Result iterator has value of : " << *resultIter << endl;

	/*PFArray is competable with for_each*/
	cout << "---Foreach---";
	std::for_each(itrBegin, itrEnd, [](int& obj){cout << (obj*4)-2 << endl;});
	cout << "-------------"<<endl;
	// /*___________________TRYING PFArray WITH CUSTOM CLASS OBJECTS________________*/


	PFArray<foo1> customClassArray;

	/*cco stands for custom class object*/
	foo1 cco1;
	foo1 cco2;
	foo1 cco3;
	foo1 cco4;
	foo1 cco5;

	customClassArray.PushBack(cco1);
	customClassArray.PushBack(cco2);
	customClassArray.PushBack(cco3);
	customClassArray.PushBack(cco4);
	customClassArray.PushBack(cco5);

	/*cci stands for custom class iterator*/
	PFArrayIterator<foo1> cci;

	for (cci = customClassArray.begin(); cci != customClassArray.end(); ++cci)
	{
		/*Arrow operator (->) for iterator class works*/
		cci->a = 3;
	}

	/*PFArray works with ranged base loop*/
	for (auto i : customClassArray)
		cout << i.a << endl;
	
	/*Creating an iterator to check if compare operatot (==) works for iterator class*/
	PFArrayIterator<foo1> cci1;

	if (cci == cci1)
		cout << "It does not work because this two iterator can not be equal"<<endl;
	else if (cci != cci1)
		cout << "It works" << endl;

	cci1 = cci;

	if (cci1 == cci)
		cout << "If you can see this print, it means '=' operator for iterator class works" << endl;

	cout << "I can hold custom created array with PFArray." << endl;
	for (cci = customClassArray.begin(); cci != customClassArray.end(); ++cci)
		cout << cci->a << " ";
	cout << endl;

	return (0);
}
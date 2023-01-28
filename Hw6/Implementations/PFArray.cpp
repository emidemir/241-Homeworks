#include "../Headers/PFArrayIterator.hpp"
#include "../Headers/PFArray.hpp"

using std::cout;
using std::endl;

namespace Emirhan{

template<typename T>
void PFArray<T>::reAlloc(sizeType newCapacity){
	
	capacity = newCapacity;
	
	/*Create a new array for copy progress*/
	std::shared_ptr<T> tempArray(new T[capacity]);
	
	/*Create iterators for bot old and new array (because there is no other way to traverse them (!) )*/
	PFArrayIterator<T> itrTemp;	/*This iterator holds the beginning of new created array*/
	PFArrayIterator<T> itrArray; /*This iterator holds the beginning of old array*/

	itrTemp = tempArray.get();
	itrArray = this->begin();

	/*Copying old array into new array*/
	for (sizeType i = 0; i < used; ++i)
	{
		*itrTemp = *itrArray;
		++itrTemp;
		++itrArray;
	}

	/*New array is now our Array*/
	Array = tempArray;
}

template <typename T>/*No parameter constructer*/
PFArray<T>::PFArray(){

	used = 0;
	reAlloc(2);
}

template<typename T>
PFArray<T>::PFArray(int size){

	used = 0;
	reAlloc(size);
}

template<typename T>/*Copy Constructer*/
PFArray<T>::PFArray(const PFArray<T>& obj){

	/*Create new smart pointer as array*/
	std::shared_ptr<T> tempArray(new T[obj.capacity]);
	
	/*Copy obj's values to this object*/
	this->used = obj.used;
	this->capacity = obj.capacity;

	PFArrayIterator<T> itrObj;	/*To traverse obj's objects*/
	PFArrayIterator<T> itrTemp;	/*To travers tempArray*/

	itrObj = obj.begin();
	itrTemp = tempArray.get();

	/*Copy old array into new array*/
	for (sizeType i = 0; i < used; ++i)
	{
		*itrTemp = *itrObj;
		++itrTemp;
		++itrObj;
	}
	
	/*Change the arrays, do not worry deleting since it's smartpointer*/
	Array = tempArray;
}

template<typename T>/*Move copy constructer*/
PFArray<T>::PFArray(PFArray<T>&& obj){
	
	Array = std::move(obj.Array);	/*Stealing the resources of temp object*/
	used = obj.used;
	capacity = obj.capacity;

	obj.used = 0;
	obj.capacity = 0;
}

template <typename T>/*Copy Assignment*/
void PFArray<T>::operator=(const PFArray<T>& obj){
	
	/*If objects are same, do not copy*/
	if (this == &obj)
		return ;

	this->capacity = obj.capacity;
	this->used = obj.used;

	/*Create a temp array*/
	std::shared_ptr<T> tempArray(new T[capacity]);

	PFArrayIterator<T> itrObj;	/*To traverse obj's objects*/
	PFArrayIterator<T> itrTemp;	/*To travers tempArray*/

	itrObj = obj.begin();
	itrTemp = tempArray.get();

	/*Copy old array into new array*/
	for (sizeType i = 0; i < used; ++i)
	{
		*itrTemp = *itrObj;
		++itrTemp;
		++itrObj;
	}

	this->Array = tempArray;
}

template <typename T>/*Move assignment operator*/
void PFArray<T>::operator=(PFArray<T>&& obj){
	
	/*Stealing the resources of temp object*/
	this->Array = std::move(obj.Array);

	this->capacity = obj.capacity;
	this->used = obj.used;

	obj.used = 0;
	obj.capacity = 0;
}

template <typename T>
void PFArray<T>::PushBack(const T& value){
	
	/*If array is full, increment the capacity*/
	if (used == capacity)
	{
		reAlloc(capacity*2);
	}
	/*If array is empty enough and wasting memory, decrease the capacity*/
	else if (used <= capacity / 2 && used != 1)
	{
		reAlloc(capacity/2);
	}

	/*Make a new dynamic object of T object which has a value of 'value' parameter*/
	PFArrayIterator<T> itr;
	itr = this->end();
	*itr = value;
	++used;
}

template<typename T>
void PFArray<T>::PopBack(){
	
	if (used > 0)
	{
		--used;
	}

	/*If array is full, increment the capacity*/
	if (used == capacity)
	{
		reAlloc(capacity*2);
	}
	/*If array is empty enough and wasting memory, decrease the capacity*/
	else if (used <= capacity / 2 && used != 1)
	{
		reAlloc(capacity/2);
	}
}

template<typename T>
const T PFArray<T>::At(sizeType index)const{

	try
	{
		if(index < 0 || index >= used) throw index;
	}
	catch(sizeType index)
	{
		std::cerr << "Invalid index for at function\n";
		exit(1);
	}
	

	PFArrayIterator<T> temp;

	temp = this->begin();

	for (sizeType i = 0; i < index; ++i)
		++temp;

	return (*temp);
}

template<typename T>
bool PFArray<T>::erase(PFArrayIterator<T>& object){

	std::shared_ptr<T> tempArray(new T[used]);

	PFArrayIterator<T> itrTemp;	/*This iterator holds the beginning of new created array*/
	PFArrayIterator<T> itrArray; /*This iterator holds the beginning of old array*/

	itrTemp = tempArray.get();
	itrArray = this->begin();

	try
	{
		if (object > this->end()) throw 13;
	}
	catch(int a)
	{
		std::cout << "This iterator is pointing out of array !!!!!!. Dude, how did you get that iterator anyway :D" << '\n';
		exit(1);
	}
	

	/*Copying old array into new array*/
	for (sizeType i = 0; i < used; ++i)
	{
		if (*itrArray == *object)
		{
			++itrArray;
		}
		*itrTemp = *itrArray;
		++itrTemp;
		++itrArray;
	}
	used = used-1;

	/*New array is now our Array*/
	Array = tempArray;

	return (true);
}

template<typename T>
std::ostream& operator<<(std::ostream& COUT, const PFArray<T>& object){

	PFArrayIterator<T> itr;

	itr = object.begin();

	for (itr = object.begin(); itr != object.end(); ++itr)
		COUT << *itr << " ";

	return COUT;
}

}
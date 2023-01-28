#pragma once

#include "PFArrayIterator.hpp"

using std::shared_ptr;
using sizeType = unsigned long long int;

namespace Emirhan
{

template <class T>
class PFArray
{
private:
	std::shared_ptr<T> Array;	/*This is a smart pointer which holds a smart pointer array of type T*/
	sizeType capacity;
	sizeType used;
	void reAlloc(sizeType newCapacity);

public:

	/*____BIG 5____*/
	PFArray();									/*|	DEFAULT CONSTRUCTER 	|*/
	PFArray(int size);							/*| 1 PARAM CONST			|*/
	PFArray(const PFArray<T>& obj);				/*| BIG 5 (COPY CONST)		|*/
	PFArray(PFArray<T>&& obj);			/*|	BIG 5 (MOVE COPY CONST)	|*/
	void operator=(const PFArray<T>& obj);		/*|	BIG 5 (ASSIGNMENT OPER)	|*/
	void operator=(PFArray<T>&& obj);		/*|	BIG 5 (MOVE COPY ASSIGN)|*/
	~PFArray() = default;						/*| BIG 5 (DESTRUCTER)		|*/

	/*____MEMBER FUNCTIONS_____*/
	void PushBack(const T& value);
	void PopBack();
	inline const T At(sizeType index)const;
	template<typename X>
	friend std::ostream& operator<<(std::ostream& COUT, const PFArray<X>& object);


	inline bool empty()const{return (used == 0 ? true : false);}
	inline int size()const{return capacity;}
	bool erase(PFArrayIterator<T>& iter);
	inline void clear(){used = 0;}
	inline PFArrayIterator<T> begin()const{return (PFArrayIterator<T>(Array.get()));}
	inline PFArrayIterator<T> end()const{return PFArrayIterator<T>((Array.get() + used));}
	inline const PFArrayIterator<T> cbegin()const{return PFArrayIterator<T>(Array.get());}
	inline const PFArrayIterator<T> cend()const{return PFArrayIterator<T>(Array.get() + used);}
};

template <typename T>
std::ostream& operator<<(std::ostream& COUT, const PFArray<T>& object);

}
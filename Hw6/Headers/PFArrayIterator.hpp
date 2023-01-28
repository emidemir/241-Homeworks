#ifndef PFA_RRAY_ITERATOR
#define PFA_RRAY_ITERATOR

#include <iostream>
#include <memory>
#include <vector>
#include <iterator>

namespace Emirhan{

template<class T>
class PFArrayIterator{

/*These are iterator_traits for random access iterators. STL library algorithms which use Rand. Acc. Iter. uses these variables.*/
public:
using	value_type = T;
using	pointer = T*;
using	reference = T&;
using	difference_type = std::ptrdiff_t;
using	iterator_category = std::random_access_iterator_tag;

/*These operator overloadings are for making iterator more flexible with begin end end function of PFArray class*/
public:
PFArrayIterator(){
	iter = nullptr;
}

PFArrayIterator(T* ptr){
	iter = ptr;
}

PFArrayIterator(const PFArrayIterator<T>& object) : iter(object.iter){

}

void operator=(T* object){iter = object;}
bool operator!=(T* object){return !(iter == object);}
bool operator==(T* obj){return (iter == obj);}


/*Required operators for every iterator class*/
public:

	PFArrayIterator& operator++(){
		++iter;
		return (*this);
	}

	PFArrayIterator& operator--(){
		--iter;
		return (*this);
	}

	PFArrayIterator& operator++(int){
		PFArrayIterator temp;
		temp.iter = iter;
		(*this->iter++);
		return (temp);
	}

	PFArrayIterator& operator--(int){
		PFArrayIterator temp;
		temp.iter = iter;
		(*this->iter++);
		return (temp);
	}

	reference operator*(){
		return *iter;
	}

	pointer operator->(){
		return iter;
	}

	value_type operator[](std::size_t index){
		return *(iter + index);
	}

	difference_type operator-(PFArrayIterator& obj){
		return ((this->iter) - (obj.iter));
	};

	PFArrayIterator<T> operator-(const difference_type other){
		PFArrayIterator<T> temp;
		temp.iter = iter - other;
		return (temp);
	};

	PFArrayIterator<T> operator+(const difference_type other){
		PFArrayIterator<T> temp;
		temp.iter = iter + other; 
		return (temp);
	}

	PFArrayIterator<T>& operator+=(const PFArrayIterator<T>& other){
		iter = iter + other.iter;
		return (*this);
	}

	PFArrayIterator& operator-=(const PFArrayIterator<T> other){
		this->iter = iter - other;
		return (*this);
	}

	bool operator==(const PFArrayIterator& obj){
		return ((this->iter) == (obj.iter));
	}
	
	bool operator!=(const PFArrayIterator& obj){
		return !((this->iter) == (obj.iter));		
	}

	bool operator<(const PFArrayIterator& obj){
		return ((this->iter) < (obj.iter));
	}

	bool operator>(const PFArrayIterator& obj){
		return ((this->iter) > (obj.iter));
	}
	
	bool operator<=(const PFArrayIterator& obj){
		return ((this->iter) <= (obj.iter));
	}

	bool operator>=(const PFArrayIterator& obj){
		return ((this->iter) >= (obj.iter));
	}

private:
	T *iter;
};

}
#endif
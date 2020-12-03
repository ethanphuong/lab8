#ifndef __CONTAINER_HPP__
#define __CONTAINER_HPP__

#include "sort.hpp"
#include "base.hpp"

class Sort;
class Base;

class Container {
    protected:
        Sort* sort_function;

    public:
        /* Constructors */
        Container() : sort_function(nullptr) { };
        Container(Sort* function) : sort_function(function) { };

        /* Non Virtual Functions */
       	void set_sort_function(Sort* sort_function)
        {
		this->sort_function = sort_function;
       	}
	virtual void add_element(Base* element) = 0;
	virtual void print() = 0;
	virtual void sort() = 0;
	virtual void swap(int i, int j) = 0;
	virtual Base* at(int i) = 0;
	virtual int size() =  0;
};
#endif

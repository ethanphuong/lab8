#ifndef __RANDOM_HPP__
#define __RANDOM_HPP__

#include "base.hpp"
#include <string>
#include "iterator.hpp"
#include "visitor.hpp"

class Random : public Base {
    private:
	double randomNumber;
	std::string stringNumber;
    public:
        Random() : Base()
	{
		srand(time(0));
		randomNumber = (rand() % 100);  
		stringNumber = std::to_string(randomNumber);
	}
	virtual double evaluate()
	{
		return randomNumber;
	}
	
	virtual std::string stringify()
	{
		return stringNumber;
	}
	
     	Base* get_left() 
	{
		return nullptr;
	}
     	Base* get_right() 
	{	
		return nullptr;
	}
	Iterator* create_iterator()
	{
		Iterator* it = new BinaryIterator(this);
     		return it;
     	}
     	void accept(CountVisitor* vis) 
	{
     		vis->visit_rand();
    	}
};		

#endif //__OP_HPP__


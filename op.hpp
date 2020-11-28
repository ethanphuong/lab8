#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    protected:
	double doubleNumber;
	std::string stringNumber;
    public:
        Op(double value) : Base()
 	{
		doubleNumber = value;
		stringNumber = std::to_string(value);
	}
	
	virtual double evaluate()
	{
		return doubleNumber;
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
        	Iterator* it = new NullIterator(this);
        	return it;
        }
        void accept(CountVisitor* vis) 
	{
        vis->visit_op();
        }
};

#endif //__OP_HPP__

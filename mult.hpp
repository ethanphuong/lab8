#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "op.hpp"
#include "base.hpp"
#include "iterator.hpp"

class Mult: public Base{
protected:
	double lhs, rhs, multAnswer;
	std::string lhsString, rhsString, multString;
	Base* left_child;
	Base* right_child;
public:
	Mult(Base* lhsOp, Base* rhsOp)
	{
		left_child = lhsOp;
		right_child = rhsOp;
		lhs = lhsOp->evaluate();
		rhs = rhsOp->evaluate();
		lhsString = lhsOp->stringify();
		rhsString = rhsOp->stringify();
	}
	
	virtual double evaluate()
	{
		multAnswer = lhs * rhs;
		return multAnswer;
	}

	virtual std::string stringify()
	{
		multString = "(" + lhsString + " * " + rhsString + ")";
		return multString;
	}
	
     	Base* get_left() 
	{
		return left_child;
	}
     	Base* get_right() 
	{	
		return right_child;
	}
	
	virtual Iterator* create_iterator()
	{
		Iterator* it = new BinaryIterator(this);
     		return it;
     	}
};
#endif

#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "op.hpp"

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
	Iterator* create_iterator()
	{
		Iterator* it = new BinaryIterator(this);
     		return it;
     	}
     	void accept(CountVisitor* vis) 
	{
     		vis->visit_mult();
    	}
};
#endif

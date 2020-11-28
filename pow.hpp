#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "op.hpp"
#include <math.h>

class Pow: public Base{
protected:
	double lhs, rhs, powAnswer;
	std::string lhsString, rhsString, powString;
	Base* left_child;
	Base* right_child;
public:
	Pow(Base* lhsOp, Base* rhsOp)
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
		powAnswer = pow(lhs, rhs);
		return powAnswer;
	}

	virtual std::string stringify()
	{
		powString = "(" + lhsString + " ** " + rhsString + ")";
		return powString;
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
     		vis->visit_pow();
    	}
};
#endif


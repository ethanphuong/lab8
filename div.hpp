#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include "op.hpp"

#include "iterator.hpp"
#include "visitor.hpp"

class Div: public Base{
protected:
	double lhs, rhs, divAnswer;
	std::string lhsString, rhsString, divString;
	Base* left_child;
	Base* right_child;
public:
	Div(Base* lhsOp, Base* rhsOp)
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
		divAnswer = lhs / rhs;
		return divAnswer;
	}

	virtual std::string stringify()
	{
		divString = "(" + lhsString + " / " + rhsString + ")";
		return divString;
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

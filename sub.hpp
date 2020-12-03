#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"

#include "iterator.hpp"
#include "visitor.hpp"

class Sub: public Base{
protected:
	double lhs, rhs, subAnswer;
	std::string lhsString, rhsString, subString;
	Base* left_child;
	Base* right_child;
public:
	Sub(Base* lhsOp, Base* rhsOp)
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
		subAnswer = lhs - rhs;
		return subAnswer;
	}

	virtual std::string stringify()
	{
		subString = "(" + lhsString + " - " + rhsString + ")";
		return subString;
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
	
	void accept(CountVisitor* vis) 
	{
		vis->visit_sub();
	}
};
#endif

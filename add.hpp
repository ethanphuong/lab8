#ifndef __ADD__HPP__
#define __ADD__HPP__

#include "base.hpp"
#include "op.hpp"

#include "iterator.hpp"

class Add: public Base{
protected:
	double lhs, rhs, addAnswer;
	std::string lhsString, rhsString, addString;
	Base* left_child;
	Base* right_child;
public:
	Add(Base* lhsOp, Base* rhsOp)
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
		addAnswer = lhs + rhs;
		return addAnswer;
	}

	virtual std::string stringify()
	{
		addString = "(" + lhsString + " + " + rhsString + ")";
		return addString;
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
     		vis->visit_add();
     	}
};
#endif

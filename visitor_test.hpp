#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "div.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "rand.hpp"
#include "gtest/gtest.h"
#include "visitor.hpp"

TEST(VisitorTest, VisitorTest1){
	CountVisitor *visitor = new CountVisitor();
	Base *num1 = new Op(8);
	Base *num2 = new Op(4);
	
	num1->accept(visitor);
	EXPECT_EQ(visitor->op_count(), 1);
	num2->accept(visitor);
	EXPECT_EQ(visitor->op_count() , 2);

	Base* temp1 = new Sub(num1, num2);
	Base* temp2 = new Div(num1, num2);
	
	temp1->accept(visitor);
	temp2->accept(visitor);

	EXPECT_EQ(visitor->op_count(), 2);
	EXPECT_EQ(visitor->sub_count(), 1);
}

#endif

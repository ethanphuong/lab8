#ifndef _VISITOR_TEST_HPP
#define _VISITOR_TEST_HPP

#include <iostream>
using namespace std;
#include <vector>
#include <list>

#include "op.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "visitor.hpp"
#include "iterator.hpp"
#include "container.hpp"

TEST(CountVisitorTest, SimpleTree1) {
  Op* op1 = new Op(3);
  Op* op2 = new Op(5);
  Op* op3 = new Op(2);
  Op* op4 = new Op(1);
	Sub* first = new Sub( op1, op2);
	Div* second = new Div( op3, op4);

	Add* dummy = new Add(first,second);
	CountVisitor *test1 = new CountVisitor();
	PreorderIterator *test2 = new PreorderIterator(dummy);
	test2->first();
	while(test2->is_done() == false){
	    test2->current()->accept(test1);
	    test2->next();
	}
	EXPECT_EQ(test1->sub_count(), 1);
	EXPECT_EQ(test1->div_count(), 1);
	EXPECT_EQ(test1->op_count(), 4);
}
#endif

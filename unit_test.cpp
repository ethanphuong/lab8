#include "gtest/gtest.h"
#include "base.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "op.hpp"

TEST(IteratorTest, PowBinaryTest){
	Base* num1 = new Op(3);
	Base* num2 = new Op(7);
	Mult* temp = new Mult(num1, num2);
	Base* dummy = new Add(temp, num2);

	Iterator *it = dummy->create_iterator();

	EXPECT_EQ(dummy->get_left(), temp);
	EXPECT_EQ(dummy->get_right(), num2);
} 

TEST(IteratorTest, PowBinaryTest2){
	Base* num1 = new Op(3);
	Base* num2 = new Op(7);
	Mult* temp = new Mult(num1, num2);
	Base* dummy = new Add(num2, temp);

	Iterator *it = dummy->create_iterator();

	EXPECT_EQ(dummy->get_left(), num2);
	EXPECT_EQ(dummy->get_right(), temp);
} 

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

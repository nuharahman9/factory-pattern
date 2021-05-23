#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__
#include "gtest/gtest.h"
#include "op.hpp"

TEST(OpTest, OpEvaluateZero) {
        Base *test = new Op(0);
        EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateNonzero) {
        Base *test = new Op(4);
        EXPECT_EQ(test->evaluate(), 4);
}
TEST(OpTest, OpEvaluateNegative) {
    Op* test = new Op(-4);
    EXPECT_EQ(test->evaluate(), -4 );
}
TEST(MultTest, OpStringifyNonzero) {
        Base *test = new Op(50); 
        EXPECT_EQ(test->stringify(), "50");
}
TEST(OpTest, OpStringifyZero) {
        Base *test = new Op(0); 
        EXPECT_EQ(test->stringify(), "0");
}
TEST(OpTest, OpStringifyNegative) {
    Op* test = new Op(-2);
    EXPECT_EQ(test->stringify(), "-2");
}


#endif

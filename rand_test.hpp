#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandEvaluateLessThan100) {
	Rand* test = new Rand();
	EXPECT_LT(test->evaluate(), 100.0);
}

TEST(RandTest, RandEvaluateMoreThanZero) {
        Rand* test = new Rand();
        EXPECT_LT(test->evaluate(), 0.0);
}

TEST(RandTest, RandStringifyNot100) {
        Rand* test = new Rand();
        EXPECT_LT(test->stringify(),"100.0");
}

#endif // __RAND_TEST_HPP__

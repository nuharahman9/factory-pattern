#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__


#include "gtest/gtest.h"
#include "pow.hpp"
#include "op.hpp"
#include "factory.hpp"


TEST(PowTest, Pow) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="2";
        test_val[2]="**";
	test_val[3]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "2 ** 3");
        EXPECT_EQ(conversion->evaluate(), 8.000);
}

TEST(PowTest, Pow2) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="7";
        test_val[2]="**";
        test_val[3]="1";
        test_val[4]="**";
        test_val[5]="2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "7 ** 1 ** 2");
        EXPECT_EQ(conversion->evaluate(), 49.000);
}

TEST(PowTest, Pow3) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="7";
        test_val[2]="**";
        test_val[3]="0";
        test_val[4]="**";
        test_val[5]="2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "7 ** 0 ** 2");
        EXPECT_EQ(conversion->evaluate(), 1.000);
}

TEST(PowTest, Pow4) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="0";
        test_val[2]="**";
        test_val[3]="1";
        test_val[4]="**";
        test_val[5]="5";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "0 ** 1 ** 5");
        EXPECT_EQ(conversion->evaluate(), 0.000);
}

TEST(PowTest, Pow5) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="-4";
        test_val[2]="**";
        test_val[3]="1";
        test_val[4]="**";
        test_val[5]="2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "-4 ** 1 ** 2");
        EXPECT_EQ(conversion->evaluate(), 16.000);
}

TEST(PowTest, Pow6) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="-4";
        test_val[2]="**";
        test_val[3]="1";
        test_val[4]="**";
        test_val[5]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "-4 ** 1 ** 3");
        EXPECT_EQ(conversion->evaluate(), -64.000);
}
#endif

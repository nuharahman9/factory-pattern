#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__


#include "gtest/gtest.h"
#include "div.hpp"
#include "op.hpp"
#include "factory.hpp"


TEST(DivTest, Div) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="8";
        test_val[2]="/";
        test_val[3]="2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8 / 2");
        EXPECT_EQ(conversion->evaluate(), 4.000);
}

TEST(DivTest, Div2) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="9";
        test_val[2]="/";
        test_val[3]="1";
        test_val[4]="/";
        test_val[5]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "9 / 1 / 3");
        EXPECT_EQ(conversion->evaluate(), 3.000);
}

TEST(DivTest, Div3) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="0";
        test_val[2]="/";
        test_val[3]="1";
        test_val[4]="/";
        test_val[5]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "0 / 1 / 3");
        EXPECT_EQ(conversion->evaluate(), 0.000);
}

TEST(DivTest, Div4) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="-9";
        test_val[2]="/";
        test_val[3]="1";
        test_val[4]="/";
        test_val[5]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "-9 / 1 / 3");
        EXPECT_EQ(conversion->evaluate(), -3.000);
}

TEST(DivTest, Div5) {
        char* test_val[8];
        test_val[0]="T";
        test_val[1]="9";
        test_val[2]="/";
        test_val[3]="1";
        test_val[4]="/";
        test_val[5]="3";
	test_val[6]="/";
        test_val[7]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 8);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "9 / 1 / 3 / 3");
        EXPECT_EQ(conversion->evaluate(), 1.000);
}

#endif


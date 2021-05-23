#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__


#include "gtest/gtest.h"
#include "mult.hpp"
#include "op.hpp"
#include "factory.hpp"


TEST(MultTest, Mult) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="2";
        test_val[2]="*";
        test_val[3]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "2 * 3");
        EXPECT_EQ(conversion->evaluate(), 6.000);
}

TEST(MultTest, Mult2) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="1";
        test_val[2]="*";
        test_val[3]="8";
        test_val[4]="*";
        test_val[5]="2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "1 * 8 * 2");
        EXPECT_EQ(conversion->evaluate(), 16.000);
}

TEST(MultTest, Mult3) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="-1";
        test_val[2]="*";
        test_val[3]="8";
        test_val[4]="*";
        test_val[5]="-2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "-1 * 8 * -2");
        EXPECT_EQ(conversion->evaluate(), 16.000);
}

TEST(MultTest, Mult4) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="1";
        test_val[2]="*";
        test_val[3]="0";
        test_val[4]="*";
        test_val[5]="2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "1 * 0 * 2");
        EXPECT_EQ(conversion->evaluate(), 0.000);
}

TEST(MultTest, Mult5) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="1";
        test_val[2]="*";
        test_val[3]="8";
        test_val[4]="*";
        test_val[5]="-3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "1 * 8 * -3");
        EXPECT_EQ(conversion->evaluate(), -24.000);
}
#endif


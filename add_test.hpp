#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__


#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"
#include "factory.hpp"


TEST(AddTest, Add) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="2";
        test_val[2]="+";
	test_val[3]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "2 + 3");
        EXPECT_EQ(conversion->evaluate(), 5.000);
}

TEST(AddTest, Add2) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="4";
        test_val[2]="+";
        test_val[3]="7";
        test_val[4]="+";
        test_val[5]="2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "4 + 7 + 2");
        EXPECT_EQ(conversion->evaluate(), 13.000);
}

TEST(AddTest, Add3) {
        char* test_val[8];
        test_val[0]="T";
        test_val[1]="4";
        test_val[2]="+";
        test_val[3]="7";
        test_val[4]="+";
        test_val[5]="2";
	test_val[6]="+";
	test_val[7]="5";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 8);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "4 + 7 + 2 + 5");
        EXPECT_EQ(conversion->evaluate(), 18.000);
}
TEST(AddTest, Add4) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="4";
        test_val[2]="+";
        test_val[3]="-7";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "4 + -7");
        EXPECT_EQ(conversion->evaluate(), -3.000);
}
TEST(AddTest, Add5) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="0";
        test_val[2]="+";
        test_val[3]="-7";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "0 + -7");
        EXPECT_EQ(conversion->evaluate(), -7.000);
}

#endif

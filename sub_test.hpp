#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__


#include "gtest/gtest.h"
#include "sub.hpp"
#include "op.hpp"
#include "factory.hpp"


TEST(SubTest, Sub) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="8";
        test_val[2]="-";
        test_val[3]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8 - 3");
        EXPECT_EQ(conversion->evaluate(), 5.000);
}

TEST(SubTest, Sub2) {
        char* test_val[6];
        test_val[0]="T";
        test_val[1]="7";
        test_val[2]="-";
        test_val[3]="1";
        test_val[4]="-";
        test_val[5]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 6);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "7 - 1 - 3");
        EXPECT_EQ(conversion->evaluate(), 3.000);
}

TEST(SubTest, Sub3) {
        char* test_val[8];
        test_val[0]="T";
        test_val[1]="8";
        test_val[2]="-";
        test_val[3]="3";
	test_val[4]="-";
        test_val[5]="8";
        test_val[6]="-";
        test_val[7]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 8);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8 - 3 - 8 - 3");
        EXPECT_EQ(conversion->evaluate(), -6.000);
}

TEST(SubTest, Sub4) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="-8";
        test_val[2]="-";
        test_val[3]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "-8 - 3");
        EXPECT_EQ(conversion->evaluate(), -11.000);
}

TEST(SubTest, Sub5) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="8";
        test_val[2]="-";
        test_val[3]="0";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8 - 0");
        EXPECT_EQ(conversion->evaluate(), 8.000);
}
TEST(SubTest, Sub6) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="8";
        test_val[2]="-";
        test_val[3]="8";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8 - 8");
        EXPECT_EQ(conversion->evaluate(), 0.000);
}


#endif


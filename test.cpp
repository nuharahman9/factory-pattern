#include "gtest/gtest.h"

#include "add.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "factory.hpp"


TEST(FactoryTest, Test) {
        char* test_val[8];
        test_val[0]="T";
        test_val[1]="2";
        test_val[2]="+";
        test_val[3]="3";
        test_val[4]="*";
        test_val[5]="1";
        test_val[6]="/";
        test_val[7]="5";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 8);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "2 + 3 * 1 / 5");
        EXPECT_EQ(conversion->evaluate(), 1.000);
}

TEST(FactoryTest, invalidPtr) {
        char* test_val[4];
        test_val[0]="T";
        test_val[1]="2";
        test_val[2]="?";
	test_val[3] = "4"; 
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val, 4);
        EXPECT_EQ(conversion, nullptr);
}
TEST(FactoryTest, minimumLength) {
        char* test_val[3];
        test_val[0]="T";
        test_val[1]="2";
        test_val[2]="+";
        Factory* factory = new Factory();
        Base* conversion = factory->parse(test_val, 3);
        EXPECT_EQ(conversion, nullptr);
}


TEST(FactoryTest, Test2) {
        char* test_val[8];
        test_val[0]="T";
        test_val[1]="4";
        test_val[2]="**";
        test_val[3]="2";
        test_val[4]="-";
        test_val[5]="7";
        test_val[6]="/";
        test_val[7]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 8);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "4 ** 2 - 7 / 3");
        EXPECT_EQ(conversion->evaluate(), 3.000);
}

TEST(FactoryTest, Test3) {
        char* test_val[8];
        test_val[0]="T";
        test_val[1]="9";
        test_val[2]="-";
        test_val[3]="8";
        test_val[4]="*";
        test_val[5]="7";
        test_val[6]="**";
        test_val[7]="2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 8);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "9 - 8 * 7 ** 2");
        EXPECT_EQ(conversion->evaluate(), 49.000);
}

TEST(FactoryTest, Test4) {
        char* test_val[8];
        test_val[0]="T";
        test_val[1]="-4";
        test_val[2]="**";
        test_val[3]="2";
        test_val[4]="-";
        test_val[5]="7";
        test_val[6]="/";
        test_val[7]="-3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 8);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "-4 ** 2 - 7 / -3");
        EXPECT_EQ(conversion->evaluate(), -3.000);
}

TEST(FactoryTest, Test5) {
        char* test_val[8];
        test_val[0]="T";
        test_val[1]="4";
        test_val[2]="**";
        test_val[3]="0";
        test_val[4]="-";
        test_val[5]="7";
        test_val[6]="/";
        test_val[7]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 8);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "4 ** 0 - 7 / 3");
        EXPECT_EQ(conversion->evaluate(), -2.000);
}

TEST(FactoryTest, Test6) {
        char* test_val[8];
        test_val[0]="T";
        test_val[1]="0";
        test_val[2]="**";
        test_val[3]="2";
        test_val[4]="-";
        test_val[5]="0";
        test_val[6]="/";
        test_val[7]="3";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 8);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "0 ** 2 - 0 / 3");
        EXPECT_EQ(conversion->evaluate(), 0.000);
}


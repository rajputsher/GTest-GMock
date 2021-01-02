#include <iostream>
#include <gtest/gtest.h>
#include "LibraryCode.hpp"

TEST(TestSample1,TestAddition)
{
    ASSERT_EQ(2,add(1,1)); //Assert the output is 2 with add(1,1)
}

TEST(TestSample2,TestAddition)
{
    ASSERT_EQ(2,add(2,2)); //Assert the output is 2 with add(1,1)
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
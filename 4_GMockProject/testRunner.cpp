#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "LibraryCode.hpp"






/*
TEST(TestSample1,TestAddition)
{
    ASSERT_EQ(2,add(1,1)); //Assert the output is 2 with add(1,1)
}

TEST(TestSample2,TestAddition)
{
    ASSERT_EQ(2,add(2,2)); //Assert the output is 2 with add(1,1)
}
*/

// G-MOCK

class SomeClass
{
    public:
        SomeClass() = default;
        virtual void someMethod()
        {
            std::cout<<"Say Something\n";
        }
};

class MockedClass: public SomeClass
{
    public:
        MockedClass()=default;
        MOCK_METHOD0(someMethod, void());
};

TEST(TestSample,TestMock)
{
    MockedClass mc;
    EXPECT_CALL(mc,someMethod()).Times(1);
    mc.someMethod();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <iostream>
#include <gtest/gtest.h>
#include "LibraryCode.hpp"
#include <vector>

TEST(TestCountPositives,BasicTest)
{
    //Arrange
    std::vector<int> inputVector{1,-2, 3, -4, 5, -6, -7};

    //Act
    int count = countPositives(inputVector);

    //Assert
    ASSERT_EQ(3,count); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST(TestCountPositives,EmptyVectorTest)
{
    //Arrange
    std::vector<int> inputVector{};

    //Act
    int count = countPositives(inputVector);

    //Assert
    ASSERT_EQ(0,count); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST(TestCountPositives,AllNegativeTest)
{
    //Arrange
    std::vector<int> inputVector{-1,-2,-3};

    //Act
    int count = countPositives(inputVector);

    //Assert
    ASSERT_EQ(0,count); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST(TestCountPositives,PrintAfterAssert)
{
    //Arrange
    std::vector<int> inputVector{-1,-2,-3};

    //Act
    int count = countPositives(inputVector);

    //Assert
    ASSERT_EQ(0,count); //ASSERT_EQ(Expected value, Test Ouput)
    std::cout<< "After assertion"<<std::endl; //This is printed only if the test passes.
}

TEST(TestCountPositives,DoesnotPrintAfterAssert)
{
    //Arrange
    std::vector<int> inputVector{-1,-2,-3};

    //Act
    int count = countPositives(inputVector);

    //Assert
    ASSERT_EQ(20,count); //ASSERT_EQ(Expected value, Test Ouput)
    std::cout<< " Message After assertion"<<std::endl; //This is printed only if the test passes.
}

TEST(TestCountPositives,PrintAfterExpect)
{
    //Arrange
    std::vector<int> inputVector{-1,-2,-3};

    //Act
    int count = countPositives(inputVector);

    //Assert
    EXPECT_EQ(20,count); //ASSERT_EQ(Expected value, Test Ouput)
    std::cout<< "Message After expect"<<std::endl; 
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
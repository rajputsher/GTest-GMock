#include <iostream>
#include <gtest/gtest.h>
#include "LibraryCode.hpp"
#include <cctype>
#include <string.h>


TEST(ExceptionTest ,NegativeInpTest)
{
    //Arrange
    double inputValue = -9;

    //Assert
    ASSERT_ANY_THROW(mySqrt(inputValue));
}

TEST(ExceptionTest ,NegativeInpAssertThrow)
{
    //Arrange
    double inputValue = -9;


    //Assert
    ASSERT_THROW(mySqrt(inputValue),std::runtime_error);
}

TEST(ExceptionTest ,PositiveInpAssertThrow)
{
    //Arrange
    double inputValue = 9;

    //Assert
    ASSERT_ANY_THROW(mySqrt(inputValue));
}

TEST(ExceptionTest ,PositiveInpAssertNoThrow)
{
    //Arrange
    double inputValue = 9;

    //Act
    double sqrtInp = mySqrt(mySqrt(inputValue));

    //Assert
    ASSERT_NO_THROW(sqrtInp);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <iostream>
#include <gtest/gtest.h>
#include "LibraryCode.hpp"
#include <cctype>
#include <string.h>


TEST(ToUpperTest,TestUsingAssertEQ)
{
    //Arrange
    char inputString[]="Have a good day";

    //Act
    toUpper(inputString);

    //Assert
    ASSERT_EQ("HAVE A GOOD DAY",inputString); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST(ToUpperTest,TestUsingAssertSTR_EQ)
{
    //Arrange
    char inputString[]="Have a good day";

    //Act
    toUpper(inputString);

    //Assert
    ASSERT_STREQ("HAVE A GOOD DAY",inputString); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST(ToUpperTest,TestUsingAssertSTR_NE)
{
    //Arrange
    char inputString[]="Have a good day";

    //Act
    toUpper(inputString);

    //Assert
    ASSERT_STRNE("Have A GOOD DAY",inputString); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST(ToUpperTest,TestTypeStringAssertSTR_EQ)
{
    //Arrange
    char inputString[]="Have a good day";

    //Act
    toUpper(inputString);
    std::string str(inputString);
    //Assert
    ASSERT_STREQ("HAVE A GOOD DAY",inputString); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST(ToUpperTest,TestTypeStringAssert_EQ)
{
    //Arrange
    char inputString[]="Have a good day";

    //Act
    toUpper(inputString);
    std::string str(inputString);
    //Assert
    ASSERT_EQ("HAVE A GOOD DAY",inputString); //ASSERT_EQ(Expected value, Test Ouput)
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
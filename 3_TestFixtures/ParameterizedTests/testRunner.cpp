#include <iostream>
#include <stdexcept>
#include <gtest/gtest.h>
#include "LibraryCode.hpp"
#include <gmock/gmock.h>
#include <vector>

//Validator(5,10)
//Good Test values are:
//4: outside the lower bound
//5: lower bound
//7: with in the range
//10:Upper bound
//11:Outside the upper bound


/*
class ValidatorFixture: public testing::TestWithParam<int> //This class extends testing class TestwithParam with input datatype : int
{
    public:
    protected:
    Validator mValidator{5,10};
};

class ValidatorNegativeFixture: public testing::TestWithParam<int> //This class extends testing class TestwithParam with input datatype : int
{
    public:
    protected:
    Validator mValidator{5,10};
};

TEST_P(ValidatorFixture,TestInRange)
{
    //Arrange
    int param = GetParam();
    std::cout << "Param = " << param << '\n';
    //Act
    bool isInside = mValidator.inRange(param);
    //Assert
    ASSERT_TRUE(isInside);

}

TEST_P(ValidatorNegativeFixture,TestNotInRange)
{
    //Arrange
    int param = GetParam();
    std::cout << "Param(Not in Range)= " << param << '\n';
    //Act
    bool isInside = mValidator.inRange(param);
    //Assert
    ASSERT_FALSE(isInside);
}

INSTANTIATE_TEST_CASE_P(InRangeTrue,ValidatorFixture,testing::Values(5,6,7,9,10));
INSTANTIATE_TEST_CASE_P(InRangeFalse,ValidatorNegativeFixture,testing::Values(-50,4,11,100));
*/
class ValidatorTupleFixture: public testing::TestWithParam<std::tuple<int,bool>> //This class extends testing class TestwithParam with input datatype : int
{
    public:
    protected:
        Validator mValidator{5,10};
};

TEST_P(ValidatorTupleFixture,TestInRange)
{
    //Arrange
    std::tuple<int,bool> tuple = GetParam();
    int param = std::get<0>(tuple);
    bool expectedValue = std::get<1>(tuple);
    std::cout << "Param = " << param << '\n'<<expectedValue <<'\n';
    //Act
    bool isInside = mValidator.inRange(param);
    //Assert
    ASSERT_EQ(expectedValue,isInside);

}
INSTANTIATE_TEST_CASE_P(InRangeTrue,ValidatorTupleFixture,testing::Values(
    std::make_tuple(5,true),
    std::make_tuple(6,true),
    std::make_tuple(7,true),
    std::make_tuple(9,true),
    std::make_tuple(10,true),
    std::make_tuple(4,false),
    std::make_tuple(-50,false),
    std::make_tuple(11,false),
    std::make_tuple(100,false)));

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
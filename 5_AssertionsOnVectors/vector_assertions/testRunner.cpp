#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "LibraryCode.hpp"
#include <vector>
#include <stdexcept>


TEST(VectorTests, P_ElementsAreTest)
{
    std::vector<int> v= generateNumbers(5,3); 
    // 0,1,2,0,1

    ASSERT_THAT(v,testing::ElementsAre(0,1,2,0,1));
}

TEST(VectorTests, P_RangeTest)
{
    std::vector<int> v= generateNumbers(5,3); 
    // 0,1,2,0,1

    //ASSERT_THAT(v,testing::Each(testing::AllOf(testing::Gt(0),testing::Lt(3))));
    using namespace testing;
    ASSERT_THAT(v,Each(AllOf(Ge(0),Lt(3))));


}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
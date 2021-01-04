#include <iostream>
#include <gtest/gtest.h>
#include "LibraryCode.hpp"

// #define __WIN32
// or WIN32, or __WIN32__

TEST(UnixSuite, DummyTest1)
{
  std::cout << "Dummy test 1 - Unix \n";
  #ifdef __WIN32
  FAIL();
  #else
  SUCCEED();
  #endif
}


TEST(UnixSuite, DummyTest2)
{
  std::cout << "Dummy test 2 - Unix \n";
  #ifdef __WIN32
  FAIL();
  #else
  SUCCEED();
  #endif
}


TEST(WindowsSuite, DummyTest1)
{
  std::cout << "Dummy test 1 - Windows \n";
  #ifdef __WIN32
  SUCCEED();
  #else
  FAIL();
  #endif
}


TEST(WindowsSuite, DummyTest2)
{
  std::cout << "Dummy test 2 - Windows \n";
  #ifdef __WIN32
  SUCCEED();
  #else
  FAIL();
  #endif
}



int main(int argc, char **argv)
{
  #ifdef __WIN32
    testing::GTEST_FLAG(filter) = "WindowsSuite.*";
  #else
    testing::GTEST_FLAG(filter) = "UnixSuite.*"; //run only the TEST with names starting with UnixSuite.
    //or from the command time >> ./unitTestRunner --gtest_filter='UnixSuite.DummyTest1'
    //Commang line takes precedence over the code in main functions
    //To run all but UnixSuite ./unitTestRunner --gtest_filter='-UnixSuite.DummyTest1'
  #endif
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

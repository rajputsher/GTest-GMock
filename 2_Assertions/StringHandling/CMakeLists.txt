cmake_minimum_required(VERSION 3.16)
project(Test_GTest)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}") #This line is to test that GTest is rightly setup

#################
#####Library#####
#################
add_library(commonLibrary LibraryCode.cpp)


#################
#####Executable#####
#################
#add_executable(mainApp main.cpp)
#target_link_libraries(mainApp commonLibrary) 

#################
#####Unit Test#####
#################
add_executable(testRunner testRunner.cpp)
target_link_libraries(testRunner commonLibrary ${GTEST_LIBRARIES} pthread)
cmake_minimum_required(VERSION 3.16)
project(Test_GTest)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}") #This line is to test that GTest is rightly setup

#################
#####Library#####
#################
add_library(databaseConnectionLibrary IDatabaseConnection.cpp)
add_library(employeeManagerLibrary EmployeeManager.cpp)

set(ACTUAL_LIBRARIES databaseConnectionLibrary employeeManagerLibrary)
target_link_libraries(${ACTUAL_LIBRARIES})

##################################
#####GTest Gmock Library#####
##################################
set(GMOCK_LIBRARIES /usr/lib/libgmock.a  /usr/lib/libgmock_main.a)
set(GTEST_LIBRARIES_SR /usr/lib/libgtest.a  /usr/lib/libgtest_main.a)

#################
#####Executable#####
#################
add_executable(mainApp main.cpp)
target_link_libraries(mainApp) 


#################
#####Unit Test#####
#################
add_executable(testRunner testRunner.cpp)
target_link_libraries(testRunner  ${GTEST_LIBRARIES_SR} ${GMOCK_LIBRARIES} pthread ${ACTUAL_LIBRARIES})
# GoogleTest and GoogleMock

> This repository contains files created while learning GTest and GMock

---

### Table of Contents

- [Description](#description)
    - [Types of Testing](#types-of-testing)
    - [What is unit testing?](#what-is-unit-testing)
    - [Why unit test?](#why-unit-test)
    - [Unit Test Guidlines](#unit-test-guidlines)
    - [GTest](#gtest)
    - [GMock](#gmock)
- [How To Use](#how-to-use)

- [References](#references)

---

## Description

### Types of Testing
There are many types of software testing. Here are some of the common ones:

1. Unit testing 
2. Integration testing
3. System testing
4. Stress testing
5. Load testing
6. Acceptance  testing

First 3 are function testing methods/

### What is unit testing ?
Unit testing means writing code that verifies individual parts, or units, of an application or library. A unit is the smallest testable part of an application. Unit tests assess code in isolation.

In C++ this means writing tests for methods or functions. Tests only examine code within a single object. They don’t rely on external resources such as databases, web servers, or message brokers.

### Why Unit Test?
- Find Bugs Early : Mostly stupid bugs, introduced by developers.
- To avoid regressions: Not all bugs are stupid. Some bugs are quite intelligent. These are regressions. 

    Our system has been working in production for a long time, but we need to add a new feature or address a deficiency. So we modify the code and roll out a new version, and something else breaks. If we’re lucky, it’s easy to figure out. If not, cancel weekend plans.

    Our first line of defense against regressions is unit tests. Creating targeted routines that verify discrete behavior, and then running them on every build helps ensure that a new feature doesn’t come with a new bug.
- Unit tests are useful for regresssion testing, meaning that when we make a change, they help prevent the introduction of new bugs.
- To get early feedback

### Unit Test Guidlines
- A Unit : Can execute independently.

    For example, while using global variables, we must make sure that these variables are not visible to other tests.
- Test must run fast in the order of milliseconds.
- Unit tests must be isolated i.e,it must not dependend on external entities. For example: enter a key to continue testing

### Unit test structure

Basic structure of unit test is divided in to Arrange-Act-Assert(AAA): 

1. Arrange: in this section the test setup is done,i.e. Setup all inputs and preconditions.
2. Act: here call the method and functions that needs to be tested.
3. Assert: Check that the test results are as expected.

Advantages of this structure:
- Seperates the code under test from the setup and verification.
- Finds out obvious bad code qualities.


### GTest
Cross-platform C++ testing framework by Google

FEATURES of GTest:
- Rich set of assertions
- Value-parametrised tests
- Type-parametrised tests
- Death tests
- Test discovery
- XML test report generation
- Multi-threaded tests

ASSERTION MACROS

Gtest has a rich set of assetions.
```cpp
ASSERT_EQ(5, 5);
ASSERT_GE(5, 0);
ASSERT_FLOAT_EQ(4.4, 4.4444444287381217);
ASSERT_TRUE(somePtr);
ASSERT_EQ(c1.size(), c2.size())<< "Vectors c1 and c2 are of unequal length";
ASSERT_THROW(c1.at(47374), std::out_of_range);
ASSERT_DEATH(c1[47374], "Assertion failed:*");
```

EXPECT_* AND ASSERT_*
```cpp
// assertions abort test if they fail
ASSERT_TRUE(somePtr);
// even if expectations fail, the test continues
// allows multiple failures to be recorded in one test pass
EXPECT_EQ("donald", somePtr->name());
EXPECT_EQ(105, somePtr->age());
```

### GMock


---

## How To Use

#### Installation
Installing GoogleTest and GoogleMock on Linux (Ubuntu):
1. Download the source files from the [GoogleTest github page](https://github.com/google/googletest) and unzip them.
2. Open a terminal and go to the googletest folder. Let’s say it’s ~/googletest-master
3. Install cmake, if you don’t already have it installed:
```html
    sudo apt install cmake
```
4. Build the project:
```html
    cmake CMakeLists.txt
    make
```
5. Copy all the static libraries into /usr/lib:
```html
    cd lib
    sudo cp * /usr/lib
```
6. Go to the ​ googlemock/include ​ subfolder and copy the entire ​ gmock ​ folder into
/usr/local/include:
```html
    cd googlemock/include
    sudo cp -r gmock /usr/local/include
```
7. Similarly from the project root folder (~/googletest-master) go to googletest/include and copy the entire ​ gtest ​ folder into /usr/local/include
```html
    cd googletest/include
    sudo cp -r gtest /usr/local/include
```
---

## References
1. [GoogleTest Github](https://github.com/google/googletest)
2. [Google Test Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
3. [Waht is GMock C++ framework?](https://chromium.googlesource.com/external/github.com/google/googletest/+/refs/tags/release-1.8.0/googlemock/docs/ForDummies.md)
4. [Intro to GMOCK slides by Donald Whyte](http://donsoft.io/gmock-presentation/#/)


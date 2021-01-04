# Google Mock

## What is Mocking ?


<img src="image/1_WhatIsMocking.png" width=300 Height=450>

## Other Types of Test doubles:

1. Fake

<img src="image/2_Fake.png" width=400 Height=300>

2. Stubs

<img src="image/3_Stubs.png" width=400 Height=150>

3. Mock

<img src="image/4_Mocks.png" width=400 Height=200>

## Mocking Methods

### Current Method 

A way to mock a method is by extending a class and instead of redefining the methods that you want to override you just have to use the `MOCK_METHOD` macro

`MOCK_METHOD(ReturnType, MethodName,(Arguments...))`

Examples:
  
1. method: `int sum(int a,int b)` ; 
Mock: `MOCK_METHOD(int,sum,(int,int))` .
Note: Arguments but be in parantheses
   
    <img src="image/5_CurrentWayMock.png" width=400 Height=150>

2. If the return type is complex type, then we need to use paranthesis as well in the returnType (param1 of MOCK_METHOD) as shown below

    <img src="image/6_CurrentWay.png" width=400 Height=100>

3. There is another parameter to this macro that is specs list that is optional:
`MOCK_METHOD(ReturnType, MethodName,(Arguments...), (Specs...))`
Specs must also be in the paranthesis.
Note that in the below example the empty arguments list is represented by `()` and `const` spec is also is in parantheses

    <img src="image/7_CurrentWay.png" width=400 Height=150>

### Legacy method

The old version of the macro looked as shown below

<img src="image/8_Legacy.png" width=400 Height=150>


## Example used in 4_GMockProject

<img src="image/9_ExampleStructure.png" width=400 Height=250>


## Setting expectation and behaviour

How to make a method behave a certain way?
We have `ON_CALL` macro for that. It specifies the behaviour when the method is called.

<img src="image/10_SetExpectation.png" width=400 Height=175>

`ON_CALL` is rarely used most of the times `EXPECT_CALL` is used. `EXPECT_CALL` does what `ON_CALL` does and in addition to that adds expectation to test, if the test does not meet that expectation, test fails.

Example:

<img src="image/11_ExceptCallEx.png" width=400 Height=150>

**Setting Mock Behaviour**

To set a certain behaviour we can use `ACTION` macro. Then in the `ON_CALL` or `EXPECT_CALL` we can invoke that ``ACTION`` as in the example below.

<img src="image/12_ActionExpect.png" width=400 Height=150>

The `EXCEPT_CALL` can invoke an `ACTION` using the following functions:

<img src="image/14_SetHowManyTimes.png" width=400 Height=150>

Similarly we can harcode the return value in the following way: 

<img src="image/13_RETURN.png" width=400 Height=150>


To verify that the method was called after `EXPECT_CALL` we can use the one of the following:

<img src="image/15_Cardinality.png" width=400 Height=300>

## Matchers

To check the method was called with a certain value, google mock has matchers for that.

Examples:
1. Exact value

<img src="image/16_Matchers1.png" width=400 Height=100>

2. To check that the argument is greater or lower than certain value

<img src="image/17_Matchers2.png" width=400 Height=100>

similar matchers

<img src="image/18_Matchers2.png" width=300 Height=200>

to have any argument underscore can be used

<img src="image/19_Matchers2.png" width=400 Height=100>

to check if the argument is Null or Not Null

<img src="image/20_Matchers2.png" width=300 Height=75>

To check if the argument contains string/sub string

<img src="image/21_Matchers2.png" width=300 Height=100>


### Combining Matchers

Combination of matchers can be used to check for arguments

<img src="image/22_Matchers2.png" width=400 Height=100>

Matchers can be combined using the following:

- `AllOf()`
- `AnyOf()`
- `AllOfArray()`
- `AnyOfArray()`
- `Not()`

Matchers need not be only used with `EXPECT_CALL`, it can also be used in `ASSERT_THAT` assertions.


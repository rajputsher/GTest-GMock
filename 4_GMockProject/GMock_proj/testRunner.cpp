#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <map>

#include "IDatabaseConnection.hpp"
#include "Employee.hpp"
#include "EmployeeManager.hpp"

class MockDatabaseConnection: public IDatabaseConnection
{
    public: 
        MockDatabaseConnection(std::string serverAddress);
        MOCK_METHOD(void,connect,());
        //Legacy method:MOCK_METHOD0(connect,void()); 
        //MOCK_METHOD0 because there are no arguments
        MOCK_METHOD(void,disconnect,());
        //MOCK_METHOD0(connect,void())
        MOCK_METHOD(float,getSalary,(int),(const));
        //MOCK_CONST_METHOD1(getSalary,float(int));
        MOCK_METHOD(void,updateSalary,(int,float));
        //MOCK_METHOD2(updateSalary,void(int,float));
        MOCK_METHOD(std::vector<Employee>, getSalariesRange,(float),(const));
        //MOCK_CONST_METHOD1(getSalariesRange,std::vector<Employee>(float));
        MOCK_METHOD(std::vector<Employee>, getSalariesRange,(float, float),(const));
        //MOCK_CONST_METHOD2(getSalariesRange,std::vector<Employee>(float,float));
        //MOCK_METHOD((std::map<std::string,int>),something,()); //When return type is complex, put it in parantheses

        void someMemberMethod()
        {
            std::cout<<"Member method called\n";
            throw std::runtime_error("Dummy error");
        }

        void someMemberMethodArg(std::string param)
        {
            std::cout<<"Member method called wwith param = "<< param<<"\n";
            throw std::runtime_error("Dummy error");
        }
/*
  virtual float getSalary(int id) const = 0; // SELECT * FROM employees WHERE id=...
  virtual void updateSalary(int id, float newSalary) = 0;

  virtual std::vector<Employee> getSalariesRange(float low) const = 0; //just greater than low
  virtual std::vector<Employee> getSalariesRange(float low, float high) const = 0;

  virtual void connect();
  virtual void disconnect();
*/
};

MockDatabaseConnection::MockDatabaseConnection(std::string serverAddress): IDatabaseConnection(serverAddress)
{

}

/*
// By doing the below we do a real connection to the data base which we do not want
// that is the reason we need to use Mock
TEST(TestEmployeeManager, TestConnection)
{
    IDatabaseConnection dbConnection("dummy connection");
    EmployeeManager employeeManager(&dbConnection);
}
*/

TEST(TestEmployeeManager, P_TestConnection)
{
    MockDatabaseConnection dbConnection("dummy connection");
    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());
    EmployeeManager employeeManager(&dbConnection);
}

TEST(TestEmployeeManager, P_TestUpdateSalary)
{
    MockDatabaseConnection dbConnection("dummy connection");
    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());
    EXPECT_CALL(dbConnection,updateSalary(50,6000)).Times(1);
    EmployeeManager employeeManager(&dbConnection);
    employeeManager.setSalary(50,6000);

}

TEST(TestEmployeeManager, F_TestUpdateSalary10)
{
    MockDatabaseConnection dbConnection("dummy connection");
    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());
    EXPECT_CALL(dbConnection,updateSalary(50,6000)).Times(10);
    EmployeeManager employeeManager(&dbConnection);
    employeeManager.setSalary(50,6000);

}

TEST(TestEmployeeManager, F_TestUpdateSalary_600)
{
    MockDatabaseConnection dbConnection("dummy connection");
    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());
    EXPECT_CALL(dbConnection,updateSalary(50,600)).Times(1);
    EmployeeManager employeeManager(&dbConnection);
    employeeManager.setSalary(50,6000);

}

TEST(TestEmployeeManager, P_TestUpdateSalary_DontCareValues)
{
    MockDatabaseConnection dbConnection("dummy connection");
    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());
    EXPECT_CALL(dbConnection,updateSalary(testing::_,testing::_)).Times(1);
    EmployeeManager employeeManager(&dbConnection);
    employeeManager.setSalary(50,6000);

}

TEST(TestEmployeeManager, P_TestGetSalary)
{
    const int employeeID = 50;
    const float salary = 6100;
    MockDatabaseConnection dbConnection("dummy connection");
    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());
    EXPECT_CALL(dbConnection,getSalary(testing::_)).Times(1).WillOnce(testing::Return(salary));
    //EXPECT_CALL(dbConnection,getSalary(testing::_)).WillOnce(testing::Return(salary));
    //EXPECT_CALL(dbConnection,getSalary(4)).WillOnce(testing::Return(4800));
    EmployeeManager employeeManager(&dbConnection);
    float returnedSalary = employeeManager.getSalary(employeeID);

    ASSERT_EQ(salary,returnedSalary);

}

//With out Actions
TEST(TestEmployeeManager, P_TestConnectionError)
{
    MockDatabaseConnection dbConnection("Dummy address");
    EXPECT_CALL(dbConnection,connect()).WillOnce(testing::Throw(std::runtime_error("Dummy Error")));
    //EXPECT_CALL(dbConnection,connect());

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);

}

//With Actions

ACTION(ErrThrow)
{
    std::cout<< "Throwing an error\n";
    throw std::runtime_error("Dummy error");

}
TEST(TestEmployeeManager, P_TestConnectionErrorAction)
{
    MockDatabaseConnection dbConnection("Dummy address");
    EXPECT_CALL(dbConnection,connect()).WillOnce(ErrThrow());
    //EXPECT_CALL(dbConnection,connect());

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);

}

//With Invoke
void someFreeFunction()
{
    std::cout << "Free function \n";
    throw std::runtime_error("Dummy error");
}

TEST(TestEmployeeManager, P_TestConnectionErrorInvoke)
{
    MockDatabaseConnection dbConnection("Dummy address");
    EXPECT_CALL(dbConnection,connect()).WillOnce(testing::Invoke(someFreeFunction));
    //EXPECT_CALL(dbConnection,connect());

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);

}

//With Invoke lamda function

TEST(TestEmployeeManager, P_TestConnectionErrorInvoke_Lambda)
{
    MockDatabaseConnection dbConnection("Dummy address");
    EXPECT_CALL(dbConnection,connect()).WillOnce(testing::Invoke(
        [](){
                    std::cout << "Lambda function called \n";
                    throw std::runtime_error("Dummy error");
        }
    ));
    //EXPECT_CALL(dbConnection,connect());

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);

}

//Invoke with member function
//We need to bind the function as done below avoid compilation error.
TEST(TestEmployeeManager, P_TestConnectionErrorInvoke_MemberFunctionNoArg)
{
    MockDatabaseConnection dbConnection("Dummy address");
    auto boundMethod = std::bind(&MockDatabaseConnection::someMemberMethod, &dbConnection);

    EXPECT_CALL(dbConnection,connect()).WillOnce(testing::InvokeWithoutArgs(boundMethod));
    //EXPECT_CALL(dbConnection,connect());

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);

}
//Invoke with member method with argument
//We need to bind the function as done below avoid compilation error.
TEST(TestEmployeeManager, P_TestConnectionErrorInvoke_MemberFunctionWithArg)
{
    MockDatabaseConnection dbConnection("Dummy address");
    auto boundMethod = std::bind(&MockDatabaseConnection::someMemberMethodArg, &dbConnection,"param to method");

    EXPECT_CALL(dbConnection,connect()).WillOnce(testing::InvokeWithoutArgs(boundMethod));
    //EXPECT_CALL(dbConnection,connect());

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);

}




// TEST using MATCHERS //////////////
TEST(TestEmployeeManager, P_TestGetSalaryInRange)
{
    const int low = 5000, high = 8000;
    std::vector<Employee> returnedVector{Employee{1,5000,"John"},
                                        Employee{2,7000,"Jane"},
                                        Employee{3,6000,"Jenny"}};
    MockDatabaseConnection dbConnection("dummy connection");
    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());
    EXPECT_CALL(dbConnection,getSalariesRange(low,high)).WillOnce(testing::Return(returnedVector));

    EmployeeManager employeeManager(&dbConnection);
    
    std::map<std::string, float> returnedMap = employeeManager.getSalariesBetween(low,high);

    for(auto it = returnedMap.begin(); it != returnedMap.end(); ++it)
    {
        std::cout << it->first << " " << it ->second <<'\n';
        //ASSERT_THAT(it->second,testing::Gt(low));
        //ASSERT_THAT(it->second,testing::AllOf(testing::Ge(low),testing::Lt(high-3000)));
        ASSERT_THAT(it->second,testing::AnyOf(testing::Ge(low),testing::Lt(high-3000)));
    }

}

int main(int argc, char **argv)
{
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}

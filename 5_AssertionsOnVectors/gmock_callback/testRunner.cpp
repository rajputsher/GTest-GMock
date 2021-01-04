#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <map>
#include <functional>
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

void realCallback(){
    std::cout<<"Real callback invoked\n";
}

TEST(TestEmployeeManager, CallbackTestMock)
{
    MockDatabaseConnection dbConnection("Dummy connection");
    testing::MockFunction<void(int,int)> mockFunction;
    dbConnection.setOnConnect(mockFunction.AsStdFunction());
    //EXPECT_CALL(mockFunction,Call(testing::_,testing::_));
    EXPECT_CALL(mockFunction,Call(5,6));
    dbConnection.connect();

}

int main(int argc, char **argv)
{
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}

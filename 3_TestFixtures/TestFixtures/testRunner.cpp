#include <iostream>
#include <stdexcept>
#include <gtest/gtest.h>
#include "LibraryCode.hpp"
#include <gmock/gmock.h>


TEST(AccountTest,TestEmptyAccount)
{
    //Arrange
    Account account;

    //Act
    double balance = account.getBalance();

    //Assert
    ASSERT_EQ(0,balance); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST(AccountTest,TestDeposit)
{
    //Arrange
    Account account;

    //Act
    account.deposit(10.5);

    //Assert
    ASSERT_EQ(10.5,account.getBalance()); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST(AccountTest,TestWithdrawOK)
{
    //Arrange
    Account account;

    //Act 
    account.deposit(10.5);
    account.withdraw(3);

    //Assert
    ASSERT_EQ(7.5,account.getBalance()); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST(AccountTest,TestWithInsufficientFunds)
{
    //Arrange
    Account account;

    //Act 
    account.deposit(10.5);

    //Assert
    ASSERT_THROW(account.withdraw(30),std::runtime_error);
}

TEST(AccountTest,TestTransferOK)
{
    //Arrange
    Account account;
    account.deposit(10.5);

    Account to;

    //Act 
    account.transfer(to,2);

    //Assert
    ASSERT_EQ(8.5,account.getBalance()); //ASSERT_EQ(Expected value, Test Ouput)
    ASSERT_EQ(2,to.getBalance());
}

TEST(AccountTest,TestTransferInsufficientFunds)
{
    //Arrange
    Account account;
    account.deposit(10.5);

    Account to;

    //Act 
    //Assert
    ASSERT_THROW(account.transfer(to,40),std::runtime_error);
}

// For all the test above it can be seen that the first few lines are 
//always same, here we can make use of a test fixture
// We can create a class by extending the class from testing::Test

class AccountTestFixture: public testing::Test
{
    public:
        AccountTestFixture(); //class constructor
        virtual ~AccountTestFixture(); //class destructor
        void SetUp() override;
        void TearDown() override;
        static void SetUpTestCase();
        static void TearDownTestCase();
    protected:
        Account account;
};

AccountTestFixture::AccountTestFixture()
{
    std::cout<<"Constructor called\n";
}

AccountTestFixture::~AccountTestFixture()
{
    std::cout<<"Destructor called\n";
}

void AccountTestFixture::SetUpTestCase()
{
    std::cout<<"SetUpTestCase called\n";
}

void AccountTestFixture::TearDownTestCase()
{
    std::cout<<"TearDownTestCase called\n";
}

void AccountTestFixture::SetUp()
{
    // Code here will be called immediately after the constructor (right
    // before each test).
    std::cout<<"SetUp called\n";
    account.deposit(10.5);
}

void AccountTestFixture::TearDown()
{
    // Code here will be called immediately after each test (right
    // before the destructor).
    std::cout<<"TearDown called\n";
}

//Now modifying the first test i.e TestDepsoit
/*
TEST(AccountTest,TestDeposit)
{
    //Arrange
    Account account;

    //Act
    account.deposit(10.5);

    //Assert
    ASSERT_EQ(10.5,account.getBalance()); //ASSERT_EQ(Expected value, Test Ouput)
}
*/
TEST_F(AccountTestFixture,TestDeposit)
{
    std::cout<<"Test body\n";
    //Assert
    ASSERT_EQ(10.5,account.getBalance()); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST_F(AccountTestFixture,TestWithdrawOK)
{
    //Act 
    account.withdraw(3);

    //Assert
    ASSERT_EQ(7.5,account.getBalance()); //ASSERT_EQ(Expected value, Test Ouput)
}

TEST_F(AccountTestFixture,TestWithInsufficientFunds)
{
    //Assert
    ASSERT_THROW(account.withdraw(30),std::runtime_error);
}

TEST_F(AccountTestFixture,TestTransferOK)
{
    Account to;

    //Act 
    account.transfer(to,2);

    //Assert
    ASSERT_EQ(8.5,account.getBalance()); //ASSERT_EQ(Expected value, Test Ouput)
    ASSERT_EQ(2,to.getBalance());
}

TEST_F(AccountTestFixture,TestTransferInsufficientFunds)
{
    Account to;

    //Act 
    //Assert
    ASSERT_THROW(account.transfer(to,40),std::runtime_error);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
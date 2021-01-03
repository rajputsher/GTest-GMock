#include "LibraryCode.hpp"
#include <stdexcept>

Account::Account(): nBalance(0)
{

}

void Account::deposit(double sum)
{
    nBalance += sum;
}

void Account::withdraw(double sum)
{
    if(nBalance < sum)
    {
        throw std::runtime_error("Insufficient funds");
    }
    nBalance -= sum;
}

double Account::getBalance() const
{
    return nBalance;
}

void Account::transfer(Account &to, double sum){
    withdraw(sum);//will thrown an error for insufficient funds
    to.deposit(sum);
}
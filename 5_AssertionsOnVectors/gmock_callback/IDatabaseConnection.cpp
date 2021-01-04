#include "IDatabaseConnection.hpp"
#include <iostream>
#include <functional>

IDatabaseConnection::IDatabaseConnection(std::string serverAddress) : mServerAddress{serverAddress}
{
}


void IDatabaseConnection::connect()
{
  std::cout << "Connecting to database server " << mServerAddress << "\n";
  //initialize real DB connection

  if(mOnConnect != nullptr)
  {
    std::cout << "Callback was set\n";
    mOnConnect(5,6);
  }
}

void IDatabaseConnection::disconnect()
{
 std::cout << "Disconnecting from database\n";
 //close the real connection
}

void IDatabaseConnection::setOnConnect(Callback onConnect)
{
  mOnConnect = onConnect;
}
#include "transaction_manager.h"
#include <sstream>  // For std::stringstream
#include <iostream> // For std::endl


void TransactionManager::addTransaction(int ID, Transaction tran)
{
  transactions[ID].push_back(tran);
}

std::string TransactionManager::printTransaction(int ID)
{
  std::stringstream ss;
  if (transactions.find(ID) != transactions.end())
  {
    for (auto &tran : transactions[ID])
    {
      ss << tran.Output() << std::endl; // std::endl to specify namespace
    }
  }
  return ss.str();
}
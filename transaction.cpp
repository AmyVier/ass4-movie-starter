#include "transaction.h"
#include <sstream>

Transaction::Transaction(std::string action, int ID, std::string movieType, Movie *movie) : action(action), CustomerID(ID), type(movieType), movie(movie) {} // Assuming movie should be a pointer

std::string Transaction::Output()
{
  std::stringstream ss;
  ss << "Action: " << action << ", CustomerID: " << CustomerID << ", Movie Type: " << type;
  return ss.str();
}

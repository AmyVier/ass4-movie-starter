
#include "transaction.h"
#include <sstream>

Transaction::Transaction(std::string action, int ID, std::string movieType,
                         string info)
    : action(action), CustomerID(ID), type(movieType), movieInfo(info){};

// invalid/empty transaction
Transaction::Transaction() {
  action = "";
  CustomerID = -1;
  type = "";
}

std::string Transaction::Output() {
  std::stringstream ss;
  // Action: action, CustomerID: ID, MovieType: type, movieInfo
  ss << "Action: " << action << ", CustomerID: " << CustomerID
     << ", Movie Type: " << type << ", " << movieInfo;
  return ss.str();
}

int Transaction::getID() { return CustomerID; }
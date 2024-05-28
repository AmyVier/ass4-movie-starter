/**
 *  transaction class - class used to manage and store transaction data
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 * 
 * stores and returns string of details of the transaction
 *
 * Every transaction should have a customer and a valid transaction that has
 * taken place.
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "movie.h"
#include <string>

using namespace std;

class Transaction {
public:

// constructor
  Transaction();
  Transaction(string action, int ID, string movieType, string info);

  // returns string of details of the transaction
  string Output();
  int getID();

private:
  string action;
  int CustomerID;
  string type;
  string movieInfo;
};

#endif // !TRANSACTION_H
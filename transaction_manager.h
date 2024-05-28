/**
 *  transaction manager class - class used to manage and store transactions
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 * adds transaction to map and prints transactions of a customer
 *
 * A transaction should have a customer and a valid transaction that has taken
 * place.
 */

#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

#include "transaction.h"
#include <map>
#include <vector>

using namespace std;

class TransactionManager {
public:
  // constructor
  TransactionManager() = default;

  // add transaction
  void addTransaction(int ID, Transaction tran);

  // print transaction of customer
  string printTransaction(int ID);

private:
  map<int, vector<Transaction>> transactions;
};
#endif // !TRANSACTION_MANAGER_H

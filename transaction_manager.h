#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

#include <map>
#include "transaction.h"
#include <vector>

using namespace std;

class TransactionManager {
public:
	void addTransaction(int ID, Transaction tran);
	string printTransaction(int ID);
private:
	map<int, vector<Transaction>> transactions;
};
#endif // !TRANSACTION_MANAGER_H


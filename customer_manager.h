#ifndef CUSTOMER_MANAGER_H
#DEFINE CUSTOMER_MANAGER_H

#include "Customer.h"
#include "hashtable.h"
#include <map>

using namespace std;

class CustomerManager {
public:
	CustomerManager();
	~CustomerManager();
	bool isValid(int ID);
	Customer getCustomer(int ID);
	bool addCustomer(int id, string firstname, string lastname);


private:
	HashTable* CustomerList = new HashTable();


};
#endif

#ifndef CUSTOMER_MANAGER_H
#DEFINE CUSTOMER_MANAGER_H

#include "Customer.h"
#include <map>

using namespace std;

class CustomerManager {
public:
	CustomerManager();
	bool isValid(int ID);
	Customer getCustomer(int ID);


private:
	map<int, Customer> customers;
};
#endif

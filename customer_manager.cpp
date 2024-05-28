#include "customer.h"
#include "hashtable.h"
#include "customer_manager.h"

CustomerManager::CustomerManager() = default;

//Need to check if sufficiently detected, likely to cause memory leaks.
CustomerManager::~CustomerManager() {
	delete CustomerList;
}


bool CustomerManager::isValid(int ID) {
	if (!CustomerList->isExist(ID)) {
		return false;
	}
	return true;
}

//if not found, return nullptr;
Customer CustomerManager::getCustomer(int ID) {
	return CustomerList->get(ID);
}

//using hash function:
bool CustomerManager::addCustomer(int id, string firstname, string lastname) {
	//if (CustomerList->get(id).getID() != id) {
		Customer c = Customer(id, firstname, lastname);
		CustomerList->insert(id, c);
		return true;
	//}
	//return false;
}
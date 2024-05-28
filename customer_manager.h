/**
 *  customer manager class - class used to manage customers
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 * The customer manager can add customers and get customers.
 *
 * Every customer has a non negative unique ID, a first name, and a last name
 */

#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include "customer.h"
#include "hashtable.h"
#include <map>

using namespace std;

class CustomerManager {
public:
  // constructor
  CustomerManager();

  // destructor
  ~CustomerManager();

  // if ID is valid
  bool isValid(int ID);

  // get customer from ID
  Customer getCustomer(int ID);

  // add new customer
  bool addCustomer(int id, string firstname, string lastname);

private:
  // list of customers
  HashTable *CustomerList = new HashTable();
};
#endif
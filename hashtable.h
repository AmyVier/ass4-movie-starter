/**
 *  hashtable class -  class used to manage how customers are stored with hashes
 *
 * Provides hash table for customers
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 * Every customer has a non negative unique ID
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h"
#include <list>

using namespace std;

class HashTable {
private:
  struct CustomerProfile {
    int id;
    Customer customerLink;
    CustomerProfile *next;
    CustomerProfile() : id(0), customerLink(), next(nullptr){};
  };
  static const int TABLE_SIZE = 12;
  CustomerProfile *table[TABLE_SIZE];

public:
  // Constructor & Destructor
  HashTable();
  ~HashTable();

  // Hash function
  static int hashFunction(int key);

  // Inserting new customer
  void insert(int id, Customer customer);

  // Getting customer with id as key
  Customer get(int key);
  bool isExist(int key);
};
#endif
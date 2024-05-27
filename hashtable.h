#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h"
#include <list>

using namespace std;

class HashTable
{
private:
  struct CustomerProfile
  {
    int id;
    Customer customerLink;
    CustomerProfile *next;
    CustomerProfile() : id(0), customerLink(), next(nullptr){};
    // ~CustomerProfile() :
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
  Customer *get(int key);
};
#endif
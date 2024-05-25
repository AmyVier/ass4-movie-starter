#include "hashtable.h"
#include "Customer.h"
#include <vector>

// Default Class constructor
HashTable::HashTable() {
  for (size_t i = 0; i < TABLE_SIZE; i++) {
    table[i] = new CustomerProfile();
    table[i]->id = 0;
  }
}

// Class destructor
HashTable::~HashTable() {
  for (int i = 0; i < TABLE_SIZE; ++i) {
    CustomerProfile *p = table[i];
    while (p != nullptr) {
      CustomerProfile *temp = p;
      p = p->next;
      delete temp; // Free memory for each node
    }
    table[i] = nullptr;
  }
}

// Hash function
int HashTable::hashFunction(int key) { return key % TABLE_SIZE; }

// Insert new customer
void HashTable::insert(int id, Customer customer) {
  int index = hashFunction(id);

  if (table[index]->id == 0) {
    table[index]->id = id;
    table[index]->customerLink = customer;
  } else {
    CustomerProfile *p = table[index];
    CustomerProfile *n = new CustomerProfile();
    n->customerLink = customer;
    n->id = id;

    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = n;
  }
}

// get customer with id as key
Customer HashTable::get(int key) {
  int index = hashFunction(key);
  CustomerProfile *p = table[index];
  while (p != nullptr) {
    if (p->id == key) {
      return p->customerLink;
    }
    p = p->next;
  }
  Customer nul;
  return nullptr;
}

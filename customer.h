/**
 *  customer manager class - class used to store and manage customer data
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 * The customer stores first name, last name and ID. It can also give all of its
 * information
 *
 * Every customer has a non negative unique ID, a first name, and a last name
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
public:
  // constructors
  Customer() = default;
  Customer(int id, string firstname, string lastname);

  // get ID
  int getID() const;

  // get first name
  string getFirstName() const;

  // get last name
  string getLastName() const;

  // get all information
  string getAllInfo() const;

private:
  int ID;
  string firstName;
  string lastName;
};
#endif
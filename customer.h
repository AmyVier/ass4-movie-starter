#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
public:
	Customer() = default;
	Customer(int id, string firstname, string lastname);
	int getID() const;
	string getFirstName() const;
	string getLastName() const;
	string getAllInfo() const;

private:
	int ID;
	string firstName;
	string lastName;
};
#endif
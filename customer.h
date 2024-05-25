#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
public:
	Customer(int id, string firstname, string lastname);
	int getID();
	string getFirstName();
	string getLastName();
	string getAllInfo();

private:
	int ID;
	string firstName;
	string lastName;
};
#endif
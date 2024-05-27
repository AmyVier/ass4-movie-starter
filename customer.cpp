#include <string>
#include "customer.h"

// customer constructor with information provided
Customer::Customer(int id, string firstname, string lastname) :ID(id), firstName(firstname), lastName(lastname) {}

int Customer::getID() const {
	return ID;
}

string Customer::getFirstName() const {
	return firstName;
}

string Customer::getLastName() const {
	return lastName;
}

// output format may need to adjust as needed.
string Customer::getAllInfo() const {
	return getID + " " + getFirstName() + " " + getLastName();
}

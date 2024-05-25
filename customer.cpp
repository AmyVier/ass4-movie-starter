#include <string>
#include "customer.h"

// customer constructor with information provided
Customer::Customer(int id, string firstname, string lastname) {
	this->ID = id;
	firstName = firstname;
	lastName = lastname;
}

int Customer::getID()
{
	return ID;
}

string Customer::getFirstName()
{
	return firstName;
}

string Customer::getLastName()
{
	return lastName;
}

// output format may need to adjust as needed.
string Customer::getAllInfo()
{
	return getID + " " + getFirstName() + " " + getLastName();
}

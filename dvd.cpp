#include "dvd.h"

// constructor with stock provided
DVD::DVD(int stock)
{
	stock = stock;
}

// add additional stock, might be proposed for other usage but keep it this way for now.
bool DVD::addTostock(int stk)
{
	stock += stk;
	return true;
}

// determine whether is in stock
bool DVD::isInStock()
{
	return (stock != 0);
}

// deduct 1 stock item.
bool DVD::checkOut()
{
	if (stock == 0)
		return false;
	stock--;
	return true;
}

// increase 1 stock item.
bool DVD::returnMovie()
{
	stock++;
	return true;
}

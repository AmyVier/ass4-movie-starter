#include "dvd.h"
#include <iostream>

//constructor with stock provided
DVD::DVD(int stock)
{
	this->stock = stock;
	borrowed = 0;
}

DVD::~DVD(){
	delete this;
}

// add additional stock, might be proposed for other usage but keep it this way for now.
bool DVD::addTostock(int stk)
{
	stock += stk;
	return true;
}

// determine whether is in stock
bool DVD::isInStock() const
{
	return (stock >= borrowed);
}

// deduct 1 stock item.
bool DVD::checkOut()
{
	if (borrowed >= stock) return false;
	borrowed++;
	return true;
}

// increase 1 stock item.
bool DVD::returnMovie()
{
	if(borrowed <= 0) return false;
	borrowed--;
	return true;
}

int DVD::getBorrowed(){
	return borrowed;
}

int DVD::getRemained(){
	return stock - borrowed;
}
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "movie.h"

using namespace std;

class Transaction
{
public:
	Transaction();
	Transaction(string action, int ID, string movieType, string info);
	string Output();
	int getID();

private:
	string action;
	int CustomerID;
	string type;
	string movieInfo;
};

#endif // !TRANSACTION_H
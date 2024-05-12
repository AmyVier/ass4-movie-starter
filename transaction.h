#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "movie.h"

using namespace std;

class Transaction {
public:
	Transaction(string action, int ID, string movieType, Movie movie);
	string Output();

private:
	string action;
	int CustomerID;
	string type;
	Movie movie;

};
#endif // !TRANSACTION_H


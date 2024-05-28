#ifndef MOVIE_STORE_H
#define MOVIE_STORE_H
#include "inventory.h"
#include "customer_manager.h"
#include "transaction_manager.h"
#include <string>

using namespace std;
const char MEDIA_TYPE = 'D';

class MovieStore
{
public:
	MovieStore();
	~MovieStore();
	void readMovie(string filename);
	void readCustomer(string filename);
	void readCommand(string filname);

private:
	Inventory *inventory; // Declaration for inventory.
	CustomerManager *customerManager;
	TransactionManager *transactionManager;
	bool Borrow();	// Will need further implementation in the parameter
	bool Return();	// Will need further implementation in the parameter
	bool History(); // Will need further implementation in the parameter
	bool getInventory();
};

#endif // !MOVIE_STORE_H
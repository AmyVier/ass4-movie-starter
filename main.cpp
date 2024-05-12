/*------------Movie Project-----------------
* -- This is the main.cpp file for the Movie Project Program
* Authors: Chris Chen, Amy Vier.
* 
* Assumption to be made:
* -- data files are hardcoded as "data4movies.txt", "data4customers.txt", and "data4command.txt"
* 
* 
*/

#include <iostream>
#include "movie_store.h"

using namespace std;

public int main() {
	MovieStore store = MovieStore();

	store.readMovie("data4movies.txt");
	store.readCustomer("data4customer.txt");
	store.readCommand("data4command.txt");

	return 0;
};
#ifndef MOVIE_STORE_H
#DEFINE MOVIE_STORE_H

#include <string>

using namespace std;

class MovieStore {
public:
	MovieStore();
	void readMovie(string filename);
	void readCustomer(string filename);
	void readCommand(string filname);

private:
	bool Borrow(); //Will need further implementation in the parameter
	bool Return(); //Will need further implementation in the parameter
	void Inventory();
	bool History(); //Will need further implementation in the parameter
};

#endif // !MOVIE_STORE_H


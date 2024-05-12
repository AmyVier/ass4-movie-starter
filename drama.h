#ifndef DRAMA_H
#define DRAMA_H

#include <string>
#include "movie.h"
#include "media.h"
#include "dvd.h"
#include <map>

using namespace std;

class Drama {
public:
	void addToStock();
	string Output();
	bool isInStock();
	bool checkOut();
	bool Return();

private:
	string director;
	string title;
	int releaseYear;
	map<char, Media> stock;
};

#endif // 


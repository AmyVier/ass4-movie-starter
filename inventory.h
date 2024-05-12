#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include "movie.h"
#include "comedy.h"
#include "classics.h"
#include "drama.h"
#include "media";
#include <vector>

using namespace std;

class Inventory {
public:
	bool AddMovie(string type, movie m);
	bool FindMovie(string type, string title);
	bool addToStock(string type, movie m, Media mediaType, int stock);
	void Sort(string movieType);
	void printInventory();

private:
	vector<Comedy> comedyMovies;
	vector<Classics> classicsMovies;
	vector<Drama> dramaMovies;

};
#endif // !INVENTORY_H


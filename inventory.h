/**
 *  Inventory class. Stores movies
 *
 * @author Kyle Ricks
 * @date 25 May 2024
 *
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include "movie.h"
#include "comedy.h"
#include "classics.h"
#include "drama.h"
#include "media.h"
#include <vector>

using namespace std;

class Inventory
{
public:
   Inventory();
   bool AddMovie(string type, Movie *m); // Change to pointer to handle polymorphism correctly.
   bool FindMovie(string type, string title);
   bool addToStock(string type, Movie *m, Media *mediaType, int stock); // Use pointer for Media too.
   void Sort(string movieType);
   void printInventory();

private:
   map<std::string, std::vector<Movie *>> inventory_;
   using KeyValuePair = std::pair<std::string, std::vector<Movie *>>;
   void PrintHelper(const std::string &type) const;
};
#endif // INVENTORY_H

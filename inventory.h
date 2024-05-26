/**
 *  Inventory class. Stores movies
 *
 * @author Kyle Ricks
 * @date 25 May 2024
 *
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
#include <utility>
#include <vector>
#include "movie.h"

class Inventory {
 public:
    // Default constructor
    Inventory();

    bool AddMovie(const std::string& type, Movie* movie);
    bool FindMovie(const std::string& type, const std::string& title);
    // Unsure what method does. Will implement later
    bool addToStock(std::string type, Movie* movie, Media mediaType, int stock);
    void PrintInventory() const;

 private:
    map<std::string, std::vector<Movie*>> inventory_;
    using KeyValuePair = std::pair<std::string, std::vector<Movie*>>;
    void PrintHelper(const std::string& type) const;
};
#endif  // INVENTORY_H

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
    // Adds movie to inventory using type as identifier
    bool AddMovie(const std::string& type, Movie* movie);
    // Finds movie from type and title. Should this return a movie?
    bool FindMovie(const std::string& type, const std::string& title);
    //Unsure how to incorporate Media here
    bool addToStock(const std::string& type, Movie* movie, Media mediaType,
                    int stock);
    void PrintInventory() const;

 private:
    std::map<std::string, std::vector<Movie*>> inventory_;
    using KeyValuePair = std::pair<std::string, std::vector<Movie*>>;
    void PrintHelper(const std::string& type) const;
};
#endif  // INVENTORY_H

#include "inventory.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include "movie.h"

Inventory::Inventory() {
    inventory_.insert(KeyValuePair("F", std::vector<Movie*>()));
    inventory_.insert(KeyValuePair("D", std::vector<Movie*>()));
    inventory_.insert(KeyValuePair("C", std::vector<Movie*>()));
}

bool Inventory::AddMovie(const std::string& type, Movie* movie) {
    if (inventory_.find(type) != inventory_.end()) {
        inventory_.find(type)->second.push_back(movie);
        std::sort(inventory_.find(type)->second.begin(),
                  inventory_.find(type)->second.end());
        return true;
    }
    return false;
}

bool Inventory::FindMovie(const std::string& type, const std::string& title) {
    if (inventory_.find(type) != inventory_.end()) {
        for (Movie* temp : inventory_.find(type)->second) {
            if (temp->getTitle() == title) {
                return true;
            }
        }
    }
    return false;
}

bool Inventory::addToStock(const std::string& type, const Movie* movie,
                           const int& stock) {
    if (inventory_.find(type) != inventory_.end()) {
        for (Movie* temp : inventory_.find(type)->second) {
            if (temp == movie) {
                temp->addTostock('D', stock);
                return true;
            }
        }
    }
    return false;
}

void Inventory::PrintInventory() const {
    PrintHelper("F");
    PrintHelper("D");
    PrintHelper("C");
}

void Inventory::PrintHelper(const std::string& type) const {
    for (const Movie* movie : inventory_.find(type)->second) {
        std::cout << *(movie) << "\n";
    }
}

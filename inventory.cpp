#include "inventory.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include "movie.h"

Inventory::Inventory()
{
    inventory_.insert(KeyValuePair("F", std::vector<Movie *>()));
    inventory_.insert(KeyValuePair("D", std::vector<Movie *>()));
    inventory_.insert(KeyValuePair("C", std::vector<Movie *>()));
}

bool Inventory::AddMovie(const std::string &type, Movie *movie)
{
    if (inventory_.find(type) != inventory_.end())
    {
        std::vector<Movie *> temp_vector = inventory_.find(type)->second;
        temp_vector.push_back(movie);
        std::sort(temp_vector.begin(), temp_vector.end());
        return true;
    }
    return false;
}

bool Inventory::FindMovie(const std::string &type, const std::string &title)
{
    if (inventory_.find(type) != inventory_.end())
    {
        const std::vector<Movie *> temp_vector = inventory_.find(type)->second;
        for (Movie *temp : temp_vector)
        {
            if (temp->getTitle() == title)
            {
                return true;
            }
        }
    }
    return false;
}

bool Inventory::addToStock(const std::string &type, Movie *movie,
                           Media mediaType, int stock)
{
    if (inventory_.find(type) != inventory_.end())
    {
        const std::vector<Movie *> temp_vector = inventory_.find(type)->second;
        for (Movie *temp : temp_vector)
        {
            if (temp == movie)
            {
                temp->addTostock('D', stock);
                return true;
            }
        }
    }
    return false;
}

void Inventory::PrintInventory() const
{
    PrintHelper("F");
    PrintHelper("D");
    PrintHelper("C");
}

void Inventory::PrintHelper(const std::string &type) const
{
    const std::vector<Movie *> temp_vector = inventory_.find(type)->second;
    for (Movie *movie : temp_vector)
    {
        std::cout << *(movie) << "\n";
    }
}

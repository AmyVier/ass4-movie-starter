#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
#include <utility>
#include <vector>
#include "movie.h"
#include "transaction.h"

class Inventory {
 public:
    // Default constructor
    Inventory();
    // Adds movie to inventory using type as identifier
    bool AddMovie(const std::string& type, Movie movie);
    // Finds movie from type and title. Should this return a movie?
    bool FindMovie(const std::string& type, const std::string& title);

    Transaction Borrow(const std::string& type, const std::string& title, const int& id);
    Transaction BorrowClassics(const std::string& actor, const int& id);

    Transaction Return(const std::string& type, const std::string& title, const int& id);
    Transaction ReturnClassics(const std::string& actor, const int& id);
    //Unsure how to incorporate Media here
    bool addToStock(const std::string& type, Movie movie,
                    const int& stock);
    void PrintInventory() const;

    void sort(std::vector<Movie*>& v);

    void sortClassics(std::vector<Movie*>& v);

 private:
    std::map<std::string, std::vector<Movie>> inventory_;
    using KeyValuePair = std::pair<std::string, std::vector<Movie*>>;
    void PrintHelper(const std::string& type) const;
};
#endif  // INVENTORY_H
/**
 *  inventory class -  class used to manage and store movies
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 * the inventory adds, finds, borrows, returns movies and adds media to stock,
 * sorts movies.
 *
 * A movie has a director, title, release year, and stocks pertaining to their
 * media types. A movie has at lease one media type (DVD, blue-ray, etc.) with a
 * corrosponding stock. Every movie has a type. Every type of movie has a
 * diffrent character.
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "movie.h"
#include "transaction.h"
#include <map>
#include <string>
#include <utility>
#include <vector>

class Inventory {
public:
  // Default constructor
  Inventory();
  // Adds movie to inventory using type as identifier
  bool AddMovie(const std::string &type, Movie movie);
  // Finds movie from type and title.
  bool FindMovie(const std::string &type, const std::string &title);

  // borrow
  Transaction Borrow(const std::string &type, const std::string &title,
                     const int &id);
  // borrow classic
  Transaction BorrowClassics(const std::string &actor, const int &id);

  // return
  Transaction Return(const std::string &type, const std::string &title,
                     const int &id);

  // return classic
  Transaction ReturnClassics(const std::string &actor, const int &id);

  // add to stock
  bool addToStock(const std::string &type, Movie movie, const int &stock);

  // print inventory
  void PrintInventory() const;

  void sort(std::vector<Movie *> &v);

  void sortClassics(std::vector<Movie *> &v);

private:
  std::map<std::string, std::vector<Movie>> inventory_;
  using KeyValuePair =
      std::pair<std::string, std::vector<Movie *>>; // all movies
  void PrintHelper(const std::string &type) const;  // print helper
};
#endif // INVENTORY_H
#include "inventory.h"
#include "movie.h"
#include "transaction.h"
#include "transaction_manager.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

Inventory::Inventory() {
  inventory_.insert(make_pair("F", std::vector<Movie>()));
  inventory_.insert(make_pair("D", std::vector<Movie>()));
  inventory_.insert(make_pair("C", std::vector<Movie>()));
}

bool Inventory::AddMovie(const std::string &type, Movie movie) {
  // if found, add movie
  if (inventory_.find(type) != inventory_.end()) {
    auto &inventory = inventory_.find(type)->second;
    inventory.push_back(movie);
    if (type == "C") {
      // sortClassics(inventory);
    } else {
      // sort(inventory);
    }
    return true;
  }
  return false;
}

bool Inventory::FindMovie(const std::string &type, const std::string &title) {
  auto &inventory = inventory_.find(type)->second;
  for (auto temp : inventory) {
    if (temp.getTitle() == title) {
      return true;
    }
  }
  return false;
}

Transaction Inventory::Borrow(const std::string &type, const std::string &title,
                              const int &id) {
  // if inventory has the movie type section
  if (inventory_.find(type) != inventory_.end()) {
    auto &inventory = inventory_.find(type)->second;
    // if found, borrow
    for (auto temp : inventory) {
      if (temp.getTitle() == title) {
        temp.checkOut('D');
        string info = temp.getTitle() + ", " + to_string(temp.getYear());
        Transaction t = Transaction("B", id, type, info);
        return t;
      }
    }
  }
  Transaction t = Transaction();
  return t;
}

Transaction Inventory::BorrowClassics(const std::string &actor, const int &id) {
  // if inventory has comedy section
  if (inventory_.find("C") != inventory_.end()) {
    auto &inventory = inventory_.find("C")->second;

    // if found, borrow
    for (auto temp : inventory) {
      if (temp.getActor() == actor) {
        temp.checkOut('D');
        string info = temp.getTitle() + ", " + temp.getActor() + ", " +
                      to_string(temp.getYear());
        Transaction t = Transaction("B", id, "C", info);
        return t;
      }
    }
  }
  Transaction t = Transaction();
  return t;
}

Transaction Inventory::Return(const std::string &type, const std::string &title,
                              const int &id) {
  // if inventory has the movie type section
  if (inventory_.find(type) != inventory_.end()) {
    auto &inventory = inventory_.find(type)->second;

    // if found, retunr
    for (auto temp : inventory) {
      if (temp.getTitle() == title) {
        temp.returnMovie('D');
        string info = temp.getTitle() + ", " + to_string(temp.getYear());
        Transaction t = Transaction("R", id, type, info);
        return t;
      }
    }
  }
  Transaction t = Transaction();
  return t;
}

Transaction Inventory::ReturnClassics(const std::string &actor, const int &id) {
  // if the inventory has comedy section
  if (inventory_.find("C") != inventory_.end()) {
    auto &inventory = inventory_.find("C")->second;
    // if found return
    for (auto temp : inventory) {
      if (temp.getActor() == actor) {
        temp.returnMovie('D');
        string info = temp.getTitle() + ", " + temp.getActor() + ", " +
                      to_string(temp.getYear());
        Transaction t = Transaction("R", id, "C", info);
        return t;
      }
    }
  }
  Transaction t = Transaction();
  return t;
}

bool Inventory::addToStock(const std::string &type, Movie movie,
                           const int &stock) {
  // if the inventory already has movie type and movie, add to stock
  if (inventory_.find(type) != inventory_.end()) {
    auto &inventory = inventory_.find(type)->second;
    for (Movie temp : inventory) {
      if (temp.getTitle() == movie.getTitle()) {
        temp.addTostock('D', stock);
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

void Inventory::PrintHelper(const std::string &type) const {
  auto &inventory = inventory_.find(type)->second;
  for (auto movie : inventory) {
    std::cout << movie << "\n";
  }
}

void Inventory::sort(std::vector<Movie *> &v) {
  if (v.empty())
    return;
  for (int i = 0; i < v.size() - 1; i++) {
    int index = i;
    for (int j = i; j < v.size(); j++) {
      // sort by title and then year
      if (v[j]->getTitle() < v[index]->getTitle() ||
          (v[j]->getTitle() == v[index]->getTitle() &&
           v[j]->getYear() < v[index]->getYear())) {
        index = j;
      }
    }
    auto temp = v[i];
    v[i] = v[index];
    v[index] = temp;
  }
}

void Inventory::sortClassics(std::vector<Movie *> &v) {
  if (v.empty())
    return;
  for (int i = 0; i < v.size() - 1; i++) {
    int index = i;
    // sort by date and then title
    for (int j = i; j < v.size(); j++) {
      if (v[j]->getYear() < v[index]->getYear() ||
          (v[j]->getTitle() < v[index]->getTitle() &&
           v[j]->getYear() == v[index]->getYear())) {
        index = j;
      }
    }
    auto temp = v[i];
    v[i] = v[index];
    v[index] = temp;
  }
}

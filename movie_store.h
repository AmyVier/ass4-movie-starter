/**
 *  Movie Store class - class used to create movies
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 * reads files to add customers and movies. Also reads file to follow commands.
 * Borrows/returns books, shows transaction history, and shows all inventory.
 *
 * A movie has a director, title, release year, and stocks pertaining to their
 * media types. A movie has at lease one media type (DVD, blue-ray, etc.) with a
 * corrosponding stock. Every movie line should be in organized based on the
 * movie type. Every customer line should be organized in: CustomerID LastName
 * FirstName. Every command should be formatted based on the command format.
 */

#ifndef MOVIE_STORE_H
#define MOVIE_STORE_H
#include "customer_manager.h"
#include "inventory.h"
#include "transaction_manager.h"
#include <string>

using namespace std;
const char MEDIA_TYPE = 'D';

class MovieStore {
public:
  // constructor
  MovieStore();

  // destructor
  ~MovieStore();

  // read movie file
  void readMovie(string filename);

  // read customer file
  void readCustomer(string filename);

  // read command file
  void readCommand(string filname);

private:
  Inventory *inventory;                   // Declaration for inventory.
  CustomerManager *customerManager;       // Declaration for customerManager.
  TransactionManager *transactionManager; // Declaration for transactionManager.

  // borrow
  bool Borrow();

  // return
  bool Return();

  // get history
  bool History();

  // get inventory
  bool getInventory();
};

#endif // !MOVIE_STORE_H
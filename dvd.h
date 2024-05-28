/**
 *  dvd class -  class used to store and manage the stock of a dvd type of a
 * movie
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 * The dvd can be checked out, returned, printed, have a media added to stock,
 * be checked whether it is in stock.
 *
 * A movie has at lease one media type (DVD, blue-ray, etc.) with a
 * corrosponding stock
 */

#ifndef DVD_H
#define DVD_H

#include "media.h"
#include <string>

using namespace std;

class DVD : public Media {
public:

  // destructor
  ~DVD();

  //constructor
  DVD(int stock);

  // add to stock
  bool addTostock(int stk);

  // whether it is in stock
  bool isInStock() const;

  // check out
  bool checkOut();

  // return 
  bool returnMovie();

  // borrow
  int getBorrowed();

  // get remaining stock
  int getRemained();

private:
  int stock; // stock
  int borrowed; // how many borrowed
};

#endif // DVD_H
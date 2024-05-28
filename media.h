/**
 *  media class - interface class used to store and manage the stock of a movie
 * type of a movie
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 * The media can be checked out, returned, printed, have a media added to
 * stock, be checked whether it is in stock.
 *
 * A movie has at lease one media type (DVD, blue-ray, etc.) with a
 * corrosponding stock
 */

#ifndef MEDIA_H
#define MEDIA_H

#include <string>

using namespace std;

class Media {
public:
  // destructor
  virtual ~Media() = default;

  // add to stock
  virtual bool addTostock(int stock) = 0;

  // whether it is in stock or not
  virtual bool isInStock() const = 0;

  // check out
  virtual bool checkOut() = 0;

  // return
  virtual bool returnMovie() = 0;

  // borrow
  virtual int getBorrowed() = 0;

  // get remaining stock
  virtual int getRemained() = 0;

private:
  int stock;    // stock
  int borrowed; // how wmany borrowed
};

#endif // MEDIA_H
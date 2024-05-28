/**
 *  media class -  class used to store and manage the stock of a dvd type of a movie
 *
 * @author Amy Vier
 * @date 12 May 2024
 *
 * A movie has at lease one media type (DVD, blue-ray, etc.) with a corrosponding stock
 */

#ifndef DVD_H
#define DVD_H

#include <string>
#include "media.h"

using namespace std;

class DVD : public Media
{
public:
  ~DVD();
  DVD(int stock);
  bool addTostock(int stk);
  bool isInStock() const;
  bool checkOut();
  bool returnMovie();
  int getBorrowed();
  int getRemained();

private:
  int stock;
  int borrowed;
};

#endif // DVD_H
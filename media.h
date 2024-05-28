/**
 *  media class - interface class used to store and manage the stock of a movie type of a movie
 *
 * @author Amy Vier
 * @date 12 May 2024
 *
 * A movie has at lease one media type (DVD, blue-ray, etc.) with a corrosponding stock
 */

#ifndef MEDIA_H
#define MEDIA_H

#include <string>

using namespace std;

class Media
{
public:
  virtual ~Media() = default;
  virtual bool addTostock(int stock) = 0;
  virtual bool isInStock() const = 0;
  virtual bool checkOut() = 0;
  virtual bool returnMovie() = 0;
  virtual int getBorrowed() = 0;
  virtual int getRemained() = 0;

private:
  int stock;
  int borrowed;
};

#endif // MEDIA_H
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
  virtual bool addTostock();
  virtual bool isInStock();
  virtual bool checkOut();
  virtual bool returnMovie();

protected:
  int stock;
};

#endif // MEDIA_H
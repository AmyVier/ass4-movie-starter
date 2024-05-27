/**
 *  movie class - interface class used to store and manage movie data
 *
 * @author Amy Vier
 * @date 12 May 2024
 *
 * A movie has a director, title, release year, and stocks pertaining to their media types.
 * A movie has at lease one media type (DVD, blue-ray, etc.) with a corrosponding stock
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <map>
#include "mediaFactory.h"
#include "media.h"

using namespace std;

class Movie
{
public:
  friend ostream &operator<<(ostream &out, const Movie &movie);

  Movie(char mediaType, int stock, string director, string title,
        int releaseYear);
  virtual bool addTostock(char mediaType, int stock);
  virtual bool isInStock(char mediaType);
  virtual bool checkOut(char mediaType);
  virtual bool returnMovie(char mediaType);
  virtual string getTitle();

protected:
  string director;
  string title;
  int releaseYear;
  map<char, Media *> allStock;
};

#endif // MOVIE_H
/**
 *  movie class - interface class used to store and manage movie data
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 * 
 * A movie can be checked out, returned, printed, have a media added to stock, 
 * be checked whether a media is in stock.
 *
 * A movie has a director, title, release year, and stocks pertaining to their
 * media types. A movie has at lease one media type (DVD, blue-ray, etc.) with a
 * corrosponding stock
 */

#ifndef MOVIE_H
#define MOVIE_H

#include "media.h"
#include "mediaFactory.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Movie {
public:
  // prints out movie title
  friend ostream &operator<<(ostream &out, const Movie &movie);

  // constructor
  Movie(char mediaType, int stock, string director, string title,
        int releaseYear);

  // adds to stock based on what type of media (DVD) that would be added
  virtual bool addTostock(char mediaType, int stock);

  // checks if the media (DVD) is in stock
  virtual bool isInStock(char mediaType);

  // checks out a movie based on what media is avaliable
  virtual bool checkOut(char mediaType);

  // returns movie of a media type
  virtual bool returnMovie(char mediaType);

  // get actor
  virtual string getActor();

  // get title
  virtual string getTitle();

  // get year
  virtual int getYear();

protected:
  string director; 
  string title;
  string actor;
  int releaseYear;
  int releaseMonth;
  map<char, Media *> allStock; 
};

#endif // MOVIE_H

/**
 *  classics class - class used to store and manage comedy movie data
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 *  A classical movie can be checked out, returned, printed, have a media added
 * to stock, be checked whether a media is in stock. It is also sorted by
 * Release date, then Major actor.
 *
 * A classics movie has a director, title, major actor, release month, release
 * year, and stocks pertaining to their media types. A classics movie has at
 * lease one media type (DVD, blue-ray, etc.) with a corrosponding stock
 */

#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"
#include <string>

using namespace std;

class Classics : public Movie {
public:
  // constructor
  Classics(char mediaType, int stock, string director, string title,
           string majorActor, int releaseYear, int releaseMonth)
      : Movie(mediaType, stock, director, title, releaseYear) {
    this->majorActor = majorActor;
    this->releaseMonth = releaseMonth;
  };

  // sorted by Release date, then Major actor.
  bool operator<(const Classics &) const;
  bool operator>(const Classics &) const;
  bool operator==(const Classics &) const;

private:
  string majorActor;
  int releaseMonth;
};

#endif // CLASSICS_H
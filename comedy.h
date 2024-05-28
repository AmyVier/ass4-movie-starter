/**
 *  comedy class - class used to store and manage comedy movie data
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 *  A comedy movie can be checked out, returned, printed, have a media
 * added to stock, be checked whether a media is in stock. It is also sorted by
 * Title, then Year it released .
 *
 * A comedy movie has a director, title, release year, and stocks pertaining to
 * their media types. A comedy movie has at lease one media type (DVD, blue-ray,
 * etc.) with a corrosponding stock
 */

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include <string>

using namespace std;

class Comedy : public Movie {
public:
  Comedy(char mediaType, int stock, string director, string title,
         int releaseYear)
      : Movie(mediaType, stock, director, title, releaseYear){};

  // sorted by Title, then Year it released
  bool operator<(const Comedy &) const;
  bool operator>(const Comedy &) const;
  bool operator==(const Comedy &) const;
};

#endif // COMEDY_H
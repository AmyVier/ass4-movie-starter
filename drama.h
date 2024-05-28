/**
 *  drama class - class used to store and manage drama movie data
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 *  A drama movie can be checked out, returned, printed, have a media
 * added to stock, be checked whether a media is in stock. It is also sorted by
 * Director, then Title.
 *
 * A drama movie has a director, title, release
 * year, and stocks pertaining to their media types. A drama movie has at
 * lease one media type (DVD, blue-ray, etc.) with a corrosponding stock
 */

#ifndef DRAMA_H
#define DRAMA_H

#include "dvd.h"
#include "media.h"
#include "movie.h"
#include <map>
#include <string>

using namespace std;

class Drama : public Movie {
public:
  // constructor
  Drama(char mediaType, int stock, string director, string title,
        int releaseYear)
      : Movie(mediaType, stock, director, title, releaseYear){};

  // sorted by Director, then Title
  bool operator<(const Drama &) const;
  bool operator>(const Drama &) const;
  bool operator==(const Drama &) const;
};

#endif
/**
 *  classics class - class used to store and manage comedy movie data
 *
 * @author Amy Vier
 * @date 12 May 2024
 *
 * A classics movie has a director, title, major actor, release month, release year,
 * and stocks pertaining to their media types.
 * A classics movie has at lease one media type (DVD, blue-ray, etc.) with a corrosponding stock
 */

#ifndef CLASSICS_H
#define CLASSICS_H

#include <string>
#include "movie.h"

using namespace std;

class Classics : public Movie
{
public:
  Classics(char mediaType, int stock, string director, string title,
           string majorActor, int releaseYear, int releaseMonth) : Movie(mediaType, stock, director, title, releaseYear)
  {
    this->majorActor = majorActor;
    this->releaseMonth = releaseMonth;
  };

  bool operator<(const Classics &) const;
  bool operator>(const Classics &) const;
  bool operator==(const Classics &) const;

private:
  string majorActor;
  int releaseMonth;
};

#endif // CLASSICS_H
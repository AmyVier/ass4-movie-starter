/**
 *  comedy class - class used to store and manage comedy movie data
 *
 * @author Amy Vier
 * @date 12 May 2024
 *
 * A comedy movie has a director, title, release year, and stocks pertaining to their media types.
 * A comedy movie has at lease one media type (DVD, blue-ray, etc.) with a corrosponding stock
 */

#ifndef COMEDY_H
#define COMEDY_H

#include <string>
#include "movie.h"

using namespace std;

class Comedy : public Movie
{
public:
  Comedy(char mediaType, int stock, string director, string title,
         int releaseYear);
};

#endif // COMEDY_H
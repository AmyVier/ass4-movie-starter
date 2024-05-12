/**
 *  MovieFactory class - class used to create movies
 *
 * @author Amy Vier
 * @date 12 May 2024
 *
 * A movie has a director, title, release year, and stocks pertaining to their media types.
 * A movie has at lease one media type (DVD, blue-ray, etc.) with a corrosponding stock
 */

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <string>
#include "comedy.h"
#include "classics.h"
#include "drama.h"

using namespace std;

class MovieFactory
{
public:
  void createComedy(char mediaType, int stock, string director, string title,
                    int releaseYear);
  void createDrama(char mediaType, int stock, string director, string title,
                   int releaseYear);
  void createClassics(char mediaType, int stock, string director, string title,
                      string majorActor, int releaseYear, int releaseMonth);
};

#endif // MOVIEFACTORY_H
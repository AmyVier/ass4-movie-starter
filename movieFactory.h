/**
 *  MovieFactory class - class used to create movies
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 * creates movies
 *
 * A movie has a director, title, release year, and stocks pertaining to their
 * media types. A movie has at lease one media type (DVD, blue-ray, etc.) with a
 * corrosponding stock
 */

#include "classics.h"
#include "comedy.h"
#include "drama.h"
#include <string>

using namespace std;

class MovieFactory {
public:
  // create comedy
  static Movie createComedy(char mediaType, int stock, string director,
                            string title, int releaseYear) {
    return Comedy(mediaType, stock, director, title, releaseYear);
  }

  // create drama
  static Movie createDrama(char mediaType, int stock, string director,
                           string title, int releaseYear) {
    return Drama(mediaType, stock, director, title, releaseYear);
  }

  // create classic
  static Movie createClassics(char mediaType, int stock, string director,
                              string title, string majorActor, int releaseYear,
                              int releaseMonth) {
    return Classics(mediaType, stock, director, title, majorActor, releaseYear,
                    releaseMonth);
  }
};
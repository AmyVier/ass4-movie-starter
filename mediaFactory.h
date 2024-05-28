/**
 *  MediaFactory class - class used to create movies
 *
 * @author Amy Vier, Chris Chen, Hoan Nguyen Cong Pham, Kyle Ricks
 * @date 27 May 2024
 *
 * creates media
 *
 * A movie has a director, title, release year, and stocks pertaining to their
 * media types. A movie has at lease one media type (DVD, blue-ray, etc.) with a
 * corrosponding stock
 */

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "dvd.h"
#include <iostream>
#include <string>

using namespace std;

class MediaFactory {
public:
  // create DVD
  static DVD *createDVD(int stock) {
    DVD *dvd = new DVD(stock);
    return dvd;
  }
};

#endif // MOVIEFACTORY_H
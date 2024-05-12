/**
 *  MediaFactory class - class used to create movies
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
#include "dvd.h"

using namespace std;

class MovieFactory
{
public:
  void createDVD(int stock);
};

#endif // MOVIEFACTORY_H
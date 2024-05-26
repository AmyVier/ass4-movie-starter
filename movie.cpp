#include "movie.h"
#include <string>

using namespace std;

Movie::Movie(char mediaType, int stock, string director, string title,
             int releaseYear)
{
  this->director = director;
  this->title = title;
  this->releaseYear = releaseYear;

  if (allStock.count(mediaType))
  {
    allStock[mediaType].addTostock(stock);
  }
  else if (mediaType == 'D')
  {
    DVD newDVD = mediaFactory.createDVD(stock);
    allStock.insert(make_pair(mediaType, newDVD));
  }
}

bool Movie::addTostock(char mediaType, int stock)
{
  if (allStock.count(mediaType))
  {
    allStock[mediaType].addTostock(stock);
  }
}

bool Movie::isInStock(char mediaType)
{
  if (allStock.count(mediaType) && allStock[mediaType].isInStock())
  {
    return true;
  }

  return false;
}

bool Movie::checkOut(char mediaType)
{
  if (allStock.count(mediaType) && allStock[mediaType].isInStock())
  {
    allStock[mediaType].checkOut();
    return true;
  }

  return false;
}

bool Movie::returnMovie(char mediaType)
{
  if (allStock.count(mediaType))
  {
    allStock[mediaType].returnMovie();
    return true;
  }

  return false;
}
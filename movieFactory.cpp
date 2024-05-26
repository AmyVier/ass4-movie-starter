#include "movieFactory.h"

#include <string>

using namespace std;

Comedy MovieFactory::createComedy(char mediaType, int stock, string director, string title,
                                  int releaseYear)
{
  return Comedy(mediaType, stock, director, title, releaseYear);
}

Drama MovieFactory::createDrama(char mediaType, int stock, string director, string title,
                                int releaseYear)
{
  return Drama(mediaType, stock, director, title, releaseYear);
}

Classics MovieFactory::createClassics(char mediaType, int stock, string director, string title,
                                      string majorActor, int releaseYear, int releaseMonth)
{
  return Classics(mediaType, stock, director, title, majorActor, releaseYear, releaseMonth);
}
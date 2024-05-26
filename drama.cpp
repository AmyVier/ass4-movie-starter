#include "drama.h"
#include <string>

using namespace std;

bool Drama::operator<(const Drama &other) const
{
  if (this->director < other.director)
  {
    return true;
  }
  else if ((this->director == other.director) && (this->title < other.title))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Drama::operator>(const Drama &other) const
{
  if (this->director < other.director)
  {
    return true;
  }
  else if ((this->director == other.director) && (this->title > other.title))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Drama::operator==(const Drama &other) const
{
  if ((this->director == other.director) && (this->title > other.title))
  {
    return true;
  }
  else
  {
    return false;
  }
}
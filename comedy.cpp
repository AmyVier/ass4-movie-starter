#include "comedy.h"
#include <iostream>
#include <string>

using namespace std;

bool Comedy::operator<(const Comedy &other) const
{
  if (this->title < other.title)
  {
    return true;
  }
  else if ((this->title == other.title) && (this->releaseYear < other.releaseYear))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Comedy::operator>(const Comedy &other) const
{
  if (this->title > other.title)
  {
    return true;
  }
  else if ((this->title == other.title) && (this->releaseYear > other.releaseYear))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Comedy::operator==(const Comedy &other) const
{
  if ((this->title == other.title) && (this->releaseYear == other.releaseYear))
  {
    return true;
  }
  else
  {
    return false;
  }
}